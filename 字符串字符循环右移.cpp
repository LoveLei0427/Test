//strcpyÓöµ½'\0'Í£Ö¹
void Loop(char* str,int step)
{
    int n = strlen(str) - step;
    char res[256];
    strcpy(res,str + n);
    strcpy(res + step,str);
    *(res + strlen(str)) = '\0';
    strcpy(str,res);

}