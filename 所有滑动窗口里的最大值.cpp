/*��������ͻ������ڴ�С���ҳ����л�������������ֵ
������{2,3,4,2,6,2,5,1}����������3��ôһ������6��������������ֵ*������4 4 6 6 6 5*/
vector<int> maxWindow(const vector<int> &num, int size)
{
    queue<int>index; //index�洢����������ÿ��Ԫ�ص��±�
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


