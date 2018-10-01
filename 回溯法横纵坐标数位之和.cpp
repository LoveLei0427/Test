/*m�к�n�еķ��񡣴�����0,0��ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ����ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ����kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ�����*/
int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || row <= 0 || cols <=0)
        return 0;
    bool *visited = new bool[rows * cols];
    for(int i = 0; i < rows*cols; ++i)
    {
        visited[i] = false;
    }
    int rowSum = 0;
    int colSum = 0;
    int row = 0,col = 0;
    int result = movingCountCore(threshold, rows, cols, 0, 0, visited);

    delete[] visited;
    return false;

}
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    int rowSum = 0, colSum = 0;
    int count = 0;
    if(check(threshold, rows, cols, row, col, visited))
    {
        visited[row * cols + col] = true;
        //count += 1;
        count = 1 + movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                movingCountCore(threshold, rows, cols, row, col - 1, visited) +
                movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                movingCountCore(threshold, rows, cols, row + 1, col, visited);

    }
    return count;
}
bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    if(row >=0 && row < rows && col >=0 && col < cols && (getSum(row) + getSum(col) < threshold) && !visited[row * cols + col])
    {
        return true;
    }
    return false;
}
int getSum(int number)
{
    int sum = 0;
    while(number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}