//两个链表的第一个公共结点
/*方法一、先让长的链表先走长度差个步长，然后遍历
 * 方法二、两个链表的第一个公共结点之后的值均相等，可以用两个辅助栈将链表中的值分别存入
 * 然后两个栈同时出栈 最后一个相等的值即为公共结点的值
*/
int GetLength(ListNode *head)
{
    int length = 0;
    ListNode* newNode = head;
    while(newNode!=NULL)
    {
        ++length;
        newNode = newNode -> next;
    }
    return length;
}
ListNode* GetFirstNode(ListNode *List1,ListNode* L2)
{
    if(List1==NULL||List2==NULL)
        return NULL;
    int length1 = GetLength(List1);
    int length2 = GetLength(List2);
    int deltaLen = length1 - length2;

    ListNode* pLong = List1;
    ListNode* pShort = List2;
    if(deltaLen<0)
    {
        pLong = List2;
        pShort = List1;
        deltaLen = -deltaLen;
    }
    for(int i = 0; i < deltaLen; ++i)
    {
        pLong = pLong -> next;
    }
    while(pLong->next!=NULL && pShort->next != NULL & pLong!=pShort)
    {
        pLong = pLong->next;
        pShort = pShort->next;
    }
    ListNode* resNode = pLong;
    return resNode;
}