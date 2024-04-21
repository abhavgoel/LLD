#include<iostream>
#include<vector>
#include "Graph.h"

//intialize empty graph
Graph::Graph() 
            : num_vertices(0) , 
            num_edges(0), 
            _adjList(std::vector<std::vector<std::pair<int,double>>>{}) {}

//intiliaze graph with given number of vertices
Graph::Graph(int vertices) 
            : num_vertices(vertices),
            num_edges(0),
            _adjList(std::vector<std::vector<std::pair<int,double>>>(vertices,std::vector<std::pair<int,double>>())){}

//intialize graph with adjacency list
Graph::Graph(std::vector<std::vector<std::pair<int,double>>> &adjList)
            : num_vertices(adjList.size()),
            num_edges(0),
            _adjList(adjList)
            {
                for(auto &it:_adjList) {
                    num_edges+=it.size();
                }
                num_edges = num_edges/2; //undirected graph
            }

//intiliaze a random graph
Graph::Graph(int vertices, double density, std::pair<double,double>distanceRange)
            : num_vertices(vertices),
            num_edges(0),
            _adjList(std::vector<std::vector<std::pair<int,double>>>(vertices,std::vector<std::pair<int,double>>()))
            {
                for(int i=0;i<num_vertices;i++)
                {
                    for(int j=i+1;j<num_vertices;j++)
                    {
                        double prob = static_cast<double>(rand()) / RAND_MAX;
                        if(prob<=density)
                        {
                            double distance = (static_cast<double>(rand()) / RAND_MAX) * (distanceRange.second - distanceRange.first) + distanceRange.first;//to make distances in range as given
                            _adjList[i].push_back(std::make_pair(j,distance));
                            _adjList[j].push_back(std::make_pair(i,distance));
                        }
                    }
                }
            }

//copy constructor
Graph::Graph(const Graph &g)
            : num_vertices(g.num_vertices),
            num_edges(g.num_edges),
            _adjList(g._adjList){}

int Graph::V() const {
    return num_vertices;
}

int Graph::E() const {
    return num_edges;
}

bool Graph::isAdjacent(int x, int y) const {

    for(auto &it : _adjList[x])
    {
        if(it.second == y)
        return true;
    }
    return false;
}

std::vector<int>Graph::getNeighbours(int x) const { 
    std::vector<int>neighbours;
    for(auto &it : _adjList[x])
    {
        neighbours.push_back(it.first);
    }
    return neighbours;
}

void Graph::addEdge(int x, int y, double edgeWt) {
    num_edges++;
    _adjList[x].push_back(std::make_pair(y,edgeWt));
    _adjList[y].push_back(std::make_pair(x,edgeWt)); 
}

void Graph::deleteEdge(int x, int y) {

    num_edges--;

    for(auto it = _adjList[x].begin();it != _adjList[x].end() ;) {
        if(it->first==y) {
            _adjList[x].erase(it);
            break;
        }
        else it++;

    }

    for(auto it = _adjList[y].begin(); it != _adjList[y].end() ;) {
        if(it->first == x) {
            _adjList[y].erase(it);
            break;
        }
        else it++;
    }
}

double Graph::getEdgeValue(int x, int y) const {
    for(auto it = _adjList[x].begin(); it != _adjList[x].end();) {
        if(it->first == y) {
            return it->second;
        }
    }
}

void Graph::setEdgeValue(int x, int y, double edgeWt) {
    for(auto it = _adjList[x].begin(); it!=_adjList[x].end();) {
        if(it->first == y) {
            it->second = edgeWt;
            break;
        }
    }

    for(auto it = _adjList[y].begin(); it != _adjList[y].end(); ) {
        if(it->first == x) {
            it->second = edgeWt;
            break;
        }
    }
}

std::string Graph::getNodeValue(int x) {
    return nodeNames[x];
}

void Graph::setNodeValue(int x, std::string nodeName) {
    nodeNames[x] = nodeName;
}

