//�ҳ�������ֻ����һ�ε�������(��ͬ�����������Ϊ0)
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
    *num1 = *num2 = 0;//0���κ��������ڱ���(һ�����������0)
    for(int i = 0; i < size; ++i)
    {
        //��ͬ������������������ͬ�����н��м��
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
//�ҳ�ÿ�����е����ڼ�λ��1��λn
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
//������Ԫ�ذ�n��Ϊ������ ��һ���ֵ�����nΪ��0 ���൹����nλ��1
int groupByFirst(int num, int carry)
{
    num = num >> carry;
    return (num & 1);
}