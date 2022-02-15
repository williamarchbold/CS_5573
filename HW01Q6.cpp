#include <iostream> //cout
#include <unistd.h> //fork
#include <fcntl.h>  //file open
#include <string.h>
#include <sys/wait.h> //wait 

int main()
{   
    int file_descriptor01, fork_id, close_value;
    
    
    fork_id = fork();

    wait(NULL);

    if (fork_id == 0)
    {   
        std::cout <<"in child process\n";
        fflush(stdout); //ensures any local file * buffer chars are written to actual file either console or redirected file. fflush goes through library
        close_value = close(STDOUT_FILENO); //stdout byte stream opened by parent (usually shell) "deassociate this process file file handler #1". this close is lower level goes to operating system
        //close_value = close(file_descriptor01);
        int error = printf("hello \n"); //
        fprintf(stderr, "Reached error: %d Close value: %d\n", error);
    }
    else
    {
        printf("hello from parent with id: %d\n", getpid()); //here, fork_id is id of child
        //write(file_descriptor01, "hello from parent\n", strlen("hello from parent\n"));
    }

    //close(file_descriptor01);
    
    return 0;
}
