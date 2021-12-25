#include <stdio.h>


enum { CMD_LENGTH,
    CMD_PRINT,
    CMD_ERROR,
    CMD_ADD_EMPTY,
    CMD_ADD_VALUE,
    CMD_POP_AND_PRINT,
    CMD_DELETE_EMPTY_FIELDS,
} ecmd;

struct Elem {
    int key;
    Elem* next;
    Elem(Elem* e, int k) : next(e), key(k) { }
};

char cmd;
int n;
bool isEmptyQueue;
Elem *first, *last;
Elem *firstQueue, *lastQueue;


int parseEnum(char cmd) {
    return cmd == 'L' ? CMD_LENGTH :
           cmd == 'P' ? CMD_PRINT :
           cmd == 'A' ? CMD_ADD_EMPTY :
           cmd == 'E' ? CMD_ADD_VALUE :
           cmd == 'D' ? CMD_POP_AND_PRINT :
           cmd == 'G' ? CMD_DELETE_EMPTY_FIELDS :
           CMD_ERROR;
}

Elem *search(int key)
{
    if(!first) return NULL;
    Elem *tmp = first;
    while(tmp->key != key && tmp != last) tmp = tmp->next;
    if (tmp->key == key) return tmp;
    else return NULL;
}

void printAll() {
    if(!firstQueue || isEmptyQueue) printf("-\n");
    else {
        Elem *tmp = firstQueue;
        while(tmp != lastQueue) {
            printf("%d->", tmp->key);
            tmp = tmp->next;
        }
        printf("%d\n", lastQueue->key);
    }
}

int totalLength()
{
    if(!first) return 0;
    int len(1);
    Elem *tmp = first;
    while(tmp->next != first) { tmp = tmp->next; len++; }
    return len;
}

void addEmpty()
{
    if (!first)
    {
        Elem *newElem = new Elem(NULL, NULL);
        first = newElem;
        last = newElem;
        newElem->next = first;
    }
    else
    {
        Elem *newElem = new Elem(first, NULL);
        last->next = newElem;
        last = newElem;
    }
}

void addElement(int key)
{
    if (isEmptyQueue)
    {
        if(!first)
        {
            addEmpty();
            first->key = key;
            firstQueue = lastQueue = first;
            isEmptyQueue = false;
        }
        else
        {
            first->key = key;
            firstQueue = lastQueue = first;
            isEmptyQueue = false;
        }
    }
    else
    {
        Elem *tempF = first;
        Elem *tempN = first->next;
        if (lastQueue->next != firstQueue)
        {
            while (tempN != lastQueue)
            {
                tempF = tempN;
                tempN = tempN->next;
            }
            tempF = tempN;
            tempN = tempN->next;
            tempN->key = key;
            lastQueue = tempN;
        }
        else
        {
            Elem *newElem = new Elem(firstQueue, key);
            if (lastQueue == last)
            {
                lastQueue->next = newElem;
                lastQueue = last = newElem;
            }
            else
            {
                lastQueue->next = newElem;
                lastQueue = newElem;
            }
        }
    }
}

void popPrint()
{
    if (isEmptyQueue)
        printf("-\n");
    else
    {
        if (firstQueue == lastQueue)
        {
            printf("%d\n", firstQueue->key);
            isEmptyQueue = true;
            firstQueue = lastQueue = NULL;
        }
        else
        {
            printf("%d\n", firstQueue->key);
            firstQueue = firstQueue->next;
        }

    }
}

void deleteEmpty()
{
    if (first && !isEmptyQueue && firstQueue != lastQueue )
    {
        Elem* tempC = lastQueue;
        Elem* tempN = lastQueue->next;
        while (tempN != firstQueue)
        {
            if (tempN != firstQueue)
            {
                if (tempN == first)
                {
                    first = tempN->next;
                    last->next = first;
                }
                if (tempN == last)
                {
                    last = tempC;
                    last->next = first;
                }
                tempC->next = tempN->next;
                delete tempN;
                tempN = tempC->next;
            }
        }
    }
    if (isEmptyQueue && first)
    {
        Elem* tempC = first;
        Elem* tempN = first->next;
        while (tempN != last)
        {
            delete tempC;
            tempC = tempN;
            tempN = tempN->next;
        }
        delete tempN;
        first = NULL;
        last = NULL;
    }
}

int main()
{
    isEmptyQueue  = true;
    while(scanf("%c", &cmd) > 0) {
        switch (parseEnum(cmd))
        {
            int temp;
            case CMD_LENGTH:
                printf("%d\n", totalLength());
                break;

            case CMD_PRINT:
                printAll();
                break;

            case CMD_ADD_EMPTY:
                addEmpty();
                break;

            case CMD_ADD_VALUE:
                scanf("%d", &temp);
                addElement(temp);
                break;

            case CMD_POP_AND_PRINT:
                popPrint();
                break;

            case CMD_DELETE_EMPTY_FIELDS:
                deleteEmpty();
                break;

            case CMD_ERROR:
            default:
                break;
        }
    }
    return 0;
}