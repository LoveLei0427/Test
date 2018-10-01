/*
ͨ��һ�����򽫼�¼�ָ�������֣�����һ���ּ�¼�Ĺؼ��־�����һ���ּ�¼�Ĺؼ���С
��ô�ݹ���������ּ�¼�Ĺؼ������� �Դﵽ�������������Ŀ��
*/
//low��ʼΪ�����±�0 high��ʼΪ���鳤��
int getPartion(int array[], int low, int high)
{
    int key = array[low];
    while (low < high)
    {
        while (low < high && key <= array[high]) //���array[high]���ڼ�ֵ����ô����Ӧ���ڼ�ֵ�ұ�
            high--;  //��˽�high�±���ǰ�ƶ���ֱ���ҵ��ȼ�ֵС��ֵ����ʱ����������ֵ
        swap(array[low], array[high]);

        while (low < high && key >= array[low])
            low++;
        swap(array[low], array[high]);
    }
    return low;//����keyֵ���±�
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