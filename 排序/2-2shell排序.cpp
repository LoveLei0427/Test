/*
���ֱ�Ӳ��������㷨�ĸĽ����÷����ֳ���С��������
����n������������У�ȡһ��С��n������gap(����)��������Ԫ�طֳ����ɸ��������У�
���о���Ϊgap�ı����ļ�¼����ͬһ�����У�
Ȼ�󣬶Ը����ڵ�Ԫ�ؽ���ֱ�Ӳ������� ��һ���������֮��ÿһ�����Ԫ�ض�������ġ�
Ȼ���Сgap��ֵ�����ظ�ִ�������ķ��������
�ظ������Ĳ�������gap=1ʱ���������о�������ġ�
*/

//д��һ��
void shellsort(int a[],int left,int right)
{
	int d = (left+right)>>1;//d���� 
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
            //d=d/2;//�����ı�
			d=d>>1; 
		}
	}
}
//д������
void inssort(int *a,int length,int step)//������������⻯�����һ�������Ǽ��ֵ��incr=1ʱ�����ǲ�������
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
void Shell_Sort(int *a,int length)//shell����
{
	int step,j;
	for(step=length/2;step>2;step/=2)
	{
		for(j=0;j<step;j++)
		{
			inssort(&a[j],length-j,step);//�ֱ���a[0]-a[7]�ĵ�ַ��ָ��
		}
	}
	inssort(a,length,1);//������Ķ��У��������������
}