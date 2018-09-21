//���ֲ���ʵ��һ������(�ֵ���)�ַ�������arr�� ֵ�����ַ���v��Ԫ�ص���� �ж����������
int BinarySearch(char** arr,int begin,int end,char*v)
{
    //arr�൱�ڶ�ά���飬����洢����char*���ͱ����ĵ�ַ
    int minIndex = begin;
    int maxIndex = end;
    int midIndex;
    //���ֲ���ѭ����������mid
    while(minIndex < maxIndex - 1)
    {
        midIndex = minIndex + (maxIndex - minIndex) / 2;
        if(strcmp(arr[minIndex],v) <= 0)
        {
            minIndex = midIndex;
        }
        else
        {
            maxIndex = midIndex;
        }
    }
    if(!strcmp(arr[maxIndex],v))
        return maxIndex;
    else if(!strcmp(arr[minIndex],v))
        return minIndex;
    else 
        return -1;
}