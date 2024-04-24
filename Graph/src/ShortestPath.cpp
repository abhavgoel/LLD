#include<iostream>
#include "ShortestPath.h"
#include "Graph.h"


ShortestPath::ShortestPath(Graph g) : graph(g){
    parent.resize(g.num_vertices);
    for(int i=0;i<g.num_vertices;i++) parent[i]=i;
}

std::vector<std::string> ShortestPath::listOfVertices() {
    for(auto &it : graph.nodeNames) {
        _vertices.push_back(it.second);
    }
    return _vertices;
}

void ShortestPath::dijkstraAlgo(int source) {
    
    std::priority_queue<std::pair<double,int>,std::vector<std::pair<double,int>>,std::greater<std::pair<double,int>>>pq; //min heap
    dist.resize(graph.num_vertices, 1.0e9);

    pq.push({0.0,source});

    std::vector<int>vis(graph.num_vertices, 0);
    dist[source] = 0.0;

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(vis[node]==1)
        continue;

        vis[node]=1;

        for(auto i : graph._adjList[node]){
            double edgeWt = i.second;
            int adjNode = i.first;

            if(dist[node] + edgeWt < dist[adjNode]) {
                dist[adjNode] = edgeWt + dist[node];
                pq.push({dist[adjNode],adjNode});
                parent[adjNode] = node;
            }
        }
    }
    
}

double ShortestPath::shortestPathCost(int source, int destination) {
    return dist[destination]==1.0e9 ? -1 : dist[destination];
}

std::string ShortestPath::shortestPath(int source, int destination) {
    std::vector<int>path;
    int node = destination;

    while(parent[node]!=node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    reverse(path.begin(),path.end());

    std::string res = "";
    for(int i = 0;i<path.size();i++)
    {
        res+=std::to_string(path[i]);
        res+="-";
    }
    res.pop_back();
    return res;
}

bool ShortestPath::isPath(int source, int destination) {
    return dist[destination]==1.0e9 ? false : true;
}



