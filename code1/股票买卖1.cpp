//prices数组中存放的是每只股票每天的价格 只能买卖一次 求最大利润
int maxprofit(vector<int>*prices)
{
	int minvalue = INT_MAX;
	int maxvalue = 0;
	for(int i = 0; i <  prices.size();++i)
	{
		minvalue = min(minvalue,prices[i]);
		maxvalue = max(maxvalue,prices[i] - minvalue);
	}
	return maxvalue;
}