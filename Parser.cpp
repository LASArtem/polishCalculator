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

    // looks like a constant for the whole class
    const char space= ' ';
    std::string word = "";
    const char* firstCharPtr = line.c_str();

    for ( int i = 0; i < line.size(); ++i )
    {
        // not clear for me. May be make sence to write if(char == space) and  continue??
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

    // i bet there is the way to rewrite loop in a way to remove this duplication.
    if (!word.empty())
    {
        stack.push(word);
    }
}

} //namespace dev
