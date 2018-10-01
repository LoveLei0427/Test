//将一个记录插到已经排好序的有序表中，从而得到一个新的记录数增1的有序表
//适用于少量数据的排序，直接插入排序是比较稳定的一种排序算法

//写法一、
void InsertSort(int arr[],int n){
    for (int i =1;i <= n;++i){
        for(int j = i;j > 0;--j){
            if(arr[j] < arr[j -1]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
//写法二、
void InsertSort(vector<int> &num){
    for(int i = 1;i < num.size();++i){
        for(int j = i;j > 0;--j){
            if(num[j] < num[j - 1]){
                int temp = num[j];
                num[j] = num[j-1];
                num[j-1] = temp;
            }
        }
    }
}

//举例
 7 void insertSort(int arr[], int length)
 8 {
 9     int i, j, key;
10     for (i = 0; i < length; i++){
11         key = arr[i];
12         for (j = i - 1; j >= 0; j--){
13             if (arr[j] > key) {
14                 arr[j + 1] = arr[j];
15             }
16             else
17                 break;
18         }
19         arr[j + 1] = key;
20     }
21 }
int main()
{
	int iArr[] = { 7, 8, 9, 5, 2, 0, 12, 6 };
43  int len = sizeof iArr / sizeof(iArr[0]);
51  insertSort_0(iArr, len);
}