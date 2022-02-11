#include <iostream> //cout
#include <unistd.h> //fork


int main()
{   
    int x = 100;
    std::cout << "x = " << x << "...calling fork()...\n";
    int id = fork(); //child process born and starts executing same lines
    
    if (id != 0)
    {
        std::cout << "hello! from parent with ID: " << id << " x = " << x << std::endl;
        std::cout << "parent changing x from " << x << " to 50..." << std::endl;
        x = 50;
        std::cout << "parent x is now " << x << std::endl << std::endl;
    }
    else
    {
        std::cout << "hello! from child with ID: " << id << " x = " << x << std::endl;
        std::cout << "child changing x from " << x << " to 75..." << std::endl;
        x = 75;
        std::cout << "child x is now " << x << std::endl << std::endl;

    }
    
    
    return 0;
}
