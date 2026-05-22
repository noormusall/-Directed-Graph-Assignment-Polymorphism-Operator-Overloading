#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "vertex.h"
#include "edge.h"
#include <string>

using namespace std; 

class Graph{ 
    protected:
        Vertex* vertices;
        int vCapacity; //capacity of array
        int vCount; //count currently 
        
        Edge* edges;
        int eCapacity;
        int eCount; //will be zero in the constructors
    public: 
        //default constructor not needed since parametrized lets you custom the size of arrays
        Graph(int,int);
        virtual ~Graph(); 
        
        
        virtual bool addVertex(Vertex& v)=0; 
        virtual bool addVertices(Vertex* vArray, int size) = 0; 
      
        virtual bool removeVertex(Vertex& v) = 0; 
        
        virtual bool addEdge(Edge& e) = 0; 

        virtual bool removeEdge(Edge& e)=0; 

        virtual bool searchVertex(const Vertex& v) = 0; 

        
     
        virtual bool searchEdge(const Edge& e) =0; 
      
        virtual void display() const = 0; 
        
        virtual string toString () const = 0; 
   
        virtual bool clean() = 0; 


};

#endif