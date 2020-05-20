#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node 
{
    string name;
    double latitude;
    double longitude;
    int p;
    int r;
    int s;

    Node* NW;
    Node* NE;
    Node* SW;
    Node* SE;

};

class quadtree 
{
    public:
        Node **tree;
        Node *root;
        int tsize;

        Node* i(Node* cur, Node* n);
        Node* s(Node* cur, double lon, double lat);
        int q_max(Node* cur, string attr);
        int q_min(Node* cur, string attr);
        int q_total(Node* cur, string attr);
        void print(Node* n);
        Node* clear(Node* n);
        void size();
        quadtree();
        ~quadtree();
    
};