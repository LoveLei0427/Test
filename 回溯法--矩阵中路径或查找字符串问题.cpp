//DFS题型
//1、终止条件（数据非法）：走到给定范围边界之外  i<0||j<0||i>row_size||j>col_size -- return false
//2、收敛条件（满足输出一种解）：cur_index == word_len-1 -- return true
//3、剪枝条件（遍历错误解回退）：visit[i][j] == true（该元素访问过） || broad[i][j] != word[cur_index]  -- return false
//4、递归方向：上--[i-1][j]  下--[i+1][j]  左--[i][j-1]  右--[i][j+1]
//终止条件、收敛条件、剪枝条件不一定在每个dfs问题中都存在，而且它们的顺序要按照具体问题情境放置
//注：
//    i,j分别表示当前索引二维空间**broad的行、列下标
//    row_size、col_size分别表示二维空间**broad的所有行和所有列
//    cur_index 表示当前索引单词*word的下标
//    bool visit[i][j] 表示当前元素是否被访问
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
