//2¡¢·­×ªµ¥´ÊË³ĞòÁĞ student. a am I-->I am a student.
class Solution {
public:
    string ReverseSentence(string str);
    //void Reverse(char* pstart,char* pend);
    void Reverse(string &str,int pstart, int end);
    
};
string Solution::ReverseSentence(string str){
    if(str.empty())
        return str;
    //char* pstart = const_cast<char*>(str.c_str());
    //char* pend = const_cast<char*>(str.c_str());
    int pstart = 0;
    int pend = 0;
    while(str[pend] != '\0')
        pend++;
    --pend;
    Reverse(str,pstart,pend);
    
    pstart = pend = 0;
    while(str[pstart] != '\0'){
        if(str[pstart] == ' '){
            pstart++;
            pend++;
        }
        else if(str[pend] == '\0' || str[pend] == ' '){
            Reverse(str,pstart,--pend);
            pstart = ++pend;
        }
        else{
            pend++;
        }
    }
    return str;
}

void Solution::Reverse(string &str,int pstart,int pend){
    //if(pstart == NULL || pend == NULL)
        //return;
    if(str.empty())
        return;
    while(pstart < pend){
        char temp = str[pstart];//*pstart;
        //*pstart = *pend;
        str[pstart] = str[pend];
        //*pend = temp;
        str[pend] = temp;
        pstart++;
        pend--;
    }
}