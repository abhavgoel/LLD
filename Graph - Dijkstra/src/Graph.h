#ifndef GRAPH_H
#define GRAPH_H


#include<iostream>
#include<vector>
#include<map>

// class ShortestPath;
class Graph{
    private:
    int num_vertices;
    int num_edges;
    std::map<int, std::string> nodeNames;
    std::vector<std::vector<std::pair<int,double>>>_adjList; //{u ->{v,edgeWt}}

    public:
    Graph(int vertices);//Make graph from V vertices
    Graph(std::vector<std::vector<std::pair<int,double>>>&adjList);//Initialize using a adjacency list
    Graph(int vertices, double density, std::pair<double,double>distanceRange);//Initialize using density of edges
    Graph(const Graph &g);

    //API methods
    int V() const;//returns number of vertices - const to it doenst modify the value pf member variables
    int E() const;//Returns the number of edges
    bool isAdjacent(int x, int y) const;//Check if two vertices are connected
    std::vector<int> getNeighbours(int x) const;
    void addEdge(int x, int y, double edgeWt);
    void deleteEdge(int x, int y);
    double getEdgeValue(int x, int y) const;
    void setEdgeValue(int x, int y, double edgeWt);
    void setNodeValue(int x, std::string nodeName);
    std::string getNodeValue(int x);

    friend class ShortestPath;
   

};

#endif