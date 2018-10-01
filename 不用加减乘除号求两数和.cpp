/*
两数异或，相当于不进位情况下 相加
计算进位：两数与操作再左移一位
重复前面两部知道进位值为0
*/
int getSum(int num1,int num2)
{
    int sum = 0;
    int carry = 0;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;

    }while(num2 != 0);

    return num1;
}