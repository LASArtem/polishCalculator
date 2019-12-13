#include <iostream>

#include "Calculator.hpp"

int main()
{
    dev::Calculator app;
    dev::Result result;
    std::string example = "";

    example= "12 3 +";
    result = app.resolve(example);
    std::cout << "main: app.resolve: " << example << " = " << (result.isValid ? result.answer : "ERROR of resolving") << "\n" << std::endl;

    example= "12 3 -";
    result = app.resolve(example);
    std::cout << "main: app.resolve: " << example << " = " << (result.isValid ? result.answer : "ERROR of resolving") << "\n" << std::endl;

    example= "12 3 *";
    result = app.resolve(example);
    std::cout << "main: app.resolve: " << example << " = " << (result.isValid ? result.answer : "ERROR of resolving") << "\n" << std::endl;

    example= "12 3 /";
    result = app.resolve(example);
    std::cout << "main: app.resolve: " << example << " = " << (result.isValid ? result.answer : "ERROR of resolving") << "\n" << std::endl;

    example= "+ + +";
    result = app.resolve(example);
    std::cout << "main: app.resolve: " << example << " = " << (result.isValid ? result.answer : "ERROR of resolving") << "\n" << std::endl;

    example= "22 33 +";
    result = app.resolve(example);
    std::cout << "main: app.resolve: " << example << " = " << (result.isValid ? result.answer : "ERROR of resolving") << "\n" << std::endl;

    return 0;
}
