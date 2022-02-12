#include <iostream> //cout
#include <unistd.h> //fork
#include <fcntl.h>  //file open
#include <string.h>
#include <sys/wait.h> //wait 

int main()
{   
    int file_descriptor01, fork_id, close_value;
    file_descriptor01 = open("HW01Q6.txt", O_CREAT | O_TRUNC | O_WRONLY);
    if (file_descriptor01 < 0)
    {
        std::cout << "error opening file"<< std::endl;
        exit(1);
    }
    else
    {
        std::cout << "parent opened file with file descriptor: " << file_descriptor01 << std::endl;
    }
    
    std::cout << "calling fork..." << std::endl;
    
    fork_id = fork();

    wait(NULL);

    if (fork_id == 0)
    {   
        std::cout <<"in child process\n";
        close_value = close(STDOUT_FILENO);
        //close_value = close(file_descriptor01);
        std::cout << "close value: " << close_value << std::endl;
    }
    else
    {
        std::cout << "parent id: " << fork_id << std::endl;
        //write(file_descriptor01, "hello from parent\n", strlen("hello from parent\n"));
    }

    //close(file_descriptor01);
    
    return 0;
}
