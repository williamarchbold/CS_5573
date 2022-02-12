#include <iostream> //cout
#include <unistd.h> //fork
#include <sys/wait.h> //wait

int main()
{   
    int x, id, wait_value;

    x = 100;
    std::cout << "x = " << x << "\n...calling fork()...\n\n";

    id = fork(); //child process born and starts executing same lines


    
    if (id != 0)
    {
        //wait_value = wait(NULL);
        //std::cout << "wait value = " << wait_value << std::endl << std::endl;
        x = 50;
    }
    else
    {
        wait_value = wait(NULL);
        std::cout << "wait value child = " << wait_value << std::endl << std::endl;
        x = 75;
    }

    if (x == 50)
    {
        std::cout << "hello! from parent with ID: " << id << " x = " << x << std::endl;
    }
    else if (x == 75)
    {
        std::cout << "hello! from child with ID: " << id << " x = " << x << std::endl;
    }
    
    std::cout << "\n";
    
    
    return 0;
}
