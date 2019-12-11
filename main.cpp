#include <iostream>

#include "Calculator.hpp"

int main()
{
    dev::Calculator app;
    std::string example = "";

    example= "12 3 +";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << "\n" << std::endl;

    example= "12 3 -";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << "\n" << std::endl;

    example= "12 3 *";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << "\n" << std::endl;

    example= "12 3 /";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << "\n" << std::endl;

    example= "+ + +";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << "\n" << std::endl;

    example= "22 33 +";
    app.setStack(example);
    app.processStackTop();
    std::cout << "main: setStack: " << example << " = " << app.getStackTop() << "\n" << std::endl;

    return 0;
}
