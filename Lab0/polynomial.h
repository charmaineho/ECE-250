#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class polynomial {
    private:
        struct node {
            double coeff; //coefficient of node
            int exp;
            node* next; //pointer to next node
        };

        int size;
        
    public:

        node* head;
        node* curr;
        node* temp;

        polynomial();
        void addNode(int exp, double coeff);
        void del();
        void print();
        void add(polynomial p_1, polynomial p_2, polynomial p_add);
        void get(polynomial p_1, polynomial p_get);
        void eval(polynomial p_1, double x, double val);
        void mult(polynomial p_1, polynomial p_2, polynomial mult);
        void compare(polynomial p, polynomial multiply);
};

#endif