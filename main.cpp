#include <iostream>

#include "Calculator.hpp"

int main()
{
    dev::Calculator app;
    std::string example = "";

    example= "12 3 +";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << std::endl;

    example= "12 3 -";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << std::endl;

    example= "12 3 *";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << std::endl;

    example= "12 3 /";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << std::endl;

    return 0;
}
