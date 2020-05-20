#include <iostream>
#include "list.h"
using namespace std;

polynomial::polynomial() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}

polynomial::polynomial(const int &size, const double coeff[]){
    for(int i = 0; i < size; i++){
        addNode(coeff[i]);
    }
}

void polynomial::addNode(double a) {
    nodePt n = new node;
    n->next = NULL;
    n->coeff = a;

    if(head != NULL) {
        curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
    else {
        head = n;
    }
}

void polynomial::delNode(double c) {
    nodePt delPt = NULL;
    temp = head;
    curr = head;
    while(curr != NULL && curr->coeff != c) {
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL) {
        cerr << c << "was not in the list\n";
        delete delPt;
    }
    else {
        delPt = curr;
        curr = curr->next;
        temp->next = curr;
        delete delPt;
    }
}

void polynomial::printList() {
    curr = head;
    while(curr != NULL) {
        cout << curr->coeff << endl;
        curr = curr->next;
    }
}

