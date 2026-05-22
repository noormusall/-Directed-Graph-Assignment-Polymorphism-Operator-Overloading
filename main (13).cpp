#include <iostream>
#include "directedGraph.h"
#include "vertex.h"
#include "edge.h"

using namespace std; 

int main(){
    
    DirectedGraph g1(10, 10);
    DirectedGraph g2(10, 10);

    Vertex a("A", 1);
    Vertex b("B", 2);
    Vertex c("C", 3);

    Edge e1("A", "B", 5);
    Edge e2("B", "C", 7);

    g1.addVertex(a);
    g1.addVertex(b);

    g2.addVertex(a);
    g2.addVertex(b);
    g2.addVertex(c);

    g1.addEdge(e1);

    g2.addEdge(e1);
    g2.addEdge(e2);

    cout<< g1 << endl;
    cout<< g2 << endl;

    cout<< (g1==g2) << endl;

    DirectedGraph g3(10, 10);
    g3 = g1;
    cout << g3 <<endl;

    cout<< ++g1;
    cout<< g1++;
    cout<< g1;

    DirectedGraph g4 = g1 + g2;
    cout<< g4 <<endl;

    cout<< (g1 > g2)<<endl; 

    return 0;
}

