/*m*n的矩阵中从左上角到右下角只能向下或者向右移动，问路径所有元素的和最大能到多少*/
int getMaxRes(int *arr, int rows, int cols)
{
    if(arr == nullptr || rows < 1 || cols < 1)
        return NULL;
    int **maxValue = new int*[rows];
    for(int i = 0; i < cols; ++i)
    {
        maxValue[i] = new int[cols];
    }
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int upvar = 0;
            int leftvar = 0;
            if(i > 0)
                upvar = maxValue[i -1][j];
            if(j >0)
                leftvar = maxValue[i][j - 1];
            maxValue = max(upvar,leftvar) + arr[i * cols + j];
        }
    }
    int resultMaxValue = maxValue[rows - 1][cols -1];
    for(int i = 0; i < rows; ++i)
    {
        delete[] maxValue[i];
    }
    delete[] maxValue;
    return resultMaxValue;
}