#include <iostream>
#include <string>

#include "Calculator.hpp"
#include "Math.hpp"
#include "Parser.hpp"

namespace dev
{

//-----------------------------------------------------------------------------
Calculator::Calculator()
    : mMath(std::make_shared<dev::Math>())
    , mParser(std::make_shared<dev::Parser>())
    , mStack()
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
Calculator::~Calculator()
//-----------------------------------------------------------------------------
{
    clearStack();
}

/* TODO:
 *  rename: setData
 */
//-----------------------------------------------------------------------------
void Calculator::setStack(const std::string inputLine)
//-----------------------------------------------------------------------------
{
    clearStack();
    mParser->parseStringToStringStack(inputLine, mStack);
}

//-----------------------------------------------------------------------------
void Calculator::printStack() const
//-----------------------------------------------------------------------------
{
    std::cout << "printStack: size = " << getStackSize() << std::endl;

    int i = 0;

    for (std::stack<std::string> temp = mStack; !temp.empty(); temp.pop(), ++i)
    {
        std::cout << "printStack: " <<  i << ") " << temp.top() << std::endl;
    }
}

//-----------------------------------------------------------------------------
int Calculator::getStackSize() const
//-----------------------------------------------------------------------------
{
    return static_cast<int>(mStack.size());
}

//-----------------------------------------------------------------------------
const std::string& Calculator::getStackTop() const
//-----------------------------------------------------------------------------
{
    return mStack.top();
}
/* TODO:
 *  rename: calculateData
 *  add: work with negative numbers
 *  add: work with double numbers
 *  make: recursive calculation
 */
//-----------------------------------------------------------------------------
void Calculator::processStackTop()
//-----------------------------------------------------------------------------
{
    const int processingMinStackSize = 3;
    if (getStackSize() < processingMinStackSize)
    {
        std::cout << "ERROR: processStackTop: small size: " << getStackSize() << std::endl;
        return;
    }

    bool success = false;
    std::string result = "";
    std::string sign = mStack.top();
    mStack.pop();
    std::string b = mStack.top();
    mStack.pop();
    std::string a = mStack.top();
    mStack.pop();

    switch(strToSign(sign))
    {
        case eSigns::PLUS:
            success = mMath->sum(result, a, b);
            break;

        case eSigns::MINUS:
            success = mMath->diff(result, a, b);
            break;

        case eSigns::MULTIPLICATION:
            success = mMath->multiplication(result, a, b);
            break;

        case eSigns::DIVISION:
            success = mMath->division(result, a, b);
            break;

        default:
            success = false;
            break;
    }

    //std::cout << "processStackTop: success = " << success << std::endl;

    if (success)
    {
        //std::cout << "processStackTop: mStack.push(result) = " << result << std::endl;
        mStack.push(result);
    }
    else
    {
        std::cout << "WARN: processStackTop: mStack was returned back" << std::endl;
        mStack.push(a);
        mStack.push(b);
        mStack.push(sign);
        printStack();
    }
}

//-----------------------------------------------------------------------------
void Calculator::clearStack()
//-----------------------------------------------------------------------------
{
    while (!mStack.empty())
    {
        mStack.pop();
    }
}

//-----------------------------------------------------------------------------
Calculator::eSigns Calculator::strToSign(const std::string str) const
//-----------------------------------------------------------------------------
{
    if ("+" == str)
    {
        return eSigns::PLUS;
    }

    if ("-" == str)
    {
        return eSigns::MINUS;
    }

    if ("*" == str)
    {
        return eSigns::MULTIPLICATION;
    }

    if ("/" == str)
    {
        return eSigns::DIVISION;
    }

    return eSigns::NONE;
}

}//dev end
