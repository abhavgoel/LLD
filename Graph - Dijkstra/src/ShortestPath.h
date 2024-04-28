#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include<algorithm>
#include<iostream>
#include<queue>
#include "Graph.h"


class ShortestPath {
    private:
    Graph graph;
    std::vector<std::string> _vertices;
    std::vector<int>parent;
    std::vector<double>dist;
    

    public:
    ShortestPath(Graph g);
    std::vector<std::string>listOfVertices();
    void dijkstraAlgo(int source);
    double shortestPathCost(int source, int destination);//returns path cost
    std::string shortestPath(int source, int destination);//return path from source to destination as a string
    bool isPath(int source, int destination);
    
};

#endif