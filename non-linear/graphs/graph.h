#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>


struct Edge{
    int startVertex, endvertex, weight;
};

class Graph{
    std::vector<std::vector<class Edge>> edgeList;
    std::vector<std::string> vertexList;
    std::map<std::string,int> vertexMap;

    public:
    Graph();
    ~Graph();
    int getVertexIndex(std::string);
    void insertVertex(std::string);
    void insertEdge(Edge);
    void deleteVertex(std::string);
    // void deleteEdge(Edge);
    void printVertexList();
    void printEdgeList();
    void printGraph();

};
