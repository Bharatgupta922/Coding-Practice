// in this you do not have the head pointer 
//complete this

void deleteNode(Node *node)
{
   // Your code here
   node->data = node->next->data;
   node->next = node->next->next;
   
}