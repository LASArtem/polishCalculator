#pragma once

#include <stack>
#include <memory>

namespace dev
{
struct Result
{
    bool isValid;
    std::string answer;
};

class string;
class Math;
class Parser;

class Calculator
{
public:
    Calculator();
    ~Calculator();

    const Result& resolve(const std::string& task);
    const Result& getLastResult();

private:
    enum class eSigns: int { PLUS, MINUS, MULTIPLICATION, DIVISION, NONE};

    std::shared_ptr<dev::Math> mMath;
    std::shared_ptr<dev::Parser> mParser;

    std::stack<std::string> mStack;
    Result mResult;

    void clearStack();
    void processStackTop();
    Calculator::eSigns strToSign(const std::string str) const;
    std::string stackTopPop();
};

}//dev end
