
// 递归法 
/* 将src[s..t]归并排序为TR1[s..t] */
void MSort(int src[],int dst[],int s, int t)
{
	int m;
	int dst2[MAXSIZE+1];
	if(s==t)
		dst[s]=src[s];
	else
	{
		m=(s+t)/2;				/* 将src[s..t]平分为src[s..m]和SR[m+1..t] */
		MSort(src,dst2,s,m);		/* 递归地将src[s..m]归并为有序的dst[s..m] */
		MSort(src,dst2,m+1,t);	/* 递归地将SR[m+1..t]归并为有序的dst[m+1..t] */
		Merge(src,dst2,s,m,t);	/* 将dst[s..m]和dst[m+1..t]归并到[s..t] */
	}
}
/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(int src[],int dst[],int start,int part,int end)
{	//将src[start:part] src[part+1:end]合并到dst[start:n]中
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
			dst[k+l]=src[start+l];		/* 将剩余的src[i..m]复制到dst */
	}
	if(j<=end)
	{
		for(l=0;l<=end-j;l++)
			dst[k+l]=src[j+l];		/* 将剩余的Ssrc[j..n]复制到dst */
	}
}
//非递归法
void MergeSort2(SqList *L)
{
	int* saveSpace=(int*)malloc(L->length * sizeof(int));/* 申请额外空间 */
    int len=1;
	while(len<L->length)
	{
		MergePass(L->r,saveSpace,len,L->length);
		len=2*len;/* 子序列长度加倍 */
		MergePass(saveSpace,L->r,len,L->length);
		len=2*len;/* 子序列长度加倍 */       
	}
}
void MergePass(int src[],int dst[],int low,int high)
{
	int i=1;
	int j;
	while(i <= high-2*low+1)
	{/* 两两归并 */
		Merge(src,dst,i,i+low-1,i+2*low-1); //第一次将1 2两个记录归并到dst中
		i=i+2*low;        //循环3 4和5 6 及 7 8 条记录
	}
	/* 归并最后两个序列 */
	if(i<high-low+1) 
		Merge(src,dst,i,i+low-1,high);
	/* 若最后只剩下单个子序列 */
	else 
		for(j =i;j <= high;j++)
			dst[j] = src[j];
}

