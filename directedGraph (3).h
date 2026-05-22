#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include "graph.h"
#include <string>



class DirectedGraph : public Graph{
    public:
        //regular constructor
        DirectedGraph(int,int);
        virtual ~DirectedGraph();
        
        
        //overiding, might be different order from how listed in the assignment instructions:
        bool searchVertex(const Vertex& v) override; 
        bool searchEdge(const Edge& e) override;
        
        bool addVertex(Vertex& v) override;
        bool addVertices(Vertex* vArray, int size) override; //assumed forgotten size 
        bool addEdge(Edge& e) override;
        
        bool removeVertex(Vertex& v) override;
        bool removeEdge(Edge& e) override;

    
        void display() const override;
        string toString() const override;
        bool clean() override;
        
        bool operator==(const DirectedGraph& other);
        DirectedGraph& operator=(const DirectedGraph& other); //return reference to the current DirectedGraph
       

        DirectedGraph operator++(int); //G++
        DirectedGraph& operator++(); //++G
        
        friend DirectedGraph operator+(const DirectedGraph& g1,const DirectedGraph& g2);
        
        bool operator>(const DirectedGraph& other) const;
        
        friend ostream& operator<<(ostream& output, const DirectedGraph& g);
            
};

#endif