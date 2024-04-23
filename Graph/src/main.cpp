#include<iostream>
#include "Graph.h"
#include "ShortestPath.h"

int main() {
    Graph g(4);

    g.addEdge(1,2,6.0);
    g.addEdge(1,3,2.0);
    g.addEdge(3,2,3.0);
    g.addEdge(1,3,4.0);

    ShortestPath sh(g);

    std::cout<<sh.shortestPathCost(1,2)<<std::endl;
    std::cout<<sh.shortestPathCost(1,3);

}