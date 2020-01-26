#include "./graph.cpp"
#include <fstream>

int main(int argc, char **argv)
{

    Graph graph;

    // read in vertices
    std::ifstream fin;
    std::vector<std::string> vertices;
    std::string v;
    Edge e;

    fin.open("./vertices.txt");
    while(!fin.eof())
    {
        fin >> v;
        graph.insertVertex(v);
    }
    fin.close();

    fin.open("./edges.txt");
    while(!fin.eof())
    {
        fin >> e.startVertex >> e.endvertex >> e.weight;
        graph.insertEdge(e);
    }
    fin.close();

    graph.printVertexList();
    graph.printEdgeList();

    graph.BFS();
    graph.DFS();

}