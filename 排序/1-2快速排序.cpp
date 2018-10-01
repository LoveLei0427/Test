/*
通过一趟排序将记录分割成两部分，其中一部分记录的关键字均比另一部分记录的关键字小
那么递归对这两部分记录的关键字排序 以达到整个序列有序的目的
*/
//low开始为数组下标0 high开始为数组长度
int getPartion(int array[], int low, int high)
{
    int key = array[low];
    while (low < high)
    {
        while (low < high && key <= array[high]) //如果array[high]大于键值，那么本就应该在键值右边
            high--;  //因此将high下标向前移动，直至找到比键值小的值，此时交换这两个值
        swap(array[low], array[high]);

        while (low < high && key >= array[low])
            low++;
        swap(array[low], array[high]);
    }
    return low;//返回key值的下标
}

void QuitSort(int a[],int low,int high)
{
    if (low < high)
    {
        int returnLow = getPartion(a, low, high);

        QuitSort(a, low, returnLow - 1);
        QuitSort(a, returnLow + 1, high);
    }
}


void swap(int &a, int &b)
{
    if (a == b)
		return;
    a = a + b;
    b = a - b;
    a = a - b;
}

void print(int  *p, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << p[i] << " ";
    }
}

int main(int argc, char *args[])
{
    int array[10] = { 12, 4, 34, 6, 8, 65, 3, 2, 988, 45 };
    QuitSort(buf, 0, sizeof(array) / sizeof(int)-1);
}