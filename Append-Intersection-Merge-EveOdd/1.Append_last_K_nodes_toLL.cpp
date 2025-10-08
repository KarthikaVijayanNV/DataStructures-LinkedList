#include<iostream>  // Linked List  appending last k nodes to the start of LL
using namespace std;  // in    SLL

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



int lengthofLL(node* &head)
{
    int l=0;
    node* temp =head;
    while(temp != NULL)
    {
        l++; 
         temp = temp->next;
        
    }

    return l;  //returning the length of LL
}



 node*  AppenKnodes(node* &head, int k)
 {
    node* newTail;
    node* newHead;
    node* Tailptr =head;

    int l = lengthofLL(head);
    int count =1;
    k =k%l;

    while(Tailptr->next != NULL)
    {
        if(count == l-k)
        {
            newTail = Tailptr;
        }

        if(count == l-k+1)
        {
            newHead = Tailptr;
        }

        Tailptr = Tailptr ->next;
        count++;
    }
    newTail->next = NULL;
    Tailptr->next = head;

    return newHead;
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






int main()
{
    node* head = NULL;
    int arr[] ={1,2,3,4,5,6};
    for(int i=0; i<6; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);


    node* newhead = AppenKnodes(head ,3);
    display(newhead);




    return 0;
}