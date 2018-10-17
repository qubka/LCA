#include <iostream> 
#include <list> 
#include <stack> 
#include <limits.h> 

#define BOOST_TEST_MODULE Simple testlca
#include <boost/test/unit_test.hpp>

using namespace std; 
  
class AdjListNode 
{ 
    int v; 
    int weight;
    
    public: 
    
        AdjListNode(int _v, int _w)  
        { 
            v = _v;  
            weight = _w;
        } 
        
        int getV()       
        {  
            return v;  
        } 
        
        int getWeight()  
        {  
            return weight; 
        } 
}; 
  
class Graph 
{ 
    int V;    
    list<AdjListNode> *adj;
    
    public: 
        Graph(int V);   
        void addEdge(int u, int v, int weight); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<AdjListNode>[V]; 
} 

void Graph::addEdge(int u, int v, int weight) 
{ 
    AdjListNode node(v, weight); 
    adj[u].push_back(node);
} 

int main() 
{ 
    Graph g(6); 
    g.addEdge(0, 1, 5); 
    g.addEdge(0, 2, 3); 
    g.addEdge(1, 3, 6); 
    g.addEdge(1, 2, 2); 
    g.addEdge(2, 4, 4); 
    g.addEdge(2, 5, 2); 
    g.addEdge(2, 3, 7); 
    g.addEdge(3, 4, -1); 
    g.addEdge(4, 5, -2); 
}