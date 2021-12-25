#include <iostream>
#include <string>
#include "Stack.h"

bool isOp(char op) {
    if (op == 'N' || op == 'K' || op == 'A')
        return true;
    return false;
}

std::string infToPost (std::string exp)
{
    Stack stack;
    std::string ans;

    for (int i = 0; i < exp.size(); i++)
    {
        if (!isOp(exp[i]) && exp[i] != '(' && exp[i] != ')')
        {
            ans+=exp[i];
        }
        else if (exp[i] == '(')
        {
            std::string temp;
            temp.push_back(exp[i]);
            stack.push(temp);
        }
        else if (exp[i] == ')')
        {
            while (!stack.isEmpty() && stack.peek() != "(")
            {
                std::string temp;
                temp = stack.peek();
                stack.pop();
                ans += temp;
            }
            stack.pop();
        }
        else if (isOp(exp[i]))
        {
            std::string temp;
            temp.push_back(exp[i]);
            stack.push(temp);

        }
    }
    return ans;
}

int main() {
    int a;
    std::string exp;
    std::cin >> a;
    for (int i = 0; i < a; i++)
    {
        std::cin >> exp;
        exp = infToPost(exp);
        std::cout << exp << std::endl;
    }
}