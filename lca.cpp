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
        void LCA(int u , int v);
        void getParent(int node);
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

void Graph::getParent(int node)
{       
    for (int n = 0; n < node; n++) 
    {
        list<AdjListNode>::iterator i;     
        for (i = adj[n].begin(); i != adj[n].end(); ++i)
        {
            if (*iter == node)
            {
                cout << n << " ";
                //parent[tree[node][i]] = node ; 
            }
        }
    }
}

void Graph::LCA(int u , int v)
{
    /*bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
    {
        visited[i] = false; 
    }*/
    
    //int *parent = new int[V];
    //GetParents(adj[v].begin(), -1);

    /*int lca; 
    while(1)
    {
        visited[u] = true ; 
        if(u == root_node)
        {
            break ; 
        }
        u = parent[u] ; 
    }


    while(1)
    {
        if(visited[v])
        {
            lca = v;    
            break;  
        }
        
        v = parent[v] ; 
    }
    
    return lca ; */
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
    
    g.getParent(5);
}

/*BOOST_AUTO_TEST_CASE(simple_test) 
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
    
    g.getParent(5);
    
    //BOOST_CHECK_EQUAL(2+2, 4);
}*/


/*
    // A recursive function used by shortestPath. See below link for details 
// https://www.geeksforgeeks.org/topological-sorting/ 
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) 
{ 
    // Mark the current node as visited 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<AdjListNode>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        AdjListNode node = *i; 
        if (!visited[node.getV()]) 
            topologicalSortUtil(node.getV(), visited, Stack); 
    } 
  
    // Push current vertex to stack which stores topological sort 
    Stack.push(v); 
} 
  
void Graph::shortestPath(int s) 
{ 
    stack<int> Stack; 
    int dist[V]; 

    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  

    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack); 

    for (int i = 0; i < V; i++) 
        dist[i] = INF; 
    dist[s] = 0; 
  
    // Process vertices in topological order 
    while (Stack.empty() == false) 
    { 
        int u = Stack.top(); 
        Stack.pop(); 

        list<AdjListNode>::iterator i; 
        if (dist[u] != INF) 
        { 
          for (i = adj[u].begin(); i != adj[u].end(); ++i) 
             if (dist[i->getV()] > dist[u] + i->getWeight()) 
                dist[i->getV()] = dist[u] + i->getWeight(); 
        } 
    } 

    for (int i = 0; i < V; i++) 
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " "; 
} 
*/