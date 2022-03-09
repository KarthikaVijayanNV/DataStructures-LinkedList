#include<iostream>  // Even after Odd
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


void EvenafterOdd(node* &head)
{
    node* odd = head;
    node* even = head->next;
    node* evenStart =even;

    while(odd->next != NULL  && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;

   // if(odd->next == NULL)    // no need to use this loop....does'nt make any change in the output
    //{
        //even->next =  NULL;
    //}
}







int main()
{
    node* head= NULL;
    
    int arr[] ={2,1,3,5,6,4,7};
    for(int i=0; i<7; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);

    EvenafterOdd(head);
    display(head);


     
    










    return 0;
}