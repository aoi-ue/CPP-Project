#include "Graph.h"
//uncomment this to include your own "heap.h"
//we will assume that you use the same code in your previous assignment
#include "heap.h"
# define INF 9999

std::ostream& operator<<(std::ostream& os, nodeWeightPair const& n) {
    return os << " (idx:" << n._node << " w:" << n._weight << ")";
}

Graph::Graph(int n)
{
    _al = new List<nodeWeightPair> [n];
    _nv = n;
}

int Graph::shortestDistance(int s, int d)
{
    _pq = new Heap<nodeWeightPair>;
    
    // all the nodes = infinite
    for (int i = 0; i < _nv; i++) {
        // initialize starting = 0 in pq
        if (i == 0) nodeWeightPair newPair(i, 0);
        nodeWeightPair newPair(i, INF);
        _pq->insert(newPair);
    }
        
    while (!_pq->empty()) {
        
        
//        nodeWeightPair current = _pq->extractMin();
 
//        List<nodeWeightPair> currentList = _al[current.nodeIndex()];
//        for (currentList.start(); !currentList.end(); currentList.next())
//            cout << currentList.current();
    }
    
    return -1;
}
void Graph::addEdge(int s, int d, int w)
{
    _al[s].insertHead(nodeWeightPair(d, w));
}

void Graph::printGraph()
{
    for (int i=0; i < _nv; i++)
    {
        cout << "Node " << i << ": ";
        for (_al[i].start(); !_al[i].end(); _al[i].next())
            cout << " (" << _al[i].current().nodeIndex() << "," << _al[i].current().weight() << ")";
        cout << endl;
        
    }
    
}
Graph::~Graph()
{
    
    delete[] _al;
    
}
