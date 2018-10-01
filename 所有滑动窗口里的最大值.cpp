/*给定数组和滑动窗口大小，找出所有滑动窗口里的最大值
如数组{2,3,4,2,6,2,5,1}及滑动窗口3那么一共存在6个滑动结果，最大值*依次是4 4 6 6 6 5*/
vector<int> maxWindow(const vector<int> &num, int size)
{
    queue<int>index; //index存储的是数组中每个元素的下标
    vector<int> maxResult;
    if(nums.size() > size && size >= 1)
    {
        for(int i = 0; i < size; ++i)
        {
            while(index.empty() && nums[i] > nums[index.front()])
            {
               index.pop_front();
            }//while
            index.push_back(i);
        }//for
        for(int i = size; i < nums.size(); ++i)
        {
            maxResult.push_back(nums[index.front()]);
            while(!index.empty() && nums[i] >= nums[index.back()])
            {
                index.pop_back();
            }//while
            if(index.front() <= (int)(i - size))
            {
                index.pop_front();
            }//if
            index.push_back(i);
        }//for
    }//if
    return maxResult;
}


