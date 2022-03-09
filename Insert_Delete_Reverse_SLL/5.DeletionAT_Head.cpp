#include<iostream>  // Linked List     deleting a  node from head
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


 
void deleteAtHead(node* &head)  // no need to pass value
{
    node* todelete = head;  //copying the head node
    head =  head->next;


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

    //deletion at head
    deleteAtHead(head);
    display(head);


   



    return 0;
}