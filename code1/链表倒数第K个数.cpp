//15、单向链表中的倒数第K个结点
//
Node* Print_reciprocal_Kth_Node(Node* head, int k)
{
    if(head==NULL || k < 1)
        return NULL;
    int count = k;
    Node *fast;
    Node *slow;
    fast = slow = head;
    for(;i > 0 && fast !=  NULL; --i)
    {
        fast = fast -> next;
    }
    while(i > 0)
        return NULL;
    if(fast != NULL)
    {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}