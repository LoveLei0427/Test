/*每个孩子有需求因子g，每个蛋糕有大小s，当某个糖果的大小s>=某个孩子的需求因子g时，代表该糖果可以满足该孩子；求使用这些糖果，最多能满足多少孩子？(注意，某个孩子最多只能用1个糖果满足)。例g = [5, 10, 2, 9, 15, 9]；s = [6, 1, 20, 3, 8]；最多可以满足3个孩子。
思路：某个si如果不能满足某个孩子则也一定不能满足需求因子更大的孩子。
某个孩子可以用更小的si满足，则没必要用更大的满足。故优先从需求因子小的孩子尝试，用某个si满足一个较大gi或一个较小gi效果是一样的(最终满足的总量不变)。*/
int findResult(vector<int> &s, vector<int> & g)
{
	std::sort(g.begin(),g.end());
	std::sort(s.begin(),s.end());
	int kid = 0;
	int cake = 0;
	while(kid <= g.size() && cake <= s.size())
	{
		if(g[kid] <= s[cake])
			kid++;
		cake++;
	}
	return kid;
}