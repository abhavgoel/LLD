#include<iostream>
#include "Graph.h"
#include "MST.h"

int main() {
    Graph g("graph.txt");

    MST mst(g);
    mst.primsAlgorithm();
    std::cout<<mst.minSpanningTreeSum()<<std::endl;;

    std::vector<double>edges = mst.minSpanningTreeEdges();
    std::cout<<"MST edges"<<std::endl;
    for(auto i:edges)
    {
        std::cout<<i<<std::endl;
    }

    return 0;
}