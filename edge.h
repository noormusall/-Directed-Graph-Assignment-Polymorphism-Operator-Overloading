#ifndef EDGE_H 
#define EDGE_H
#include <iostream>
#include <string>

using namespace std; 
class Edge{
    private:
        string startV; //only the ID of the vertex
        string endV;  //only the ID of the vertex
        int weight;
        
    public:
        Edge();
        Edge(string,string,int); //regular constructor
    
        string getStartV() const;
        string getEndV() const;
        int getWeight() const;
        
        void setStartV(string);
        void setEndV(string);
        void setWeight(int);
        
        //comparison
        bool operator==(const Edge&) const;
        
};







#endif
