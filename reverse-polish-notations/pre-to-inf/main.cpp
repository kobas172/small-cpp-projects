#include <iostream>
#include <string>
#include "Stack.h"

bool isOp(char op) {
    if (op == 'N' || op == 'K' || op == 'A')
        return true;
    return false;
}

std::string preToInf(std::string exp)
{
    Stack stack;
    std::string ans;
    for (int i = exp.size() - 1; i >= 0; i--)
    {
        if(!isOp(exp[i]))
        {
            std::string temp;
            temp.push_back(exp[i]);
            stack.push(temp);
        }
        else
        {
            if (exp[i] == 'N')
            {
                std::string temp = stack.peek();
                stack.pop();
                std::string op;
                op.push_back(exp[i]);
                ans = "(" +  op + temp + ")";
            }
            else
            {
                std::string temp = stack.peek();
                stack.pop();
                std::string temp2 = stack.peek();
                stack.pop();
                std::string op;
                op.push_back(exp[i]);
                ans = "(" + temp + op + temp2 + ")";
            }
            stack.push(ans);
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
        exp = preToInf(exp);
        std::cout << exp << std::endl;
    }
}