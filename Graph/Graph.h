#include<iostream>
#include<vector>


class Graph{
    private:
    int vertices;
    int edges;
    std::vector<std::vector<int>>adjList;

    public:
    Graph();
    Graph(int V);
    

};