//1、哈希
// * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].*/
vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int,int> mapRes;
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i)
    {
        mapRes[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); ++i)
    {
        int temp = target - nums[i];
        //coutount返回被查找元素的个数存在返回1否则返回0
        if(mapRes.count(temp) && mapRes[temp]!=i)
        {
            res.push_back(i);
            res.push_back(mapRes[temp]);
            break;
        }
    }
    return res;
}