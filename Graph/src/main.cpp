#include<iostream>
#include "Graph.h"
#include "ShortestPath.h"

int main() {
    Graph g1(50,0.2,{1.0,10.0});//graph with density 20% 
    ShortestPath sh1(g1);

    std::cout<<"Initialized a graph with 50 vertices and 20% density"<<std::endl;

    std::cout<<"Enter the source vertex ";
    int src;
    std::cin>>src;
    sh1.dijkstraAlgo(src);//source as 1
    for(int i=2;i<50;i++) {
        std::cout<<1<<" to "<<i<<" ";
        std::cout<<sh1.shortestPathCost(1,i)<<std::endl;
    }
    if(sh1.isPath(1,4))
    std::cout<<sh1.shortestPath(1,4);
    
}