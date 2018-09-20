
//7¡¢ÕûÊı·­×ª -123--> -321  69-->96
int  reverseInt(int x)
{
    int res = 0;
    while(x != 0)
    {
        if(abs(res) > INT_MAX / 10)
            return 0;
        res = res * 10 + x % 10;
        x /= 10;
    }
  