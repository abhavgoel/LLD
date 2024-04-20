#include<iostream>
#include<vector>


class Graph{
    private:
    int _vertices;
    int _edges;
    std::vector<std::vector<std::pair<int,double>>>_adjList;

    public:
    Graph();//default contructor
    Graph(int vertices);//Make graph from V vertices
    Graph(std::vector<std::vector<std::pair<int,double>>>&adjList);//Initialize using a adjacency list
    Graph(int vertices, double density, std::pair<double,double>distanceRange);//Initialize using density of edges
    Graph(const Graph &g);

    //API methods
    int V() const;//returns number of vertices - const to it doenst modify the value pf member variables
    int E() const;//Returns the number of edges
    bool isAdjacent(int x, int y);//Check if two vertices are connected




    

};