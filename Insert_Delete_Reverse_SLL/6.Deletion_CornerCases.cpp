//deletion by taking care of corner cases
//  1)  what if there is no node to delete ?
//  2)  what if there is only one node to delete (head node) ?


#include<iostream>  // Linked List     deletion with corner cases
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


void deleteAtMiddle(node* &head, int val)  //same code with corner cases
 {

    if(head == NULL)  //if there is no node to delete  
    {
        return;
    }

    if(head ->next == NULL)  // if there is only one node existing (head)
    {
       deleteAtHead(head);
       return;
    }


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
    display(head);

    // deletion at 2nd node
    deleteAtMiddle(head , 2);
    display(head);             // now only one node existing




    //only one node existing..that node deleting...here corner case will work
    deleteAtMiddle(head, 1);
    display(head);

   



    return 0;
}