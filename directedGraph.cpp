
#include "directedGraph.h"
#include <iostream>

using namespace std; 

DirectedGraph::DirectedGraph(int vCapacity, int eCapacity): Graph(vCapacity,eCapacity){}

DirectedGraph::~DirectedGraph() {} 

//Search functions

bool DirectedGraph::searchVertex(const Vertex& v) { //search for a Vertex uses == operator for vertices
    for(int i = 0; i< vCount; i++){
        if(vertices[i] == v){
            return true;
        }
    }
    return false;
    
}

bool DirectedGraph::searchEdge(const Edge& e) {
    for(int i = 0; i< eCount; i++){
        if(edges[i] == e){
            return true;
        }
    }
    return false;
}

//add functions

bool DirectedGraph::addVertex(Vertex& v){
    if (searchVertex(v) == false && vCount != vCapacity){
        vertices[vCount] = v;
        vCount++;
        return true;
    }else{
        return false;
    }
}

bool DirectedGraph::addVertices(Vertex* vArray, int size){
    bool temp = true; //all added
    for(int i=0; i< size;i++){
        if(addVertex(vArray[i]) == false){
            temp= false;
        }
    }
    return temp;
}

bool DirectedGraph::addEdge(Edge& e){
    if(searchEdge(e)==false && eCount != eCapacity){ //assumed user wouldnt add an edge whose vertices arent the ones in the graph
        edges[eCount] = e;  
        eCount++;
        return true;
    }else{
        return false;
    }
}

//remove functions

bool DirectedGraph::removeVertex(Vertex& v){
    int index = -1;
    if (searchVertex(v) == true){
        for(int i=0; i< eCount; i++){
            if(vertices[i] == v){
            index = i;
            break;
            }
        }
        if(index == -1){
            return false;
        }//otherwise:
        
        //need to remove any attatched edges
        for(int i = 0; i < eCount ; ){
            if(edges[i].getStartV() == v.getId() || edges[i].getEndV() == v.getId()){
                //if edges connected to the vertex u wanna remove then shift eArray down
                for (int j = i; j < eCount - 1; j++) {
                    edges[j] = edges[j + 1];
                }
                eCount--;
            }else{
                i++; //only increment if didnt meet the criteria
            }
        }
        
        
        
        //shifting vertices to remove
        for(int i = index; i < vCount-1; i++){
            vertices[i]=vertices[i+1];
        }
        vCount--;
        return true;
        
    }else{
        return false;
    }
}

bool DirectedGraph::removeEdge(Edge& e){
    int index = -1;
    if (searchEdge(e) == true){
        for(int i=0; i< eCount; i++){
            if(edges[i] == e){
            index = i;
            break;
            }
        }
        if(index == -1){
            return false;
        }
        
        //otherwise shift/remove
        for(int i = index; i < eCount-1; i++){
            edges[i]=edges[i+1];
        }
        eCount--;
        return true;
        
    }else{
        return false;
    }
}

//other functions

void DirectedGraph::display() const{
    cout << "Vertices:" << endl;
    for (int i = 0; i < vCount; i++) {
        cout <<"vertex: "<< vertices[i].getId() << "( value " <<vertices[i].getValue() << ")" << endl;
    }

    cout << "Edges:" << endl;
    for (int i = 0; i < eCount; i++) {
        cout << edges[i].getStartV() << "->"<<edges[i].getEndV()<< " (weight " << edges[i].getWeight() << ")" << endl;
    }
    
}

string DirectedGraph::toString() const{
    string FinalString = "";
    
    for(int i = 0; i< eCount; i++){
        FinalString += edges[i].getStartV()+ "->" + edges[i].getEndV();
        FinalString += "(weight " + to_string(edges[i].getWeight()) + ")";
        if(i < eCount -1){
            FinalString += ";";
        }
    }
    
    return FinalString;
}

bool DirectedGraph::clean(){
    for (int i = 0; i < vCount; i++) {
        vertices[i] = Vertex(); //the original state of our arrays
    }

    for (int i = 0; i < eCount; i++) {
        edges[i] = Edge();
    }

    vCount = 0;
    eCount = 0;

    return true;
}


//Problem 2:

bool DirectedGraph::operator==(const DirectedGraph& other) {
    //
    if (vCount != other.vCount || eCount != other.eCount) {
        return false;
    }

for (int i = 0; i < vCount; i++) {
        if (this->searchVertex(other.vertices[i]) == false) {
            return false;
        }
    }

    for (int i = 0; i < eCount; i++) {
        if (this->searchEdge(other.edges[i]) == false ) {
            return false;
        }
    }
//if at least one vertex or edge in our graph not found in other then return false basically
    return true;
}

DirectedGraph& DirectedGraph::operator=(const DirectedGraph& other) {
    if (this != &other) { //using the == operator to make sure ur not self-assigning

        delete[] vertices; //empty them
        delete[] edges;

        vCapacity= other.vCapacity;
        eCapacity= other.eCapacity;
        
        vertices = new Vertex[vCapacity];
        edges = new Edge[eCapacity];
        
        vCount = other.vCount;
        eCount = other.eCount;

        for (int i = 0; i < vCount; i++) {
            vertices[i] = other.vertices[i]; //no dynamic so safe
        }

        for (int i = 0; i < eCount; i++) {
            edges[i] = other.edges[i];
        }
    }

    return *(this);
}

//G++ use current then update
DirectedGraph DirectedGraph::operator++(int) {
    DirectedGraph preUpdate = *this;

    for (int i = 0; i < eCount; i++) {
        edges[i].setWeight(edges[i].getWeight() + 1);
    }

    return preUpdate;
}


//++G update first then use
DirectedGraph& DirectedGraph::operator++() {
    for (int i = 0; i < eCount; i++) {
        edges[i].setWeight(edges[i].getWeight() + 1);
    }
    return *this;
}

//friend
DirectedGraph operator+(const DirectedGraph& g1, const DirectedGraph& g2) {
    DirectedGraph g3((g1.vCapacity +g2.vCapacity),(g1.eCapacity +g2.eCapacity));

    for (int i = 0; i < g1.vCount; i++) {
        g3.addVertex(g1.vertices[i]); 
    }
    for (int i = 0; i < g2.vCount; i++) {
        g3.addVertex(g2.vertices[i]);
    }
    for (int i = 0; i < g1.eCount; i++) {
        g3.addEdge(g1.edges[i]);
    }
    for (int i = 0; i < g2.eCount; i++) {
        g3.addEdge(g2.edges[i]);
    }

    return g3;
}

bool DirectedGraph::operator>(const DirectedGraph& other) const{
    
    int sum1 = 0;
    int sum2 = 0;
    
    for (int i = 0; i < eCount; i++) {
        sum1 += edges[i].getWeight();
    }
    for (int i = 0; i < other.eCount; i++) {
        sum2 += other.edges[i].getWeight();
    }
    
    return (sum1>sum2);
}

//friend
ostream& operator<<(ostream& output, const DirectedGraph& g){
    output << "Vertices:" << endl;
    for (int i = 0; i < g.vCount; i++) {
        output <<"vertex: "<< g.vertices[i].getId() << "( value " <<g.vertices[i].getValue() << ")" << endl;
    }

    output << "Edges:" << endl;
    for (int i = 0; i < g.eCount; i++) {
        output << g.edges[i].getStartV() << "->"<<g.edges[i].getEndV()<< " (weight " << g.edges[i].getWeight() << ")" << endl;
    }
    
    return output;
    }
