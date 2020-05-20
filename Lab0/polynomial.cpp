#include <iostream>
#include "polynomial.h"
#include <string>
#include <math.h>
using namespace std;

polynomial::polynomial() {
    head = nullptr;
    curr = nullptr;
    temp = nullptr;
}

void polynomial::addNode(int exp, double coeff) {
    node* n = new node;
    n->next = nullptr;
    n->coeff = coeff;
    n->exp = exp;

    if(head != nullptr) {
        curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = n;
    }
    else {
        head = n;
    }
}

void polynomial::del() {
    node *curr = head;
    node *next;

    while(curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    head = nullptr;
}

void polynomial::print() {
    curr = head;
    while(curr != nullptr) {
        cout << curr->exp;
        cout << curr->coeff << endl;
        curr = curr->next;
    }
}

void init(int m) {
    if(m > 0) {
        cout << "success" << endl;
    }
    else {
        cout << "failure" << endl;
    }
}

void polynomial::add(polynomial p_1, polynomial p_2, polynomial p_add) {
    int exp_cur;
    double sum;
    bool equal = true;

    node *p1_cur = new node;
    node *p2_cur = new node;
    node *padd_cur = new node;
    p1_cur = p_1.head;
    p2_cur = p_2.head;
    padd_cur = p_add.head; 

    while((p1_cur != nullptr || p2_cur != nullptr) && padd_cur->next != nullptr) {
        if((p2_cur == nullptr) && (p1_cur != nullptr)) {
            exp_cur = p1_cur->exp;
            sum = p1_cur->coeff;
            p1_cur = p1_cur->next;
        }
        if((p1_cur == nullptr) && (p2_cur != nullptr)) {
            exp_cur = p2_cur->exp;
            sum = p2_cur->coeff;
            p2_cur = p2_cur->next;
        }
        if((p1_cur != nullptr) && (p2_cur != nullptr)) {
            exp_cur = p1_cur->exp;
            sum = p1_cur->coeff + p2_cur->coeff;
            p1_cur = p1_cur->next;
            p2_cur = p2_cur->next;
        }
        if((exp_cur != padd_cur->exp) || (sum != padd_cur->coeff)) {
            equal = false;
        }
        padd_cur = padd_cur->next;
    }
    if((p1_cur == nullptr && p2_cur == nullptr) && padd_cur != nullptr) {
        equal = false;
    }
    if(equal) {
        cout << "success" << endl;
    }
    else
    {
        cout << "failure" << endl;
    }   
}

void polynomial::get(polynomial p_1, polynomial p_get) {
    bool equal = true;
    node *p1_cur = new node;
    node *pget_cur = new node;
    p1_cur = p_1.head;
    pget_cur = p_get.head;

    while((p1_cur != nullptr) || (pget_cur != nullptr)) {
        if((p1_cur != nullptr) && (pget_cur != nullptr)) {
            if((p1_cur->coeff) != (pget_cur->coeff)) {
                equal = false;
            }
        }
        else if((p1_cur == nullptr) && (pget_cur != nullptr)) {
            equal = false;
        }
        else if((pget_cur == nullptr) && (p1_cur != nullptr)) {
            equal = false;
        }
        p1_cur = p1_cur->next;
        pget_cur = pget_cur->next;
    }
    if(equal == true) {
        cout << "success" << endl;
    }
    else
    {
        cout << "failure" << endl;
    }   

}

void polynomial::eval(polynomial p_1, double x, double val) {
    int expo;
    double sum;
    double coef;
    node *p1_cur = new node;
    p1_cur = p_1.head;
    while(p1_cur != nullptr) {
        expo = p1_cur->exp;
        coef = p1_cur->coeff;
        sum += coef * (pow(x, expo));
        p1_cur = p1_cur->next;
    }
    if(sum != val) {
        cout << "failure" << endl;
    }
    else {
        cout << "success" << endl;
    }
}

// void polynomial::mult(polynomial p_1, polynomial p_2, polynomial mult) {
//     polynomial temp;
//     node *p1_cur = new node;
//     node *p2_cur = new node;
//     p1_cur = p_1.head;
//     p2_cur = p_1.head;

//     while(p1_cur != nullptr) {
//         while(p2_cur != nullptr) {
//             int pow = p1_cur->exp + p2_cur->exp;
//             double coef = p1_cur->coeff * p2_cur->coeff;
//             temp.addNode(pow, coef);
//             p2_cur = p2_cur->next;
//         }
//         p2_cur = p_2.head;
//         p1_cur = p1_cur->next;
//     }

//     p_1.compare(temp, mult);

// }

// void polynomial::compare(polynomial p, polynomial multiply) {
//     node *p_cur = new node;
//     node *p_mult = new node;
//     p_cur = p.head;
//     p_mult = multiply.head;

//     while(p_cur != nullptr && p_cur->next != nullptr) {

//     }

// }