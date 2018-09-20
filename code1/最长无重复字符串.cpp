/*3 动态规划
最长无重复字符子串*/
int LongestSubString(string str, int strLength)
{
    map<char, int> strMap;
    int maxLength = 0; //保存最长字串长度
    int startIndex = 0; //记录头指针索引
    //遍历字符串每遍历一个字母去找该字母最近一次出现的时间
    //寻找无重复字符的字符串
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