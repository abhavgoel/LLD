#include<algorithm>
#include<iostream>
#include<queue>
#include "Graph.h"

class ShortestPath {
    private:
    Graph graph;
    std::vector<std::string> _vertices;
    std::vector<int>parent;
    std::priority_queue<std::pair<double,int>,std::vector<std::pair<double,int>>,std::greater<std::pair<double,int>>>pq; //min heap

    public:
    ShortestPath(Graph g) {}
    std::vector<std::string>listOfVertices(){}
    int shortestPathCost(int source, int destination){}//returns path cost
    std::string shortestPath(int source, int destination){}//return path from source to destination as a string
    

};