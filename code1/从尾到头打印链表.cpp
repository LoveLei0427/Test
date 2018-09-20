
//5、从尾到头打印链表
void PrintListEnd2Start(ListNode* head)
{
    if(head!=NULL)
    {
        if(head->next!=NULL)
        {
            PrintListEnd2Start(head);
        }
        print("%d\n",head->value);
    }
}