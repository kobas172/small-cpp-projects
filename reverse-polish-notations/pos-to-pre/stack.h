#include <string>

struct Elem {
    Elem* next;
    std::string chr;

    Elem(std::string chr)
    {
        this->next = nullptr;
        this->chr = chr;
    }
};

class Stack {
    Elem* top;
public:
    Stack();
    Stack(Elem* top);
    void push(std::string chr);
    void pop();
    void printStack();
    bool isEmpty();
    std::string peek();
    ~Stack();
};

