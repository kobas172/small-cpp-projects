#include <iostream>
#include "Graph.h"

int main() {
    int key;
    int size;
    scanf ("%d", &key);
    for (int i = 0; i < key; i++)
    {
        Graph graph;
        int q;
        scanf("%d", &size);
        graph.makeGraph(size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &q);
            graph.add(q, i);
        }
        graph.coloring();
    }
}
