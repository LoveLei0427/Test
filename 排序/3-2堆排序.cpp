/*堆是具有以下性质的完全二叉树：
每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；
每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。
大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2] 
大顶堆：将待排序列构造成一个大顶堆（从上到下，由左到右将每个非叶子结点当做根节点，将其和其子树调整为大顶堆）
序列最大值就是对的根节点
将其与堆数组的末尾元素交换，然后将剩余的n-1个元素重新构造一个堆
反复执行 便能得到一个有序序列
*/
#define MAXSIZE 10000  /* 用于要排序数组个数最大值，可根据需要修改 */
typedef struct
{
	int r[MAXSIZE+1];	/* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
	int length;			/* 用于记录顺序表的长度 */
}SqList;

/*  对顺序表L进行堆排序 */
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  把L中的r构建成一个大根堆 */
		 HeapAdjust(L,i,L->length);

	for(i=L->length;i>1;i--)
	{ 
		 swap(L,1,i); /* 将堆顶记录和当前未经排序子序列的最后一个记录交换 */
		 HeapAdjust(L,1,i-1); /*  将L->r[1..i-1]重新调整为大根堆 */
	}
}

/* 调整L->r[s]的关键字,使L->r[s..m]成为一个大顶堆 */
void HeapAdjust(SqList *L,int s,int m)
{ 
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) /* 沿关键字较大的孩子结点向下筛选 */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; /* j为关键字中较大的记录的下标 */
		if(temp>=L->r[j])
			break; /* rc应插入在位置s上 */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* 插入 */
}

