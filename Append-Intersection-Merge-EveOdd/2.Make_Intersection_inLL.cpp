#include<iostream>  // Linked List  making intersection in LL
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



void MakeIntersection(node* &head1 ,node* &head2 , int pos)
{
   node* temp1 = head1;
   pos--;
   while(pos--)
   {
       temp1= temp1->next;
   }


   /*  below code also works
   int count = 1;
    while(temp1->next != NULL && count != pos)
    {
        temp1 = temp1->next;
        count++;
    }

    */



   node* temp2 = head2;
   while(temp2->next != NULL)
   {
       temp2 = temp2 ->next;
   }

   temp2->next = temp1;   //intersection is made at given position
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
    node* head1 = NULL;
    node* head2 = NULL;
    int arr[] ={1,2,3,4,5,6};
    for(int i=0; i<6; i++)
    {
        insertAtTail(head1, arr[i]);
    }
    display(head1);     //passed value to head1


    insertAtTail(head2 ,9);
    insertAtTail(head2, 10);
    display(head2);    //passed value to head to also


//Making intersection  
   MakeIntersection(head1 ,head2, 5);

   //now you display both the LL
   display(head1); 
   display(head2);     // intesection is visible at output








    return 0;
}