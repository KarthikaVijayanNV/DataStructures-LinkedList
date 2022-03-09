#include<iostream>  //insert at Tail
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


}