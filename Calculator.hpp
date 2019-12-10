#pragma once

#include <stack>
#include <string>

namespace dev
{

class Calculator
{
public:
    Calculator();
    ~Calculator();

    void setStack(std::string inputLine);
    void printStack() const;
    int getStackSize() const;

    const std::string& getStackTop() const;
    void processStackTop();

private:
    enum class eSigns: int { PLUS, MINUS, MULTIPLICATION, DIVISION, NONE};

    std::stack<std::string> mStack;

    void clearStack();
    eSigns strToSing(const std::string str) const;
    bool sum(std::string& result, const std::string a, const std::string b);
    bool diff(std::string& result, const std::string a, const std::string b);
    bool multiplication(std::string& result, const std::string a, const std::string b);
    bool division(std::string& result, const std::string a, const std::string b);

};

}//dev end
