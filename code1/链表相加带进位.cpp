/*2、链表
 * 两个链表中对应位置相加 组合为新链表 注意进位  每个结点只保存一位数
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8*/
ListNode* addTwoNumber(ListNode* list1, ListNode* list2)
{
    ListNode *resList = new ListNode(-1);
    ListNode *currentNode = resList;
    int carry = 0;
    //int sum = 0;
    while(list1 || list2)
    {
        int num1 = list1 ? list1 -> value : 0;
        int num2 = list2 ? list2 -> value : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        currentNode -> next = new ListNode(sum % 10);
        currentNode = currentNode -> next;
        if(list1)
            list1 = list1 -> next;
        if(list2)
            list2 = list2 -> next;
    }
    if(carry)
        currentNode -> next = new ListNode(1);
    return resList -> next;
}