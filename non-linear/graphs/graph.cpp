#include "./graph.h"

Graph::Graph()
{
    edgeList;
    vertexList;
    vertexMap;
}
Graph::~Graph()
{

}
int Graph::getVertexIndex(std::string v)
{
    return vertexMap[v];
}

void Graph::insertVertex(std::string v)
{
    //check if unique first
    vertexList.push_back(v);
    std::vector<Edge> edge;
    edgeList.push_back(edge);
    vertexMap[v] = vertexList.size()-1;
}
void Graph::insertEdge(Edge edge)
{
    // don't need to store the start vertex since we already know 
    // startVertex will be same for all edges at an index n
    // e.g edgeList[0] = {{0,x,y},{0,z,q}} where 0 is always start v
        edgeList[edge.startVertex].push_back(edge);
}
void Graph::deleteVertex(std::string v)
{
    int vertexIndex = getVertexIndex(v);
    vertexList.erase(vertexList.begin()+ vertexIndex);
    edgeList.erase(edgeList.begin()+vertexIndex);
}
// void Graph::deleteEdge(Edge edge)
// {

//     std::vector<Edge>::iterator start = edgeList[edge.startVertex].begin();
//     std::vector<Edge>::iterator end = edgeList[edge.startVertex].end();
//     edgeList[edge.startVertex].erase(std::remove(start,end, edge));
// }
void Graph::printEdgeList()
{
    for(auto &vertex : edgeList )
    {
        for(auto &edge: vertex)
        {
            std::cout << " { " << edge.startVertex << " , ";
            std::cout << edge.endvertex << " , " << edge.weight << " } ";
        }
        std::cout << std::endl;
    }
}
void Graph::printVertexList()
{
    for(auto &vertex : vertexList)
    {
        std::cout << vertex << " "; 
    }
    std::cout << std::endl;
}

