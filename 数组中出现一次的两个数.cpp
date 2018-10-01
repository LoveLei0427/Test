//找出数组中只出现一次的两个数(相同的两个数异或为0)
void FindResult(int arr[])
{
    int *num1 = NULL;
    int *num2 = NULL;
    int size = sizeof(arr) / sizeof(int);
    if(arr == NULL || arr < 2)
        return ;
    int finalRes = 0;
    for(int i = 0; i < size; ++i)
    {
        finalRes ^= arr[i];
    }
    int carry = FindFirst(finalRes);
    *num1 = *num2 = 0;//0和任何数异或等于本身(一个数异或本身是0)
    for(int i = 0; i < size; ++i)
    {
        //不同的两个数分在两个不同的组中进行检测
        if(a[i],carry)
        {
            *num1 ^= a[i];
        }
        else
        {
            *num2 ^= a[i];
        }
    }
}
//找出每个数中倒数第几位是1计位n
int FindFirst(int num)
{
    int count = 0;
    while((num & 1 ==0) && count <= 8 * sizeof(int))
    {
        num = num >> 2;
        count += 1;
    }
    return count;
}
//将所有元素按n分为两部分 第一部分倒数第n为是0 其余倒数第n位是1
int groupByFirst(int num, int carry)
{
    num = num >> carry;
    return (num & 1);
}