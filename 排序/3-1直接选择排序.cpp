/*�ڵ�i��ѡ�������ͨ��n-i�μ�ֵ��Ƚϣ�
��n-i+1����¼��ѡ����ֵ��С�ļ�¼��
���͵�i(1<=i<=n-1)����¼����(i = 1,2,3,..n)
*/
//�±�Ϊ��洢0ֵ �ڱ�����
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
			swap(array[min],array[i]);//swap��������������������λ��
		}
    }
}