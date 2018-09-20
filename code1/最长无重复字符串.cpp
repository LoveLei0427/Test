/*3 ��̬�滮
����ظ��ַ��Ӵ�*/
int LongestSubString(string str, int strLength)
{
    map<char, int> strMap;
    int maxLength = 0; //������ִ�����
    int startIndex = 0; //��¼ͷָ������
    //�����ַ���ÿ����һ����ĸȥ�Ҹ���ĸ���һ�γ��ֵ�ʱ��
    //Ѱ�����ظ��ַ����ַ���
    for(int i = 0; i < strLength; ++i)
    {
        char ch = str[i];
        if(strMap[ch] >= startIndex)
        {
            startIndex = strMap[ch] + 1;
        }
        maxLength = max(maxLength, i - startIndex + 1);
        strMap[ch] = i;
    }
    return maxLength;
}