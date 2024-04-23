#include<iostream>
#include "ShortestPath.h"
#include "Graph.h"


ShortestPath::ShortestPath(Graph g) : graph(g){
    for(int i=0;i<graph.V();i++) parent[i]=i;
}

std::vector<std::string> ShortestPath::listOfVertices() {
    for(auto &it : graph.nodeNames) {
        _vertices.push_back(it.second);
    }
    return _vertices;
}

int ShortestPath::shortestPathCost(int source, int destination) {
    while(!pq.empty())pq.pop();

    std::vector<double>dist(graph.V(),1.0e9);

    pq.push({0.0,source});

    std::vector<int>vis(graph.V(), 0);
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
    return dist[destination]==1.0e9 ? -1 : dist[destination];
}

std::string ShortestPath::shortestPath(int source, int destination) {
    std::vector<int>path;
    int node = destination;

    while(parent[node]!=source) {
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
    return res;
}




