#include <iostream> //cout
#include <unistd.h> //fork
#include <fcntl.h>  //file open
#include <string.h>

//How do you want this presented???/// Only one exec seems to work at a time

int main()
{   
    int fork_id;
    
    fork_id = fork(); //can do all execs if have each child do one exec therefore 1 fork per exec and only do exec if you're child

    char *args[] = {"/bin/ls",NULL};
    char *envp[] = {NULL};

    int exec_error = execvp(args[0],args);
    if (exec_error != 0)
    {
        /* code */
    }
    
    execvpe(args[0], args, args);
    //execv(args[0],args);
    //exec(args[0],args,envp);
    //execlp(args[0],"", (char *) NULL);
    //execl(args[0], "", NULL);
    return 0;
}
