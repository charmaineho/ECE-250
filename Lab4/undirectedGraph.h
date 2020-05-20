#include <iostream>
#include <string>

using namespace std;

struct Edge
{
    string name;
    double dist;
    Edge* next;
    Edge* parent;
};

struct Node 
{
    string name;
    int degree;
    int id;
    Node* nextCity;
    Edge* edge;
};

class Graph 
{
    public:
        
        int numCity;
        int numEdges;
        
        Node* head = nullptr;

        Node* search(string n);
        Edge* createEdge(string n, double d);
        Edge* dijkstra(string name1, string name2);
        bool addEdge(Node* start, string n, double d);
        void insert(string n);
        void setd(string name1, string name2, double d);
        void degree(string n);
        void graph_nodes();
        void graph_edges();
        void clear();
        void distance(string name1, string name2);
        void short_d(string name1, string name2);
        void print_path(string name1, string name2);
        Graph();
};

class Heap
{
    public:
    Edge* pq;
    int numCities;

    Heap(int size);
    Edge* extMin();
    Edge* createEdge(string n, double d);
    bool isEmpty();
    void decKey(int pos);
    void insert(Edge newItem);
    void heapify(int pos);
};