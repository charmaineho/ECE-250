#include <iostream>
#include <sstream>
#include <string>
#include "undirectedGraph.h"

using namespace std;

Graph:: Graph()
{
    numCity = 0;
    numEdges = 0;
}

void Graph:: insert(string n) 
{
    Node* temp = new Node;
    temp->name = n;
    temp->nextCity = nullptr;
    temp->edge = nullptr;
    temp->degree = 0;
    temp->id = numCity;

    if (!head)
    {
        head = temp;
        cout << "success" << endl;
        numCity++;
        return;
    }

    Node* check = head;
    Node* cur = head;

    while (check)
    {
        if (check->name == n)
        {
            cout << "failure" << endl;
            return;
        }
        check = check->nextCity;
    }
    
    while (cur->nextCity)
    {
        cur = cur->nextCity;
    }
    cur->nextCity = temp;
    cout << "success" << endl;
    numCity++;
}

void Graph:: setd(string name1, string name2, double d)
{
    Node* city1 = search(name1);
    Node* city2 = search(name2);

    if (city1 && city2)
    {
        bool copy1 = addEdge(city1, name2, d);
        bool copy2 = addEdge(city2, name1, d);

        if(copy1 && copy2)
        {
            cout << "success" << endl;
        }
        else
        {
            numEdges++;
            cout << "success" << endl;
        }
    }
    else
    {
        cout << "failure" << endl;
        return;
    }
}

Edge* Graph:: createEdge(string n, double d)
{
    Edge* temp = new Edge;
    temp->name = n;
    temp->dist = d;
    temp->parent = nullptr;
    temp->next = nullptr;
    return temp;
}

bool Graph:: addEdge(Node* start, string n, double d) 
{
    Edge* temp = createEdge(n, d);

    if (!start->edge)
    {
        start->edge = temp;
    }
    else
    {
        Edge* cur = start->edge;
        while (cur->next)
        {
            if (cur->name == n)
            {
                cur->dist = d;
                return true;
            }
            cur = cur->next;
        }
        cur->next = temp;
    }
    start->degree++;
    return false;
}

Node* Graph:: search(string n) 
{
    Node* cur = head;
    while (cur)
    {
        //if city is found
        if (cur->name == n)
            return cur;

        cur = cur->nextCity;
    }
    //if city was not found
    return nullptr;
}

void Graph:: distance(string name1, string name2)
{
    Node* city1 = search(name1);
    Edge* check = city1->edge;

    if(city1 && search(name2)){
        while (check != nullptr)
        {
            if (check->name == name2)
            {
                stringstream ss;
                ss << "direct distance " << name1 << " to " << name2 << " " << check->dist;
                cout << ss.str() << endl;
                return;
            }
            check = check->next;
        }
    }
    cout << "failure" << endl;
}

void Graph:: degree(string n) 
{
    Node* cur = search(n);
    if (!cur)
    {
        cout << "failure" << endl;
        return;
    }
    stringstream ss;
    ss << "degree of " << n << " " << cur->degree;
    cout << ss.str() << endl;
}

void Graph:: graph_nodes()
{
    stringstream ss;
    ss << "number of nodes " << numCity;
    cout << ss.str() << endl;
}

void Graph:: graph_edges()
{
    stringstream ss;
    ss << "number of edges " << numEdges;
    cout << ss.str() << endl;
}

void Graph:: clear()
{
    if(head) 
    {
        Node* cur = head;
        Edge* list = cur->edge;

        while (!cur)
        {
            while (!list)
            {
                Edge* nextEdge = list->next;
                delete list;
                list = nextEdge;
            }
            Node* nextCur = cur->nextCity;
            delete cur;
            cur = nextCur;
        }
        head = nullptr;
        numCity = 0;
        numEdges = 0;
    }
}

void print(Edge* cur)
{
    if (!cur)
        return;

    print(cur->parent);
    cout << cur->name + " ";
}

