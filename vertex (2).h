#ifndef VERTEX_H 
#define VERTEX_H
#include <iostream>
#include <string>

using namespace std; 

class Vertex{
    private:
        string id;
        int value;
    public:
        //constructor,getter and setters
        Vertex();
        Vertex(string,int);
        
        string getId() const;
        int getValue() const;
        
        void setId(string);
        void setValue(int);
        
        //comparison operator
        bool operator==(const Vertex&) const;
    
    
    
};









#endif