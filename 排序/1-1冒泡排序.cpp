int bubble_sort3(int num[], int n) /*加入一标志性变量exchange，用于标志某一趟排序过程中是否有数据交换，
  如果进行某一趟排序时并没有进行数据交换，则说明数据已经按要求排列好，
  则立即结束排序，避免不必要的比较过程。
 */
{
	int i, j, tmp, flag = 1, count =0;
	for(i = 0; i< n - 1 && (flag==1); i++) /*判断上一趟是否有数据交换，没有则表明排序已完成*/
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