/*strstr(str1,str2) �ж��ַ���str2�Ƿ���str1���Ӵ���
 * ����ǣ��򷵻�str2��str1���״γ��ֵĵ�ַ�����򷵻�NULL*/
/*������ʣ�µĳ��Ⱥ����ַ�����ȵ�λ�ü��ɣ��������Ч��.Ȼ�����ÿһ���ַ���
 * ���Ƕ�����һ�����ַ�����һ��һ���ַ��Ķ�Ӧ�Ƚϣ������Ӧλ���в��ȵģ�������ѭ����
 * ���һֱ��û������ѭ������˵�����ַ��������ˣ��򷵻���ʼλ�ü��ɣ�*/
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
//д����
char *myStr(char *srcStr, const char *subStr)
{
    for(int i = 0; str[i] != '\0'; ++i)
    {
        int temp = i;//����srcStr����ʼ�ж�С�±�λ��
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