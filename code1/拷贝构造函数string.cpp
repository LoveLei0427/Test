//1���������������
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
//����ֵ��������Ϊ���͵�����
//����Ϊ���ö�����ʵ������ֹ���ø��ƹ��캯�� ͬʱ���ı䴫�������ֵ����Ϊconst
CMyString& CMyString::operator = (const CMyString& str)//�ص�
{
    //�жϴ�������͵�ǰʵ���Ƿ���ͬһ��ʵ�� �����򲻽��и�ֵ����
    if(this->m_pData==str.m_pData)
    {
        return *this;
    }
    //�ͷ�ʵ��������ڴ�
    delete[] m_pData;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
    //ʵ������ʱ������������
    return *this;
}