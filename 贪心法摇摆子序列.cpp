/*
序列相邻元素的产值严格在正负之间交替,则被称为摆动序列,[1,7,4,9,2,5]是摆动序列,因为差值(6,-3,5,-7,3)正负交替。
给定一个整数序列,返回长度最长的摆动序列的子序列的长度。子序列是通过从原始序列删除一些数量的元素
如输入[1,17,5,10,13,15,10,5,16,8]，结果为7  ([1,17,10,13,10,16,8] )；
*/
//方法一：
int MaxLength(vector<int>& nums)
{
    if(nums.size() < 2)
        return nums.size();
    //用两个变量分别计数差值为正或者为负的长度
    int pvar = 1;
    int nvar = 1;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > nums[i-1])
        {
            pvar = nvar + 1;
        }
        else if(nums[i] < nums[i-1])
        {
            nvar = pvar + 1;
        }
        else{
            //nums[i]==nums[i-1]时不做改变
        }
    }
    return max(pvar,nvar);
}

//方法二 状态机实现
/*变量三种状态begin,up,down--
 * 每个元素处于三个状态中的某一个，如果这个数和前一个数相等，则是BEGIN状态，
 * 如果是大于前一个数，则是UP状态，如果小于前一个数，则是DOWN状态。
 * BEGIN可以转向自身，也可以转向UP,DOWN，
 * UP是转向自身和转向DOWN，DOWN是到自身和到UP的转换
 * 向自身的转换不用写出来，转换成自身的状态（也就是状态不变）并不影响count的变化
 */
int MaxLength(vactor<int> &nums)
{
    if(nums.size() < 2)
        return nums.size();
    int BEGIN = 0;
    int UP = 1;
    int DOWN = 2;
    int STATE = BEGIN;
    int count = 1; //子序列长度最少是1
    for(int i = 1; i < nums.size(); ++i)
    {
        switch (STATE)
        {
        case BEGIN:
            if(nums[i] > nums[i-1])
            {
                STATE = UP;
                count += 1;
            }
            else if(nums[i] < nums[i-1])
            {
                STATE = DOWN;
                count += 1;
            }
            else{/*nums[i]==nums[i-1]不进行状态转换*/}
            break;
        case UP:
            if(nums[i] < nums[i-1])
            {
                STATE = DOWN;
                count += 1;
            }
            else{/*nums[i]==nums[i-1]不进行状态转换*/}
            break;

        case DOWN:
            if(nums[i] > nums[i-1])
            {
                STATE = UP;
                count += 1;
            }
            else{/*nums[i]==nums[i-1]不进行状态转换*/}
            break;
        default:
            break;
        }
    }
    return count;
}