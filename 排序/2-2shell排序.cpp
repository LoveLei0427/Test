/*
针对直接插入排序算法的改进。该方法又称缩小增量排序
对于n个待排序的数列，取一个小于n的整数gap(步长)将待排序元素分成若干个组子序列，
所有距离为gap的倍数的记录放在同一个组中；
然后，对各组内的元素进行直接插入排序。 这一趟排序完成之后，每一个组的元素都是有序的。
然后减小gap的值，并重复执行上述的分组和排序。
重复这样的操作，当gap=1时，整个数列就是有序的。
*/

//写法一、
void shellsort(int a[],int left,int right)
{
	int d = (left+right)>>1;//d步长 
	while(d>0)
	{
		for(int i = 0; i<right-d+1;i++)
		{
			if(a[i]>a[i+d])
			{
				int temp = a[i+d];
				a[i+d] = a[i];
				a[i] = temp;
		    }
            //d=d/2;//步长改变
			d=d>>1; 
		}
	}
}
//写法二、
void inssort(int *a,int length,int step)//插入排序的特殊化，最后一个参数是间隔值，incr=1时，就是插入排序。
{  
	int i,j;
	for(i=step;i<length;i+=step)
	{
		for(j=i;j>=step;j-=step)
		{
			if(a[j]<a[j-step])
				swap(a[j],a[j-step]);
		}
	}
}
void Shell_Sort(int *a,int length)//shell排序
{
	int step,j;
	for(step=length/2;step>2;step/=2)
	{
		for(j=0;j<step;j++)
		{
			inssort(&a[j],length-j,step);//分别传入a[0]-a[7]的地址给指针
		}
	}
	inssort(a,length,1);//对有序的队列，最后做插入排序
}