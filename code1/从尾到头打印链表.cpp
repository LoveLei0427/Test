
//5����β��ͷ��ӡ����
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