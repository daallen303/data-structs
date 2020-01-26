#include "./graph.h"
#include <queue>
#include <unordered_set>
#include <stack>

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
void Graph::deleteEdge(Edge edge)
{

    std::vector<Edge>::iterator start = edgeList[edge.startVertex].begin();
    std::vector<Edge>::iterator end = edgeList[edge.startVertex].end();
    edgeList[edge.startVertex].erase(std::remove(start,end, edge));
}
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
void Graph::BFS()
{
    std::vector<int> visited;
    std::queue<int> q;
    std::string v = vertexList[0];
    bool done = false;

    int i = 0;

    visited.push_back(0);
    
    while(done != true)
    {
        std::cout << i << " ";
        for(auto &edge: edgeList[i])
        {
            if(std::find(visited.begin(), visited.end(), edge.endvertex) == visited.end())
            {
                    q.push(edge.endvertex);
                    visited.push_back(edge.endvertex);
            }
        }
        if(q.empty())
        {
          done = true;
        }
        else 
        {
            i = q.front();
            q.pop();
        }
    }
    std::cout << std::endl;
}

void Graph::DFS(){
    std::unordered_set<int> visited;
    std::stack<int> s;
    int current_vertex = 0;
    bool done = false;
    bool new_vertex;

    while(!done)
    {
        new_vertex = false;
        if(visited.find(current_vertex) == visited.end())
        {
            visited.insert(current_vertex);
            std::cout << current_vertex << " ";
        }
        if(edgeList[current_vertex].size() != 0)
        {
            for(auto &edge : edgeList[current_vertex])
            {
                if(visited.find(edge.endvertex) == visited.end())
                {
                    s.push(current_vertex);
                    current_vertex = edge.endvertex;
                    new_vertex = true;
                    break;
                }
                
            }

        }
        
        // if ! new vertex, then vertex has been fully explored
        if( !new_vertex )
        {
            if(!s.empty())
            {
                current_vertex == s.top();
                s.pop();
            }
            else
            {
                done = true;
            }
        }
    }
    std::cout << std::endl;
}
