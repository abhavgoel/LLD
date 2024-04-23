#include<iostream>
#include "Graph.h"
#include "ShortestPath.h"

int main() {
    Graph g(4);

    g.addEdge(1,2,6.1);
    g.addEdge(1,3,2.0);
    g.addEdge(3,2,3.0);
    g.addEdge(1,3,4.0);

    std::cout<<g.getEdgeValue(1,2)<<std::endl;

}