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
    clearStack();
    mParser->parseStringToStringStack(task, mStack);
    // i believe, it is not obvious that processStackTop will modify mResult.
    processStackTop();
    return getLastResult();
}

//-----------------------------------------------------------------------------
const Result& Calculator::getLastResult()
//-----------------------------------------------------------------------------
{
    return mResult;
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
        // So we pop at the very beginning and now, if something went wrong, we push back all, we had before?
        // Not the best solution as for me...
        std::cout << "WARN: processStackTop: mStack was returned back" << std::endl;
        mStack.push(a);
        mStack.push(b);
        mStack.push(sign);
    }
}

//-----------------------------------------------------------------------------
Calculator::eSigns Calculator::strToSign(const std::string str) const
//-----------------------------------------------------------------------------
{
    // How about switch?
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
