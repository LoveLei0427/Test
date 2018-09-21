//二分查找实现一个有序(字典序)字符串数组arr中 值等于字符串v的元素的序号 有多个返回最大的
int BinarySearch(char** arr,int begin,int end,char*v)
{
    //arr相当于二维数组，里面存储的是char*类型变量的地址
    int minIndex = begin;
    int maxIndex = end;
    int midIndex;
    //二分查找循环结束条件mid
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