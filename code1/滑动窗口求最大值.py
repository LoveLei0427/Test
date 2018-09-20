class Solution:
    def maxInWindows(self, num, size):
        # write code here
        if(num is None or len(num) == 0 or len(num) < size or size == 0):
            return []
        maxList=[]
        for i in range(len(num) - size + 1):
            #生成数组 从0开始
            maxList.append(max(num[i:i+size]))
        return maxList
