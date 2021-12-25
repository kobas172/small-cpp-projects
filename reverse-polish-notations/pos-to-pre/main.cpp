#include <iostream>
#include <string>
#include "Stack.h"

bool isOp(char op) {
    if (op == 'N' || op == 'K' || op == 'A')
        return true;
    return false;
}

std::string postToPre (std::string exp)
{
    Stack stack;
    std::string answer;
    for (int i = 0; i < exp.length(); i++)
    {
        if(!isOp(exp[i]))
        {
            std::string temp;
            temp.push_back(exp[i]);
            stack.push(temp);
        }
        else
        {
            if(exp[i] != 'N')
            {
                std::string temp = stack.peek();
                stack.pop();
                std::string temp2 = stack.peek();
                stack.pop();
                std::string ans = exp[i] + temp2 + temp;
                stack.push(ans);
            }
            else
            {
                std::string temp = stack.peek();
                stack.pop();
                std::string ans = exp[i] + temp;
                stack.push(ans);
            }
        }
    }
    return stack.peek();
}

int main() {
    int a;
    std::string exp;
    std::cin >> a;
    for (int i = 0; i < a; i++)
    {
        std::cin >> exp;
        exp = postToPre(exp);
        std::cout << exp << std::endl;
    }
}