#include<iostream>  // Linked List  find intersection in LL
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

   node* temp2 = head2;
   while(temp2->next != NULL)
   {
       temp2 = temp2 ->next;
   }

   temp2->next = temp1;   //intersection is made at given position
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



 int FindIntersection(node* &head1 , node* &head2)
 {
    int l1 = lengthofLL(head1);
    int l2 = lengthofLL(head2);
    int diff =0;

    node* ptr1;  // points to largest LL
    node* ptr2;  // smallest LL
    if(l1>l2)  
    {
        diff = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        diff = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }


    while(diff)
    {
        ptr1 = ptr1 ->next;
        if(ptr1 == NULL)
        {
            return -1;
        }
        diff--;
    }


    while(ptr1 != NULL && ptr2 != NULL)
    {
      if(ptr1 == ptr2)   // at intersection point
      {
        return ptr1->data;  // if ptr2 ->data.....both are same....because intersection value is same
      }
        ptr1= ptr1->next;
        ptr2 =ptr2->next;
    }


    return -1;

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

   cout<<FindIntersection(head1, head2);








    return 0;
}