#include <stack>
#include <string>

#include "Parser.hpp"

namespace dev
{
//-----------------------------------------------------------------------------
Parser::Parser()
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
Parser::~Parser()
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
void Parser::parseStringToStringStack(const std::string line, std::stack<std::string>& stack) const
//-----------------------------------------------------------------------------
{
    /* TODO:
     *  simplify: make separate function for take single world
     *  add: while !str.empty() save world to stack
     */
    const char space= ' ';
    std::string word = "";
    const char* firstCharPtr = line.c_str();

    for ( size_t i = 0; i < line.size(); ++i )
    {
        if (space != firstCharPtr[i])
        {
            word += firstCharPtr[i];
        }
        else
        {
            if (!word.empty())
            {
                stack.push(word);
                word.clear();
            }
        }
    }

    if (!word.empty())
    {
        stack.push(word);
    }
}

} //namespace dev
