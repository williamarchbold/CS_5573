#include <iostream> //cout
#include <unistd.h> //fork
#include <sys/wait.h> //wait

int main()
{   
    int x, id, wait_value;

    x = 100;
    std::cout << "x = " << x << "\n...calling fork()...\n\n";

    id = fork(); //child process born and starts executing same lines

    waitpid(id, &wait_value,0);
    
    if (id != 0)
    {
        x = 50;
    }
    else
    {
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
    
    std::cout << "wait value: " << wait_value << "\n\n";
    
    
    return 0;
}
