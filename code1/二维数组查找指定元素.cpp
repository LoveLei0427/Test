//3�����а��е�����ά���� ����ָ��Ԫ��
bool Find(int *matrix, int rows, int cols, int numbers)
{
    bool findresult = false;
    if(matrix!=NULL && rows>0 && cols >0)
    {
        int row = 0;
        int col = cols-1;
        while(row<rows && col>=0)
        {
            if(matrix[row*cols+col]==numbers)
            {
                findresult = true;
                break;
            }
            else if(matrix[row*cols+col]>numbers)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
    }
    return findresult;
}