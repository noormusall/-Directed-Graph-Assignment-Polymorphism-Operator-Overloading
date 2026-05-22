#include "graph.h"

Graph::Graph(int vCapacity,int eCapacity) {
    vCount=0;
    eCount = 0;
    
    this->vCapacity = vCapacity;
    this->eCapacity = eCapacity;
    
    vertices = new Vertex[vCapacity]; //which uses the default constructor of Vertex
    edges = new Edge[eCapacity];
    
}
Graph::~Graph(){
    delete[] vertices;
    delete[] edges;
} 



