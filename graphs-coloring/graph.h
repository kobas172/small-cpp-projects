#include "Node.h"

class Graph {
public:
    int size;
    Node** graphList;

    Graph();
    void makeGraph(int size);
    void add(int q, int index);
    void print();
    void coloring();
    ~Graph();
};

