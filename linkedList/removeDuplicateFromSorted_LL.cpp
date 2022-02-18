#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void removeDuplicates(node * & head){
    if(head == NULL)return;
    if(head->next == NULL)return ;
    node * curr = head;
    while(curr!=NULL){
        if(curr->next != NULL && curr->data == curr->next->data){
            node * pointertonext = curr->next->next;
            delete(curr->next);
            curr->next = pointertonext;
        }
        else curr=curr->next;
    }

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 5);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    display(head);
    
    removeDuplicates(head);
    display(head);

    return 0;
}
