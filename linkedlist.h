
#pragma once
#include <QMainWindow>
#include <stdio.h>
#include <iostream>
using namespace std;
struct node{

    QString val;
    node* next,*prev;
};

class Linkedlist{

    public:
    node *head;
    int size;

    ~Linkedlist(){
        node* ptr=head;
        for(int i=0;i<size;i++){
            head=head->next;
            delete ptr;
            ptr=head;
        }
        size=0;

    }
    Linkedlist();


    node* add_node(QString n);

    void displ();

    void del(node* n);





};
