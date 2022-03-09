#include<iostream>  // Linked List     deleting a  node from middle
using namespace std;

class node
{
    public:
    int data;
    node* next;

    
    node(int val)
    {
        data =val;
        next = NULL;
    }
};



void  insertAtTail(node* &head , int val)
    {
       node* n =   new node(val);


       if(head == NULL)
        {
           head =n;
           return ;
        }


       node* temp = head;
       while(temp->next != NULL)
       {
           temp= temp->next;
       }

       temp->next = n;
    }



    void display(node* head)

    {
        node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<" NULL"<<endl;
    }


 void deleteAtMiddle(node* &head, int val)
 {
    node* temp = head;
    while(temp -> next -> data != val)
    {
        temp = temp->next;
    }

    node *todelete  =temp -> next;   // copying the deleting node
    temp->next = temp-> next -> next;

    delete todelete;
 }






int main()
{
    //Insertion operation
    node* head = NULL;
    insertAtTail(head , 1);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    display(head);

    //deletion at middle
    deleteAtMiddle(head , 3);
    display(head);


   



    return 0;
}