Edge* Graph:: dijkstra(string name1, string name2) 
{
    Edge* vertex = new Edge[numCity];
    Edge temp;
    Heap* heap = new Heap(numCity);
    Node* cur = head;
    int i = 0;

    while(i < numCity)
    {
        string citName = cur->name;
        vertex[i].name = citName;
        vertex[i].parent = nullptr;

        if (citName != name1)
        {
            temp = *heap->createEdge(citName, INT32_MAX);
            vertex[i].dist = INT32_MAX;
        }
        else
        {
            temp = *heap->createEdge(name1, 0);
            vertex[i].dist = 0;
        }
        heap->insert(temp);
        cur = cur->nextCity;
        i++;
    }

    Edge* dest = createEdge(name2, 0);
    while (!heap->isEmpty())
    {
        Edge* u = heap->extMin();
        Edge* currEdge = search(u->name)->edge;

        while (currEdge)
        {
            int v = 0;
            while (v < numCity)
            {
                if (heap->pq[v].name == currEdge->name)
                {
                    if (heap->pq[v].dist > u->dist + currEdge->dist)
                    {
                        heap->pq[v].dist = (u->dist + currEdge->dist);
                        heap->pq[v].parent = u;
                        if (heap->pq[v].name == name2)
                        {
                            dest->dist = heap->pq[v].dist;
                            dest->parent = u;
                        }
                        heap->heapify(0);
                    }
                }
                v++;
            }
            currEdge = currEdge->next;
        }
    }

    return dest;
    stringstream ss;
    ss << "shortest distance " << name1 << " to " << name2 << " " << dest->dist;
    cout << ss.str() << endl;
    print(dest);
    return nullptr;
}

void Graph::short_d(string name1, string name2)
{
    if (!search(name1) || !search(name2)) {
        cout << "failure" << endl;
    }
    else if (name1 == name2)
    {
        cout << "shortest distance " + name1 + " to " + name2 + " 0" << endl;
    }
    else if (dijkstra(name1, name2))
    {
        if (!dijkstra(name1, name2)->dist) {
            cout << "failure" << endl;
            return;
        }
        stringstream ss;
        ss << "shortest distance " << name1 << " to " << name2 << " " << dijkstra(name1, name2)->dist;
        cout << ss.str() << endl;
    }
    return;
}

void Graph::print_path(string name1, string name2)
{
    if (!search(name1) || !search(name2)) {
        cout << "failure" << endl;
        return;
    }
    else if (name1 == name2)
    {
        cout << name2 << endl;
        return;
    }
    else if (!dijkstra(name1, name2))
    {
        cout << "failure" << endl;
        return;
    }

    print(dijkstra(name1, name2));
    cout << endl;
}

void Heap:: decKey(int pos)
{
    heapify(0);
    pq[pos].name = "";
    pq[pos].dist = INT32_MIN;
}

bool Heap:: isEmpty()
{
    return numCities == 0;
}

Edge* Heap:: extMin()
{
    Edge *temp = new Edge;
    temp->name = pq[0].name;
    temp->next = pq[0].next;
    temp->parent = pq[0].parent;
    temp->dist = pq[0].dist;

    if (numCities > 1)
    {
        pq[0] = pq[numCities - 1];
    }
    numCities--;
    return temp;
}

void Heap:: heapify(int n)
{
    int smallest = n; 
    int left = 2*n + 1; 
    int right = 2*n + 2; 
  
    if (numCities > left && pq[left].dist < pq[n].dist)
        smallest = left;

    if (numCities > right && pq[right].dist < pq[smallest].dist)
        smallest = right;

    if (smallest != n)
    { 
        heapify(smallest); 
        swap(pq[n], pq[smallest]); 
    } 
}

void Heap:: insert(Edge cur)
{
    heapify(0);
    numCities++;
    int i = numCities - 1;
    pq[i] = cur;

}

Edge* Heap:: createEdge(string n, double d)
{
    Edge* temp = new Edge;
    temp->name = n;
    temp->dist = d;
    temp->parent = nullptr;
    temp->next = nullptr;
    return temp;
}

Heap:: Heap(int size)
{
    numCities = 0;
    pq = new Edge[size];
}