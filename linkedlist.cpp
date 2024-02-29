//
//  Linkedlist.cpp
//  sorting
//
//  Created by mohamed on 17/11/2022.
//

#include "linkedlist.h"


void Linkedlist::del(node* n){
    int index=0;
    node* ptr=head;
 do{
       if(ptr==n){
           break;
       } else{
           index++;
           ptr=ptr->next;
       }
    }while(ptr!=head);
    if(index==0&&size==1){
        delete head;
        head=NULL;
        size=0;
        return;
    }
    if(index==0&&size>0){
        node*ptr =head;
        head=head->next;
        head->prev=ptr->prev;
        size--;
        delete ptr;

        return;
    }

    if(index>=0||index<size){

        node* ptr=head;
        node* tem;
        for(int i=1;i<index;i++){
            ptr=ptr->next;
        }
        tem=ptr->next;
        ptr->next=tem->next;
        ptr->next->prev=ptr;
        delete tem;

        size--;
    }

}

node* Linkedlist::add_node(QString n){
    node* ptr=new node();
    ptr->val=n;
    if(head==NULL){
        head=ptr;
        head->next=head->prev=head;

        size++;
    }
    else{
        node* t=head;
        while(t->next!=head){
            t=t->next;
        }
        t->next=ptr;
        ptr->prev=t;
        ptr->next=head;
        head->prev=ptr;

        size++;
    }
    return ptr;
}
Linkedlist::Linkedlist(){
    head=NULL;
    size=0;
}
