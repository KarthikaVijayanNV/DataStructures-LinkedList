#include<iostream>  //insert at head
using namespace std;

class node
{
    public:

    int data;
    node* next;
    node* prev;

    
    node(int val)
    {
        data = val;
        next= NULL;
        prev = NULL;
    }
};


void InsertAtHead(node* &head, int val)
{
    node* n = new node(val);

    n->next = head;
    head->prev = n;
    head = n;
}



void InsertAtTail(node* &head , int val)
{
    
    node* n = new node(val);

    if(head == NULL)
    {
        head = n;   
        return;
    }


    node* temp = head;
    while(temp->next != NULL)
    {
        temp= temp-> next;
    }

    temp->next =n;
    n->prev = temp;

}



void deleteAtHead(node* &head)
{
    node* todelete = head;

    head = head->next;
    head->prev = NULL;

    delete todelete;
}


void deleteAtMiddle(node* &head ,int pos)
{
    // corner case   2) what if you are deleting node at pos ==1 means...the head node
    if(pos == 1)
    {   
        deleteAtHead(head);
        return;
    }


    node* temp = head;
    int count =1;

    while(temp != NULL  && count<pos)
    {

        temp =temp->next;
        count ++;
    }

    temp->prev->next = temp ->next;             // 2corner cases     1) what if u are deleting the last node
    if(temp->next != NULL)
    {
       temp->next->prev = temp ->prev;
    } 

    delete temp;
}




void display(node* head)
{
    node* temp =head;
    while(temp != NULL)
    {
        cout<<temp->data<<" - ";
        temp = temp->next;
    }
    cout<<" NULL"<<endl;
}




int main()
{
    node* head =NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    display(head);


   //InsertAtHead(head, 5);
   //display(head);

   deleteAtMiddle(head, 3); // positon is 3
   display(head);

   deleteAtMiddle(head , 1); // pos is 1..means deleting head node;
   display(head);

}