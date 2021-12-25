#include <iostream>
#include <string>
#include "Stack.h"

bool isOp(char op) {
    if (op == 'N' || op == 'K' || op == 'A')
        return true;
    return false;
}

void countPost(std::string exp)
{
    bool ans;
    Stack stack;
    for (int i = 0; i < exp.length(); i++)
    {
        if (!isOp(exp[i]))
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
                bool valueTemp;
                if (temp == "t")
                    valueTemp = true;
                else
                    valueTemp = false;
                ans = !valueTemp;
                if (ans)
                    stack.push("t");
                else
                    stack.push("f");
            }
            else
            {
                std::string temp = stack.peek();
                stack.pop();
                std::string temp2 = stack.peek();
                stack.pop();
                bool valueTemp, valueTemp2;
                if (temp == "t")
                    valueTemp = true;
                else
                    valueTemp = false;
                if (temp2 == "t")
                    valueTemp2 = true;
                else
                    valueTemp2 = false;
                if (exp[i] == 'K')
                    ans = valueTemp2&&valueTemp;
                else if(exp[i] == 'A')
                    ans = valueTemp2||valueTemp;
                if (ans)
                    stack.push("t");
                else
                    stack.push("f");
            }
        }
    }
    std::cout << stack.peek() << std::endl;
}

int main() {
    int a;
    std::string exp;
    std::cin >> a;
    for (int i = 0; i < a; i++)
    {
        std::cin >> exp;
        countPost(exp);
    }
}