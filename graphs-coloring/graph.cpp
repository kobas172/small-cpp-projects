#include "Graph.h"
#include <iostream>

Graph::Graph() {
    this->size = 0;
    this->graphList = nullptr;
}

void Graph::makeGraph(int size) {
    this->size = size;
    this->graphList = new Node*[size];
    for (int i = 0; i < size; i++)
    {
        Node* temp = new Node(i);
        graphList[i] = temp;
    }
}

void Graph::add(int q, int index) {
    Node* temp = this->graphList[index];
    temp->q = q;
    temp->list = new Node*[q];
    int key;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &key);
        temp->list[i] = this->graphList[key];
    }
}

void Graph::print() {
    for (int i = 0; i < this->size; i++)
        printf("%d", this->graphList[i]->number);
}

void Graph::coloring() {
    int *colors = new int[this->size];
    bool *list = new bool[this->size];
    Node **anotherlist = new Node*[this->size];

    for (int i = 0; i < this->size; i++)
    {
        colors[i] = -1000;
        list[i] = false;
        anotherlist[i] = this->graphList[i];
    }

    for (int i = 0; i < this->size-1; i++)
    {
        for (int j = 0; j < this->size-i-1; j++)
        {
            if (this->graphList[j]->q < this->graphList[j+1]->q)
            {
                Node* temp = this->graphList[j];
                this->graphList[j] = this->graphList[j+1];
                this->graphList[j+1] = temp;
            }
            else if (this->graphList[j]->q == this->graphList[j+1]->q)
            {
                if (this->graphList[j]->number > this->graphList[j+1]->number)
                {
                    Node* temp = this->graphList[j];
                    this->graphList[j] = this->graphList[j+1];
                    this->graphList[j+1] = temp;
                }
            }
        }
    }

    colors[anotherlist[graphList[0]->number]->number] = 0;
//    printf("%d\n", anotherlist[graphList[0]->number]->number);
//    print();
//    printf("\n\n");

    for (int i = 1; i < this->size; i++)
    {
        for (int j = 0; j <  anotherlist[this->graphList[i]->number]->q; j++)
            if (colors[anotherlist[this->graphList[i]->number]->list[j]->number] != -1000)
                list[colors[anotherlist[this->graphList[i]->number]->list[j]->number]] = true;

        int iterator = 0;
        while (iterator < this->size)
        {
            if (!list[iterator])
                break;
            iterator++;
        }

        colors[anotherlist[this->graphList[i]->number]->number] = iterator;

        for (int j = 0; j < anotherlist[this->graphList[i]->number]->q; j++)
            if (colors[anotherlist[this->graphList[i]->number]->list[j]->number] != -1000)
                list[colors[anotherlist[this->graphList[i]->number]->list[j]->number]] = false;
    }

    int max = -10000;
    int i = 0;
    while (i < this->size)
    {
        //printf("%d ", colors[i]);
        if (colors[i] > max)
            max = colors[i];
        i++;
    }
    //printf("\n");

    printf("%d\n", max+1);

    delete[] anotherlist;
    delete[] list;
    delete[] colors;
}

Graph::~Graph() {
    for (int i = 0; i < this->size; i++)
        delete this->graphList[i];
}

