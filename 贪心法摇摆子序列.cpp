/*
��������Ԫ�صĲ�ֵ�ϸ�������֮�佻��,�򱻳�Ϊ�ڶ�����,[1,7,4,9,2,5]�ǰڶ�����,��Ϊ��ֵ(6,-3,5,-7,3)�������档
����һ����������,���س�����İڶ����е������еĳ��ȡ���������ͨ����ԭʼ����ɾ��һЩ������Ԫ��
������[1,17,5,10,13,15,10,5,16,8]�����Ϊ7  ([1,17,10,13,10,16,8] )��
*/
//����һ��
int MaxLength(vector<int>& nums)
{
    if(nums.size() < 2)
        return nums.size();
    //�����������ֱ������ֵΪ������Ϊ���ĳ���
    int pvar = 1;
    int nvar = 1;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > nums[i-1])
        {
            pvar = nvar + 1;
        }
        else if(nums[i] < nums[i-1])
        {
            nvar = pvar + 1;
        }
        else{
            //nums[i]==nums[i-1]ʱ�����ı�
        }
    }
    return max(pvar,nvar);
}

//������ ״̬��ʵ��
/*��������״̬begin,up,down--
 * ÿ��Ԫ�ش�������״̬�е�ĳһ��������������ǰһ������ȣ�����BEGIN״̬��
 * ����Ǵ���ǰһ����������UP״̬�����С��ǰһ����������DOWN״̬��
 * BEGIN����ת������Ҳ����ת��UP,DOWN��
 * UP��ת�������ת��DOWN��DOWN�ǵ�����͵�UP��ת��
 * �������ת������д������ת���������״̬��Ҳ����״̬���䣩����Ӱ��count�ı仯
 */
int MaxLength(vactor<int> &nums)
{
    if(nums.size() < 2)
        return nums.size();
    int BEGIN = 0;
    int UP = 1;
    int DOWN = 2;
    int STATE = BEGIN;
    int count = 1; //�����г���������1
    for(int i = 1; i < nums.size(); ++i)
    {
        switch (STATE)
        {
        case BEGIN:
            if(nums[i] > nums[i-1])
            {
                STATE = UP;
                count += 1;
            }
            else if(nums[i] < nums[i-1])
            {
                STATE = DOWN;
                count += 1;
            }
            else{/*nums[i]==nums[i-1]������״̬ת��*/}
            break;
        case UP:
            if(nums[i] < nums[i-1])
            {
                STATE = DOWN;
                count += 1;
            }
            else{/*nums[i]==nums[i-1]������״̬ת��*/}
            break;

        case DOWN:
            if(nums[i] > nums[i-1])
            {
                STATE = UP;
                count += 1;
            }
            else{/*nums[i]==nums[i-1]������״̬ת��*/}
            break;
        default:
            break;
        }
    }
    return count;
}