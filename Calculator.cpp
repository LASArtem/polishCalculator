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
    , mResult()
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
Calculator::~Calculator()
//-----------------------------------------------------------------------------
{
    clearStack();
}

//-----------------------------------------------------------------------------
const Result& Calculator::resolve(const std::string& task)
//-----------------------------------------------------------------------------
{
    mResult.isValid = false;
    clearStack();

    mParser->parseStringToStringStack(task, mStack);

    processStackTop();

    return getLastResult();
}

//-----------------------------------------------------------------------------
const Result& Calculator::getLastResult()
//-----------------------------------------------------------------------------
{
    return mResult;
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
    std::string sign = stackTopPop();
    std::string b = stackTopPop();
    std::string a = stackTopPop();

    switch(strToSign(sign))
    {
        case eSigns::PLUS:
            mResult.isValid = mMath->sum(mResult.answer, a, b);
            break;

        case eSigns::MINUS:
            mResult.isValid = mMath->diff(mResult.answer, a, b);
            break;

        case eSigns::MULTIPLICATION:
            mResult.isValid = mMath->multiplication(mResult.answer, a, b);
            break;

        case eSigns::DIVISION:
            mResult.isValid = mMath->division(mResult.answer, a, b);
            break;

        default:
            mResult.isValid = false;
            break;
    }

    if (mResult.isValid)
    {
        mStack.push(mResult.answer);
    }
    else
    {
        std::cout << "WARN: processStackTop: mStack was returned back" << std::endl;
        mStack.push(a);
        mStack.push(b);
        mStack.push(sign);
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
std::string Calculator::stackTopPop()
//-----------------------------------------------------------------------------
{
    std::string temp = "";

    if (!mStack.empty())
    {
        temp = mStack.top();
        mStack.pop();
    }

    return temp;
}

}//dev end
