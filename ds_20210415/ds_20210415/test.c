#define _CRT_SECURE_NO_WARNINGS 1

int removeDuplicates(int* nums, int numsSize){
	//�������Ϊ�գ���return 0
	if (numsSize == 0)
		return 0;
	//˫ָ��
	//����ָ��
	//��������ָ��prev=0,cur=1,dest=0;
	//prevָ���� curָ����
	//����prev=0,cur=1;
	//dest�������ɾ�����������Ԫ��
	int prev = 0, cur = 1, dest = 0;
	//whileѭ������������cur�ߵ���������һ��Ԫ��
	//������cur<numsSiz
	while (cur < numsSize)
	{
		//��Ϊnums��һ����������
		//�������prevָ���Ԫ�غ�curָ���Ԫ�ز���ͬ
		//��ô��prevָ���Ԫ�ظ�dest
		//Ȼ��prev cur dest�ֱ�++��
		if (nums[prev] != nums[cur])
		{
			nums[dest] = nums[prev];
			prev++;
			cur++;
			dest++;
		}
		//���prev��curָ���Ԫ����ͬ
		//��ô�Ͳ���Ԫ����dest��ȥ��
		//����2 2 3
		//��ʱprev++ cur++;
		//�ȵ�prevָ��ڶ���2 curָ��3
		//�Ż��2�ŵ�dest��
		//���Ҳ����©��Ԫ��
		else
		{
			prev++;
			cur++;
		}
	}
	//��ʱcur�Ѿ�ָ��NULL
	//prevָ�����һ��Ԫ��
	//�������һ��Ԫ�ػ�û�зŵ�dest��
	nums[dest] = nums[prev];
	//��Ϊ���Ҫ����ɾ����������³���
	//���Բ�Ҫ����dest++
	dest++;
	return dest;
}



int removeDuplicates(int* nums, int numsSize){
	if (numsSize == 0)
		return 0;
	int prev = 0, cur = 1, dest = 0;
	while (cur < numsSize)
	{
		if (nums[prev] != nums[cur])
		{
			nums[dest] = nums[prev];
			prev++;
			cur++;
			dest++;
		}
		else
		{
			prev++;
			cur++;
		}
	}
	nums[dest] = nums[prev];
	dest++;
	return dest;
}



int removeDuplicates(int* nums, int numsSize){
	//����OJ�⣬һ�������ȿ������������-����Ϊ�յ����
	//�����������Ϊ�գ�ֱ��return 0;
	if (numsSize == 0)
		return 0;
	//˫ָ������
	//prev cur
	//dest
	int prev = 0, cur = 1, dest = 0;
	//1 1 2 2 3 numsSize=5
	//0 1 2 3 4 �±�
	//��prevָ��3��curָ��յ�ʱ��ѭ������
	//����while��ѭ����������Ϊcur<numsSize
	while (cur < numsSize)
	{
		//���prev��curָ���Ԫ�ز����
		//�Ͱ����Ԫ�طŵ�dest��
		//ͬʱprev cur dest�ֱ�++
		if (nums[prev] != nums[cur])
		{
			nums[dest] = nums[prev];
			prev++;
			cur++;
			dest++;
		}
		//���prev��curָ���Ԫ�����
		//�ǵ�Ȼ����
		//prev cur++����
		else
		{
			prev++;
			cur++;
		}
	}
	//       prev cur
	//1 1 2 2 3
	//��ʱprevָ������һ��Ԫ�ػ�û�зŵ�dest��
	nums[dest] = nums[prev];
	dest++;
	//����������ĳ���dest
	return dest;
}