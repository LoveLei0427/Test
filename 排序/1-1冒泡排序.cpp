int bubble_sort3(int num[], int n) /*����һ��־�Ա���exchange�����ڱ�־ĳһ������������Ƿ������ݽ�����
  �������ĳһ������ʱ��û�н������ݽ�������˵�������Ѿ���Ҫ�����кã�
  �������������򣬱��ⲻ��Ҫ�ıȽϹ��̡�
 */
{
	int i, j, tmp, flag = 1, count =0;
	for(i = 0; i< n - 1 && (flag==1); i++) /*�ж���һ���Ƿ������ݽ�����û����������������*/
		for(j = 0, flag=0; j < n-1-i; j++, count++)
		{
			if(num[j] > num[j+1])
			{
				flag = 1;
				tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
			}
		}
	return count;
}