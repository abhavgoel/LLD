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
