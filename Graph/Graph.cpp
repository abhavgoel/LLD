#include<iostream>
#include<vector>
#include "Graph.h"

//intialize empty graph
Graph::Graph() 
            : _vertices(0) , 
            _edges(0), 
            _adjList(std::vector<std::vector<std::pair<int,double>>>{}) {}

//intiliaze graph with given number of vertices
Graph::Graph(int vertices) 
            : _vertices(vertices),
            _edges(0),
            _adjList(std::vector<std::vector<std::pair<int,double>>>(vertices,std::vector<std::pair<int,double>>())){}

//intialize graph with adjacency list
Graph::Graph(std::vector<std::vector<std::pair<int,double>>> &adjList)
            : _vertices(adjList.size()),
            _edges(0),
            _adjList(adjList)
            {
                for(auto &it:_adjList) {
                    _edges+=it.size();
                }
                _edges = _edges/2; //undirected graph
            }

//intiliaze a random graph
Graph::Graph(int vertices, double density, std::pair<double,double>distanceRange)
            : _vertices(vertices),
            _edges(0),
            _adjList(std::vector<std::vector<std::pair<int,double>>>(vertices,std::vector<std::pair<int,double>>()))
            {
                for(int i=0;i<_vertices;i++)
                {
                    for(int j=i+1;j<_vertices;j++)
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
            : _vertices(g._vertices),
            _edges(g._edges),
            _adjList(g._adjList){}

int Graph::V() const {
    return _vertices;
}

int Graph::E() const {
    return _edges;
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
    _edges++;
    _adjList[x].push_back(std::make_pair(y,edgeWt));
    _adjList[y].push_back(std::make_pair(x,edgeWt)); 
}

void Graph::deleteEdge(int x, int y) {

    _edges--;

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

