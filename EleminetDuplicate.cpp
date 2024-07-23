#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
Node *removeDuplicates(Node *head)
{
   
    if (head == NULL)
    {
        return head;
    }

    Node *h2 = head->next;
    Node *h1 = head;

    while (h2)
    {
        if (h2->data == h1->data)
        {
            if (h2->next == NULL)
            {
                h1->next = NULL;
            }
           h2 = h2->next;
        }
        else
        {
           h1->next =h2;
            h1 = h2;
            h2 = h2->next;
        }
    }

    return head;
}
void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
}
int main()
{
    Node *head=takeInput();
    print(head);
   removeDuplicates(head);
   cout<<endl;
   print(head);
    
}
