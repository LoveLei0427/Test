/*数组A[0,1,...n-1]构建数组B[0,1,...n-1]
其中B[i]=A[0]*A[1]*...A[i-1]*A[i+1]*...A[n-1]不允许使用除法
定义C[i]=A[0]*A[1]*...A[i-1];D[i]=A[i+1]*...A[n-1]
C[i]=C[i-1]*A[i-1];D[i]=D[i+1]*A[i+1]
B[0] = 1 * A[1] * A[2]...*A[n-1]
B[1] = A[0] * 1 * A[2]...*A[n-1]
B[2] = A[0] * A[1] * 1...*A[n-1]
B[n-1] = 1 * A[1] * A[2]...*1*/
void multiply(const vector<double> &array1, vector<double> &array2)
{
    int array1Size = array1.size();
    int array2Size = array2.size();
    if(array1Size == array2Size && array2Size > 1)
    {
        array2[0] = 1;
        for(int i = 1; i < array1Size; ++i)
        {
            array2[i] = array2[i - 1] * array1[i];
        }
        double temp = 1.0f;
        for(int i = array1Size - 2; i >= 0; --1)
        {
            temp *= array1[i + 1];
            array2[i] *= temp;
        }
    }
}