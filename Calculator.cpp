#include <algorithm>
#include <iostream>


#include "Calculator.hpp"


namespace dev
{

//-----------------------------------------------------------------------------
Calculator::Calculator()
    : mStack()
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
    /* TODO:
     *  simplify: make separate function for take single world
     *  add: while !str.empty() save world to stack
     */
    std::string word = "";
    const char* firstCharPtr = inputLine.c_str();

    for ( int i = 0; i < inputLine.size(); ++i )
    {
        if ( firstCharPtr[i] != 0x20)
        {
            word += firstCharPtr[i];
        }
        else
        {
            mStack.push(word);
            word.clear();
        }
    }

    if (!word.empty())
    {
        mStack.push(word);
    }
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
            success = sum(result, a, b);
            break;

        case eSigns::MINUS:
            success = diff(result, a, b);
            break;

        case eSigns::MULTIPLICATION:
            success = multiplication(result, a, b);
            break;

        case eSigns::DIVISION:
            success = division(result, a, b);
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

//-----------------------------------------------------------------------------
bool Calculator::isNumber(const std::string& str) const
//-----------------------------------------------------------------------------
{
    return ( !str.empty() )
           && ( str.end() == std::find_if(str.begin(), str.end(), [](char c)
                             {
                                return !std::isdigit(c);
                             }));
}

//-----------------------------------------------------------------------------
bool Calculator::sum(std::string& result, const std::string a, const std::string b) const
//-----------------------------------------------------------------------------
{
    const bool isFirstNumber = isNumber(a);
    const bool isSecondNumber = isNumber(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) + std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

//-----------------------------------------------------------------------------
bool Calculator::diff(std::string& result, const std::string a, const std::string b) const
//-----------------------------------------------------------------------------
{
    const bool isFirstNumber = isNumber(a);
    const bool isSecondNumber = isNumber(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) - std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

//-----------------------------------------------------------------------------
bool Calculator::multiplication(std::string& result, const std::string a, const std::string b) const
//-----------------------------------------------------------------------------
{
    const bool isFirstNumber = isNumber(a);
    const bool isSecondNumber = isNumber(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) * std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

//-----------------------------------------------------------------------------
bool Calculator::division(std::string& result, const std::string a, const std::string b) const
//-----------------------------------------------------------------------------
{
    const bool isFirstNumber = isNumber(a);
    const bool isSecondNumber = isNumber(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) / std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

}//dev end
