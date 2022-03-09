#include<iostream>  // Linked List  Making and detecting a  cycle
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


void MakeAcycle(node* &head , int pos)
{
    node* temp = head;
    node* startNode;

    int count =1;

    while(temp->next != NULL)
    {
        if(count == pos)
        {
            startNode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startNode;

}



bool detectCycle(node* &head)
{
    node* slow = head;
    node* fast = head;


    while(fast  != NULL  &&  fast->next != NULL )
    {

       slow = slow->next;
       fast = fast->next->next;


        if(fast == slow)
        {
            return true;  //cycle is there
        }
        
    }

    return false; // no cycle
}







int main()
{
    node* head = NULL;
    insertAtTail(head , 1);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 6);

    display(head);


    MakeAcycle(head , 3);  //here u made a cycle 
    // display(head);         // it will give you an infinite result...because it's a cycle


   cout<<detectCycle(head)<<endl;

    




    return 0;
}