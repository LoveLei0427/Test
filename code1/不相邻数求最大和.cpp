/*198、在一列数组中取出一个或多个不相邻数，使其和最大*/
class Solution {
public:
    int *result;
    int solve(vector<int> &nums)
    {
        if(nums.size() <= 1)
            return nums.empty() ? 0 : num[0];
        vector<int> res;
        res.push_back(num[0]);
        res.push_back(max(num[0],num[1]));
        for(int i = 2; i < nums.size(); ++i)
        {
            res.push_back(max(num[i]+num[i-2],num[i-1]));
        }
        return res.back();
    }

};
或者
/*result[0] = nums[0];
  result[1]= max(nums[0],nums[1]);
  for(int i=2;i<nums.size();i++)
    result[i]= max(nums[i]+result[i-2],result[i-1]);*/