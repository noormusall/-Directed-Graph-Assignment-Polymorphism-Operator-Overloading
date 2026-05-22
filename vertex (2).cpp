#include "vertex.h"
#include <string>

Vertex::Vertex() {
    id = "";
    value = 0;
}

Vertex::Vertex(string n,int v) : id(n), value(v){}
        
string Vertex::getId() const{
    return id;
}
int Vertex::getValue() const{
    return value;
}
        
void Vertex::setId(string id){
    this->id=id;
}
void Vertex::setValue(int value){
    this->value=value;
}

bool Vertex::operator==(const Vertex& other) const{
    return(this->id == other.id);
}