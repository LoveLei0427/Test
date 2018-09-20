//1、复制运算符函数
#include <stdio.h>
#include <tchar.h>
#include <string>

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator = (const CMyString& str);

    void Print();
private:
    char* m_pData;
};
CMyString:: CMyString(char* pData)
{
    if(pData==NULL)
    {
        m_pData = new char[1];
        m_pData = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length+1];
        strcpy(m_pData,pData);
    }
}
CMyString::CMyString(const CMyString& str)
{
    int length = strlen(str);
    m_pData = new char[length + 1];
    strcpy(m_pData,str.m_pData);
}
CMyString::~CMyString(void)
{
    delete[] m_pData;
}
//返回值类型声明为类型的引用
//参数为引用而不是实例，防止调用复制构造函数 同时不改变传入参数的值声明为const
CMyString& CMyString::operator = (const CMyString& str)//重点
{
    //判断传入参数和当前实例是否是同一个实例 若是则不进行复值操作
    if(this->m_pData==str.m_pData)
    {
        return *this;
    }
    //释放实例本身的内存
    delete[] m_pData;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
    //实例结束时返回自身引用
    return *this;
}