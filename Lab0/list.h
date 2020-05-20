#include <iostream>
using namespace std;

class polynomial {
    private: 
        typedef struct node {
            int coeff; //coefficient of node
            node* next; //pointer to next node
        }* nodePt;

        nodePt head;
        nodePt curr;
        nodePt temp;
        
    public: //where functions go
        polynomial();
        void addNode(double a);
        void delNode(double c);
        void printList();
};