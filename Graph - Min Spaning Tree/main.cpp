#include<iostream>
#include "Graph.h"
#include "MST.h"

int main() {
    Graph g("graph.txt");

    MST mst(g);
    mst.primsAlgorithm();
    std::cout<<mst.minSpanningTreeSum();

    return 0;
}