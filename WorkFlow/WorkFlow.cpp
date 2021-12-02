#include <iostream>
#include "WorkFlowExecutor.h"

int main()
{
    try 
    {
        WorkFlowExecutor a;
        a.execute("./Tests/CommonTest.txt");
    }
    catch (std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}