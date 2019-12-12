#pragma once

#include <stack>
#include <memory>

namespace dev
{

class string;
class Math;
class Parser;

class Calculator
{
public:
    Calculator();
    ~Calculator();

    void setStack(const std::string inputLine);
    void printStack() const;
    int getStackSize() const;

    const std::string& getStackTop() const;
    void processStackTop();

private:
    enum class eSigns: int { PLUS, MINUS, MULTIPLICATION, DIVISION, NONE};

    std::shared_ptr<dev::Math> mMath;
    std::shared_ptr<dev::Parser> mParser;
    std::stack<std::string> mStack;

    void clearStack();
    eSigns strToSign(const std::string str) const;

};

}//dev end
