//DFS����
//1����ֹ���������ݷǷ������ߵ�������Χ�߽�֮��  i<0||j<0||i>row_size||j>col_size -- return false
//2�������������������һ�ֽ⣩��cur_index == word_len-1 -- return true
//3����֦�����������������ˣ���visit[i][j] == true����Ԫ�ط��ʹ��� || broad[i][j] != word[cur_index]  -- return false
//4���ݹ鷽����--[i-1][j]  ��--[i+1][j]  ��--[i][j-1]  ��--[i][j+1]
//��ֹ������������������֦������һ����ÿ��dfs�����ж����ڣ��������ǵ�˳��Ҫ���վ��������龳����
//ע��
//    i,j�ֱ��ʾ��ǰ������ά�ռ�**broad���С����±�
//    row_size��col_size�ֱ��ʾ��ά�ռ�**broad�������к�������
//    cur_index ��ʾ��ǰ��������*word���±�
//    bool visit[i][j] ��ʾ��ǰԪ���Ƿ񱻷���
//*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str);
    bool hasPathCore(char* matrix, int rows, int cols,int row, int col, char *str, int &pathLength,bool *visited);
};
bool Solution::hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, int &pathLength, bool *visited)
{
    if(str[pathLength] == '\0')
    {
        return true;
    }
    bool hasPath = false;
    
    if(row >= 0 && 
       row < rows && 
       col >= 0 && 
       col < cols && 
       matrix[row * cols + col] == str[pathLength] &&
       !visited[row * cols + col])
                   {
                       pathLength += 1;
                       visited[row * cols + col] = true;
                       hasPath = hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)
                           ||hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)
                           ||hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)
                           ||hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);
                        if(!hasPath)
                        {
                            pathLength--;
                            visited[row * cols + col] = false;
                        }
    }
    return hasPath;
}
bool Solution::hasPath(char *matrix, int rows, int cols, char *str)
{
    if(matrix==NULL || rows < 1 || cols < 1 || str==NULL)
        return false;
    bool *visited = new bool[rows * cols];
    memset(visited,0,rows*cols);
    int pathLength = 0;
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
            {
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}
