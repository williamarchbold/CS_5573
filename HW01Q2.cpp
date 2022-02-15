#include <iostream> //cout
#include <unistd.h> //fork
#include <fcntl.h>  //file open
#include <string.h>


int main()
{   
    int file_descriptor01, file_descriptor02, fork_id, parent_write, child_write;
    file_descriptor01 = open("HW01Q2.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
    if (file_descriptor01 < 0)
    {
        std::cout << "error opening file from parent"<< std::endl;
        exit(1);
    }
    else
    {
        std::cout << "parent opened file with file descriptor: " << file_descriptor01 << std::endl;
    }
    
    std::cout << "calling fork..." << std::endl;
    
    fork_id = fork();

    if (fork_id == 0)
    {   
        file_descriptor01 = open("HW01Q2.txt", O_RDWR);
        if (file_descriptor01 < 0)
        {
            std::cout << "error opening file from child"<< std::endl;
            exit(1);
        }
        else
        {
            std::cout << "child opened file with file descriptor: " << file_descriptor01 << std::endl;
        }
        
        child_write = write(file_descriptor01, "hello from child\n", strlen("hello from child\n"));


    }
    else
    {
        std::cout << "parent id: " << fork_id << std::endl;
        parent_write = write(file_descriptor01, "hello from parent\n", strlen("hello from parent\n"));
    }

    close(file_descriptor01);
    close(file_descriptor02);

    
    return 0;
}
