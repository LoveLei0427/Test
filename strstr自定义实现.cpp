/*strstr(str1,str2) 判断字符串str2是否是str1的子串。
 * 如果是，则返回str2在str1中首次出现的地址；否则返回NULL*/
/*遍历到剩下的长度和子字符串相等的位置即可，提高运算效率.然后对于每一个字符，
 * 我们都遍历一遍子字符串，一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，
 * 如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即可，*/
int mystr(string srcStr, string subStr)
{
    if(subStr == " ")
        return 0;
    int srcSize = srcStr.size();
    int subSize = subStr.size();
    if(srcSize < subSize)
        return -1;
    for(int i = 0; i <= srcSize - subSize; ++i)
    {
        int j;
        for(j = 0; j < subSize; ++j)
        {
            if(srcStr[i + j] != subStr[j])
                break;
        }//for
        if(j == subSize)
            return i;
    }//for
    return -1;
}
//写法二
char *myStr(char *srcStr, const char *subStr)
{
    for(int i = 0; str[i] != '\0'; ++i)
    {
        int temp = i;//保留srcStr中起始判断小下标位置
        int j = 0;
        while(srcStr[i++] == subStr[j++])
        {
            if(subStr[j] == '\0')
            {
                return &str[temp];
            }//if
        }//while
        i = temp;
    }
    return NULL;
}