//46、数字全排列（从该组数的第一个依次和每一位交换（包括本身）） 深度优先搜索DFS
//1、无重复数字全排列 递归实现
void Swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
//K表示当前选取第几个数，n表示一共有几个数
void AllRange(char* str, int start, int end)
{
    if(start == end)
    {
       // static int count = 1;
        //printf("第%d个全排列:",count++);
        printf("%s\n",str);
    }//if
    else
    {
        for(int i = start; i <= end; ++i)
        {
            Swap(str + start, str + i);
            AllRange(srt,start + 1,end);
            Swap(str + start, str + i);//再交换一次变为原来的字符串

        }//for
    }//else
}
void Func(char* str)
{
    AllRange(str,0,strlen(str)-1);
}
//------------------------------------------------------------------
//2、有重复数字时的全排列去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换
bool isSwap(char* str, int start, int end)
{
    for(;start<end;start++)
    {
        if(str[start]==str[end])
            return false;
    }
    return true;
}
void AllRange2(char* str, int start, int end)
{
    if(start == end)
        printf("%s",str);
    else
    {
        for(int i = start; i <= end - 1;++i)
        {
            if(isSwap(str,start,i))
            {
                Swap(&str[start],&start[i]);
                AllRange2(str,start+1,end);
                Swap(&str[start],&str[i]);
            }
        }
    }
}
//--------------------------------------------------------------
//3、全排列的非递归实现
//冒泡升序排序
void BubbleSort(int arr[],int length) {
    int tmp;
    int i,j;
    for(i=length-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(arr[j] > arr[j+1]) {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}
void PrintArray(int arr[],int length) {  //打印数组，用于查看排序效果
    printf("第%2d种排列为：[",++cnt);
    for(int i=0; i<length; i++) {
        if(i==length-1)
            printf("%d]\n",arr[i]);
        else
            printf("%d ,",arr[i]);
    }
}
void reverse(int arr[],int from, int to) {//反转[from,to]
    while(from < to) {
        char tmp = arr[from];
        arr[from]= arr[to];
        arr[to] = tmp;
        from ++;
        to --;
    }
}
bool Next_Permutation(int A[], int n) {
    int i,j,m;
    for(i = n-2; i >= 0; i--) { //一、找：
        if(A[i+1] > A[i])
            break;
    }
    if(i < 0)
        return false;//找不到，返回false
    m = i;
    i++;
    for( j=n-1; j>i; j--) {     //二、找
        if(A[j] >= A[m])
            break;
    }
    swap(&A[j],&A[m]);          //三、交换
    reverse(A,m+1,n-1);         //四、反转
    return true;
}

void Full_Permutation(int A[],int n) {
    if(A==NULL || n<=0) return; //健壮性检测
    BubbleSort(A,n);            //冒泡排序（升序）
    do {
        PrintArray(A,n);
    } while(Next_Permutation(A,n));//检测是否还有下一个字典序排列
}

//-------------------------------------------------------------------
//4、全组合  假设元素原本有：a,b,c 三个，则 1 表示取该元素，0 表示不取
void Combination(char* str)
{
    if(str==NULL)
        return;
    int len = strlen(str);
    int n = 1<<len; //n即为全组合的个数
    //从 1 循环到 2^len -1
    for(itn i = 1; i < n; ++i)
    {
        for(int j=0;j<len;j++)
        {
            int temp = i;
            //对应位上为1，则输出对应的字符
            if(temp & (1<<j))
            {
                printf("%c",*(str+j));
            }
        }
        printf("\n");
    }
}