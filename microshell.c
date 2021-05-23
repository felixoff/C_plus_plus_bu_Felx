#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define STDIN  0
#define STDOUT 1
#define STDERR 2
#define PIPE 4
#define BREAK 5
#define END 3

typedef struct s_base {
    char **argv;
    int type;
    int fd[2];
    int size;
    struct s_base *next;
    struct s_base *prev;
} t_base;

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return(i);
}

char *ft_strdup(char *old)
{
    char *new;
    int size;

    size = ft_strlen(old);
    if (!old)
        return(NULL);
    if(!(new=malloc(sizeof(char)*size+1)))
        return(NULL);
    new[size] = '\0';
    while (--size >= 0)
        new[size] = old[size];
    return(new);
}

void exit_fatal()
{
    char *msg;
    msg = "exit_fatal";
    write(STDERR,msg,ft_strlen(msg));
    exit(EXIT_FAILURE);
}

void exit_execve(char *str)
{
    char *msg;
    msg = "exit_cannot_execute";
    write(STDERR,msg,ft_strlen(msg));
    write(STDERR,str,ft_strlen(str));
    write(STDERR,"\n",1);
    exit(EXIT_FAILURE);
}

void exit_cd1()
{
    char *msg;
    msg = "cd_bad_arg";
    write(STDERR,msg,ft_strlen(msg));
    exit(EXIT_FAILURE);
}

void exit_cd2(char *str)
{
    char *msg;
    msg = "cannot change dir";
    write(STDERR,msg,ft_strlen(msg));
    write(STDERR,str,ft_strlen(str));
    write(STDERR,"\n",1);
    exit(EXIT_FAILURE);
}

void lst_add_back(t_base **base, t_base *new)
{
    t_base *tmp;
    if (!(*base))
        *base = new;
    else
    {
        tmp = *base;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
}

int size_argv(char **argv)
{
    int i = 0;
    while (argv[i] && strcmp(argv[i],'|') != 0 && strcmp(argv[i],';') != 0)
        i++;
    return (i);
}

int check_end(char *av)
{
    if (!av)
        return (END);
    if (strcmp(av,'|')== 0)
        return(PIPE);
    if (strcmp(av,';')== 0)
        return(BREAK);
    return(0);
}

int parse(t_base **base, char **argv)
{
    int size = size_argv(argv);
    t_base *new;
    if(!(new=malloc(sizeof(t_base)*size)))
        return(NULL);
    if(!(new->argv=malloc(sizeof(char *)*size+1)))
        return(NULL);
    new->size = size;
    new->next = NULL;
    new->prev = NULL;
    new->argv[size] = NULL;
    while (--size >= 0)
        new->argv[size] = ft_strdup(argv[size]);
    new->type = check_end(argv[new->size]);
    lst_add_back(base,new);
    return(new->size);
}

void exec_cmd2(t_base *base, char **env)
{
    pid_t pid;
    int status;
    int pipeopen;

    pipeopen = 0;
    if (base->type == PIPE || (base->prev && base->prev == PIPE))
    {
        pipeopen = 1;
        if(pipe(base->fd))
            exit_fatal();
    }
    if (pid == 0)
    {
        if(base->type == PIPE && dup2(base->fd[1],STDOUT) < 0)
           exit_fatal();
		if(base->prev && base->prev->type== PIPE && dup2(base->prev->fd[0],STDIN) < 0)
		   exit_fatal();
		if ((execve(base->argv[0],base->argv,env))<0)
           exit_execve(base->argv[0]);
		exit(EXIT_SUCCESS);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (pipeopen)
        {
            close(base->fd[1]);
            if(!base->next || base->type == BREAK)
                close(base->fd[0]);
        }
            if (base->prev && base->prev->type == PIPE)
                close(base->prev->fd[0]);
    }
}
void exec_cmd1(t_base *base, char **env)
{
    t_base *tmp;

    tmp = base;
    while(tmp)
    {
        if (strcmp("cd", tmp->argv[0]) == 0)
        {
            if (tmp->size < 2) // || tmp->size > 2
                exit_cd1();
            else if(chdir(tmp->argv[1]))
                exit_cd2(tmp->argv[1]);
        }
        else
            exec_cmd2(tmp,env);
        tmp = tmp->next;
    }
}
void clear_all(t_base *base)
{
    t_base *tmp;
    while (base)
    {
        tmp = base->next;
        int i = 0;
        while (i< base->size)
        {
            free(base->argv[i]);
            i++;
        }
        free(base->argv);
        free(base);
        base = tmp;
    }
    base =NULL;
}

int main(int argc, char **argv, char **env)
{
    t_base *base = NULL;
    int i;
    
    i = 1;
    if (argc > 1)
    {
        while (argv[i])
    {
        if (strcmp(argv[i],';') == 0)
        {
            i++;
            continue;
        }
        i += parse(&base, &argv[i]);
        if (!argv[i])
            break;
        else
            i++;
    }
    if (base)
        exec_cmd1(base,env);
    clear_all(base);
    }
    return(0);
}