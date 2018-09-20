//46������ȫ���У��Ӹ������ĵ�һ�����κ�ÿһλ���������������� �����������DFS
//1�����ظ�����ȫ���� �ݹ�ʵ��
void Swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
//K��ʾ��ǰѡȡ�ڼ�������n��ʾһ���м�����
void AllRange(char* str, int start, int end)
{
    if(start == end)
    {
       // static int count = 1;
        //printf("��%d��ȫ����:",count++);
        printf("%s\n",str);
    }//if
    else
    {
        for(int i = start; i <= end; ++i)
        {
            Swap(str + start, str + i);
            AllRange(srt,start + 1,end);
            Swap(str + start, str + i);//�ٽ���һ�α�Ϊԭ�����ַ���

        }//for
    }//else
}
void Func(char* str)
{
    AllRange(str,0,strlen(str)-1);
}
//------------------------------------------------------------------
//2�����ظ�����ʱ��ȫ����ȥ�ص�ȫ���о��Ǵӵ�һ��������ÿ�����ֱ�����������ظ����ֵ����ֽ���
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
//3��ȫ���еķǵݹ�ʵ��
//ð����������
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
void PrintArray(int arr[],int length) {  //��ӡ���飬���ڲ鿴����Ч��
    printf("��%2d������Ϊ��[",++cnt);
    for(int i=0; i<length; i++) {
        if(i==length-1)
            printf("%d]\n",arr[i]);
        else
            printf("%d ,",arr[i]);
    }
}
void reverse(int arr[],int from, int to) {//��ת[from,to]
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
    for(i = n-2; i >= 0; i--) { //һ���ң�
        if(A[i+1] > A[i])
            break;
    }
    if(i < 0)
        return false;//�Ҳ���������false
    m = i;
    i++;
    for( j=n-1; j>i; j--) {     //������
        if(A[j] >= A[m])
            break;
    }
    swap(&A[j],&A[m]);          //��������
    reverse(A,m+1,n-1);         //�ġ���ת
    return true;
}

void Full_Permutation(int A[],int n) {
    if(A==NULL || n<=0) return; //��׳�Լ��
    BubbleSort(A,n);            //ð����������
    do {
        PrintArray(A,n);
    } while(Next_Permutation(A,n));//����Ƿ�����һ���ֵ�������
}

//-------------------------------------------------------------------
//4��ȫ���  ����Ԫ��ԭ���У�a,b,c �������� 1 ��ʾȡ��Ԫ�أ�0 ��ʾ��ȡ
void Combination(char* str)
{
    if(str==NULL)
        return;
    int len = strlen(str);
    int n = 1<<len; //n��Ϊȫ��ϵĸ���
    //�� 1 ѭ���� 2^len -1
    for(itn i = 1; i < n; ++i)
    {
        for(int j=0;j<len;j++)
        {
            int temp = i;
            //��Ӧλ��Ϊ1���������Ӧ���ַ�
            if(temp & (1<<j))
            {
                printf("%c",*(str+j));
            }
        }
        printf("\n");
    }
}