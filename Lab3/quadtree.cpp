#include <iostream>
#include <sstream>
#include <string>
#include "quadtree.h"

using namespace std;

quadtree:: quadtree()
{
    root = nullptr;
    tsize = 0;
}

quadtree:: ~quadtree()
{

}

Node* quadtree:: i(Node* cur, Node* n) 
{
    if (!tsize)                     //add root
    {
        root = n;
        cout << "success" << endl;
        tsize++;
        return root;
    }

    if (cur == nullptr) 
    {
        tsize++;
        cout << "success" << endl;
        return n;
    }

    if (cur->longitude == n->longitude && cur->latitude == n->latitude)
    {
        cout << "failure" << endl;
        return cur;
    }
    
    if (n->longitude >= cur->longitude && n->latitude > cur->latitude)
    {
        cur->NE = i(cur->NE, n);
    }
    else if (n->longitude < cur->longitude && n->latitude >= cur->latitude)
    {
        cur->NW = i(cur->NW, n);
    }
    else if (n->longitude <= cur->longitude && n->latitude < cur->latitude)
    {
        cur->SW = i(cur->SW, n);
    }
    else if (n->longitude > cur->longitude && n->latitude <= cur->latitude)
    {
        cur->SE = i(cur->SE, n);
    }

    return cur;
}

Node* quadtree:: s(Node* cur, double lon, double lat)
{        
    if (cur == nullptr || (cur->longitude == lon && cur->latitude == lat))
        return cur;

    if (lon >= cur->longitude && lat > cur->latitude)
    {
        return s(cur->NE, lon, lat);
    }
    else if (lon < cur->longitude && lat >= cur->latitude)
    {
        return s(cur->NW, lon, lat);
    }
    else if (lon <= cur->longitude && lat < cur->latitude)
    {
        return s(cur->SW, lon, lat);
    }
    else
    {
        return s(cur->SE, lon, lat);
    }
}

int quadtree:: q_max(Node* cur, string attr)
{
    int data;
    int vals[4];

    if (!cur)
        return 0;

    if (attr == "p")
        data = cur->p;

    else if (attr == "r")
        data = cur->r;

    else
        data = cur->s;

    int max = data;
    vals[0] = q_max(cur->NE, attr);
    vals[1] = q_max(cur->NW, attr);
    vals[2] = q_max(cur->SW, attr);
    vals[3] = q_max(cur->SE, attr);

    for (int i = 0; i < 4; i++)
    {
        if (vals[i] > max)
            max = vals[i];
    }

    return max;
}

int quadtree:: q_min(Node* cur, string attr)
{
    int data;
    int vals[4];

    if (!cur)
        return INT32_MAX;

    if (attr == "p")
        data = cur->p;

    else if (attr == "r")
        data = cur->r;

    else
        data = cur->s;

    int min = data;
    vals[0] = q_min(cur->NE, attr);
    vals[1] = q_min(cur->NW, attr);
    vals[2] = q_min(cur->SW, attr);
    vals[3] = q_min(cur->SE, attr);

    for (int i = 0; i < 4; i++)
    {
        if (vals[i] < min)
            min = vals[i];
    }

    return min;
}

int quadtree:: q_total(Node* cur, string attr)
{
    int data;
    int vals[4];

    if (cur == nullptr)
        return 0;

    if (attr == "p")
        data = cur->p;

    else if (attr == "r")
        data = cur->r;

    else
        data = cur->s;

    int total = data;
    vals[0] = q_total(cur->NE, attr);
    vals[1] = q_total(cur->NW, attr);
    vals[2] = q_total(cur->SW, attr);
    vals[3] = q_total(cur->SE, attr);

    for (int i = 0; i < 4; i++)
    {
        total += vals[i];
    }

    return total;
}

void quadtree:: print(Node* n)
{
    if (n == nullptr)
    {
        return;
    }

    print(n->NE);
    print(n->NW);

    cout << n->name + " ";

    print(n->SW);
    print(n->SE);

}

Node* quadtree:: clear(Node* n)
{
    if (n == nullptr)
    {
        tsize = 0;
        return n;
    }

    clear(n->NE);
    clear(n->NW);
    clear(n->SE);
    clear(n->SW);

    delete(n);

    return nullptr;

}

void quadtree:: size() 
{
    stringstream ss;
    ss << "tree size " << tsize;
    cout << ss.str() << endl; 
}