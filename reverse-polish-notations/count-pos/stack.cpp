#include "Stack.h"
#include "iostream"

Stack::Stack() {
    this->top = nullptr;
}

Stack::Stack(Elem *top) {
    this->top = top;
}

void Stack::push(std::string chr) {
//    if (!this->top)
//    {
//        this->top = elem;
//        elem->next = nullptr;
//    }
//    else
//    {
//        elem->next = this->top;
//        this->top = elem;
//    }
    if (!this->top)
    {
        this->top = new Elem(chr);
        this->top->next = nullptr;
    }
    else
    {
        Elem *temp = new Elem(chr);
        temp->next = this->top;
        this->top = temp;
    }
}

void Stack::pop() {
    if (this->top)
    {
        Elem* temp = this->top;
        this->top = this->top->next;
        delete temp;
    }
}

void Stack::printStack() {
    Elem* temp = this->top;
    while (temp->next != nullptr)
    {
        std::cout << temp->chr;
        temp = temp->next;
    }
    std::cout << temp->chr << "\n";
}

bool Stack::isEmpty() {
    if (!this->top)
        return true;
    return false;
}

std::string Stack::peek() {
    if (this->top)
        return this->top->chr;
    return "";
}

Stack::~Stack() {
    Elem* temp = this->top;
    Elem* toDel = this->top;
    this->top = nullptr;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        delete toDel;
        toDel = temp;
    }
    delete temp;
}
