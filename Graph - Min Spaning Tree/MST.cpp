#include<iostream>
#include<queue>
#include "Graph.h"
#include "MST.h"

void MST::primsAlgorithm() {
    int V = graph.V();
    std::vector<int>vis(V,0);

    mstSum = 0;

    std::priority_queue<std::pair<double,int>, std::vector<std::pair<double,int>>, std::greater<std::pair<double,int>>> pq;
    pq.push({0.0,0});

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        double d = it.first;
        int node  = it.second;

        if(vis[node]==1) continue;

        vis[node] = 1;
        mstSum += d;
        
        if(d!=0)
        mstEdges.push_back(d);
        
        for(auto i:graph._adjList[node]) {
            double edgeWt = i.second;
            int adjNode = i.first;

            if(vis[adjNode]==0) {
                pq.push({edgeWt,adjNode});
            }
        }

    }

}

double MST::minSpanningTreeSum() {
    return mstSum;
}

std::vector<double> MST::minSpanningTreeEdges() {
    return mstEdges;
}
