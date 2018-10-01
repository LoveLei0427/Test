/*在第i次选择操作中通过n-i次键值间比较，
从n-i+1个记录中选出键值最小的记录，
并和第i(1<=i<=n-1)个记录交换(i = 1,2,3,..n)
*/
//下标为零存储0值 哨兵作用
void SelectSort(int array[],int n)
{
	int min,i,j;
	for(i=1;i<=n-1;i++)
	{
		min=i;
		for(j=i+1;j<=n;j++)
		{
			if(array[j]<array[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			swap(array[min],array[i]);//swap函数，将两个参数互换位置
		}
    }
}