#include<iostream>
#include "Graph.h"

class MST {
    private:
    double mstSum;
    std::vector<double> mstEdges;
    Graph graph;

    public:
    MST(const Graph& G) : graph(G){}//intialize with a Graph
    void primsAlgorithm();
    double minSpanningTreeSum();
    std::vector<double>minSpanningTreeEdges();
   
};