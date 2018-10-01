
// �ݹ鷨 
/* ��src[s..t]�鲢����ΪTR1[s..t] */
void MSort(int src[],int dst[],int s, int t)
{
	int m;
	int dst2[MAXSIZE+1];
	if(s==t)
		dst[s]=src[s];
	else
	{
		m=(s+t)/2;				/* ��src[s..t]ƽ��Ϊsrc[s..m]��SR[m+1..t] */
		MSort(src,dst2,s,m);		/* �ݹ�ؽ�src[s..m]�鲢Ϊ�����dst[s..m] */
		MSort(src,dst2,m+1,t);	/* �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����dst[m+1..t] */
		Merge(src,dst2,s,m,t);	/* ��dst[s..m]��dst[m+1..t]�鲢��[s..t] */
	}
}
/* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
void Merge(int src[],int dst[],int start,int part,int end)
{	//��src[start:part] src[part+1:end]�ϲ���dst[start:n]��
	int j,k,l;
	for(j=part+1,k=start;start<=part && j<=end;k++)	
	{
		if (src[start]<src[j])
			dst[k]=src[start++];
		else
			dst[k]=src[j++];
	}
	if(start<=part)
	{
		for(l=0;l<=part-start;l++)
			dst[k+l]=src[start+l];		/* ��ʣ���src[i..m]���Ƶ�dst */
	}
	if(j<=end)
	{
		for(l=0;l<=end-j;l++)
			dst[k+l]=src[j+l];		/* ��ʣ���Ssrc[j..n]���Ƶ�dst */
	}
}
//�ǵݹ鷨
void MergeSort2(SqList *L)
{
	int* saveSpace=(int*)malloc(L->length * sizeof(int));/* �������ռ� */
    int len=1;
	while(len<L->length)
	{
		MergePass(L->r,saveSpace,len,L->length);
		len=2*len;/* �����г��ȼӱ� */
		MergePass(saveSpace,L->r,len,L->length);
		len=2*len;/* �����г��ȼӱ� */       
	}
}
void MergePass(int src[],int dst[],int low,int high)
{
	int i=1;
	int j;
	while(i <= high-2*low+1)
	{/* �����鲢 */
		Merge(src,dst,i,i+low-1,i+2*low-1); //��һ�ν�1 2������¼�鲢��dst��
		i=i+2*low;        //ѭ��3 4��5 6 �� 7 8 ����¼
	}
	/* �鲢����������� */
	if(i<high-low+1) 
		Merge(src,dst,i,i+low-1,high);
	/* �����ֻʣ�µ��������� */
	else 
		for(j =i;j <= high;j++)
			dst[j] = src[j];
}

