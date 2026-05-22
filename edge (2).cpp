#include "edge.h"
#include <string>
using namespace std; 

Edge::Edge(){
    startV = "";
    endV = "";
    weight = 0;
}

Edge::Edge(string s,string e,int w) : startV(s), endV(e), weight(w){}

string Edge::getStartV() const{
    return startV;
}

string Edge::getEndV() const{
    return endV;
}

int Edge::getWeight() const{
    return weight;
}

void Edge::setStartV(string startV){
    this->startV= startV;
}

void Edge::setEndV(string endV){
    this->endV= endV;
}

void Edge::setWeight(int weight){
    this->weight= weight;
}

bool Edge::operator==(const Edge& other) const{ //since can have multigraph and also directed edges everything must be checked
    return(this->startV == other.startV && this->endV == other.endV && this->weight == other.weight);
}
