#include <iostream> //cout
#include <unistd.h> //fork
#include <fcntl.h>  //file open
#include <string.h>



int main()
{   
    int fork_id;
    
    fork_id = fork();

    char *args[] = {"/bin/ls",NULL};
    char *envp[] = {NULL};

    execvp(args[0],args);
    //execvpe(args[0], args, args);
    //execv(args[0],args);
    //exec(args[0],args,envp);
    //execlp(args[0],"", (char *) NULL);
    //execl(args[0], "", NULL);
    return 0;
}
