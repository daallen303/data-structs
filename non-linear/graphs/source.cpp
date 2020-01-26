#include "./graph.cpp"
#include <initializer_list>

int main(int argc, char **argv)
{

    Graph graph;
    graph.insertVertex("a");
    graph.insertVertex("b");
    graph.insertVertex("c");
    graph.insertVertex("d");

    Edge edge1 = {0,1,10};
    Edge edge2 = {2,3,20};
    Edge edge3 = {0,3,192};

    graph.insertEdge(edge1);
    graph.insertEdge(edge2);
    graph.insertEdge(edge3);

    graph.printVertexList();

    graph.printEdgeList();

    graph.deleteVertex("b");
    // graph.deleteEdge(edge3);

    graph.printVertexList();

    graph.printEdgeList();


}