#include<iostream>
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


 void InsertAtHead(node* &head , int val)
 {
    node* n = new node(val);

    if(head == NULL)
    {
        n->next = n;  // because it is CLL
        head =n;
        return ;
    }


  
    node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next =n;
    n->next = head;
    head =n;
    
 }



void InsertionAtTail(node* &head, int val)
{

    if(head == NULL)
    {
        InsertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    
    node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;

}

void DeleteAtHead(node* &head)
{
    node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }

    node* todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
    
}



void Deletion(node* &head , int pos)
{
    if(pos == 1)
    { 
        DeleteAtHead(head);
        return ;
    }


    node* temp =head;
    int count =1;

    while(count != pos-1)
    {
        temp = temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
    
    delete todelete;
}



void display(node* head)
{

    node* temp =head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
    
}
int main()
{
    node* head = NULL;
    int arr[]= {1,2,3,4,5};
    for(int i=0; i<5; i++)
    {
        InsertionAtTail(head, arr[i]);
    }
    display(head);

    Deletion(head, 5);
    display(head);

    Deletion(head, 1); // to check pos 1 is deleting or not
    display(head);

}