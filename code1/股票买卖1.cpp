//prices�����д�ŵ���ÿֻ��Ʊÿ��ļ۸� ֻ������һ�� ���������
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