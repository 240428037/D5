#define _CRT_SECURE_NO_WARNINGS 1


int*A, int ASize, int k, int*returnsize
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
	//����k����λ
	int KSize = 0;
	//134
	//�ö���һ��KNum����Ȼk��ֵ�ͻᷢ���仯
	int KNum = k;
	while (KNum)
	{
		KSize++;
		KNum /= 10;
	}
	int len = ASize > KSize ? ASize : KSize;
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));

	//A[]
	//K
	int Ai = ASize - 1;	//���������±�
	int reti = 0;//��������±�
	int nextNum = 0;//��λ
	//˳�ŷţ��������
	while (len--)
	{
		int a = 0;
		if (Ai>=0)
		{
			a = A[Ai];
			Ai--;
		}
		int ret = A[Ai] + k % 10 + nextNum;
		k /= 10;
		//��λ
		if (ret > 9)
		{
			ret -= 10;
			nextNum = 1;
		}
		else
		{
			nextNum = 0;
		}
		retArr[reti] = ret;
		reti++;
	}



	if (nextNum == 1)
	{
		retArr[reti] = 1;
		reti++;
	}

	//����
	int left = 0, right = reti - 1;
	while (left < right)
	{
		int tmp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = tmp;
		left++;
		right--;
	}

	*returnSize = reti;
	return retArr;
}



////////////////////////////////////////
//int*A, int ASize, int k, int*returnsize
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
	//����k����λ
	int kSize = 0;
	//�ö���һ��kNum����Ȼk��ֵ�ͻᷢ���仯
	int kNum = k;
	//134
	//134 -1 -13
	//13 -2 -1
	//1 -3 0
	while (kNum)
	{
		kSize++;
		kNum /= 10;
	}
	int len = numSize > kSize ? numSize : kSize;
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));

	//nums[]
	//k
	int i = numSize - 1;	//���������±�
	int reti = 0;//��������±�
	int nextNum = 0;//��λ
	//���µ�������ӵõ�����˳�ŷţ���������������
	while (len--)
	{
		int a = 0;
		if (i >= 0)
		{
			a = num[i];
			i--;
		}
		int ret = num[i] + k % 10 + nextNum;
		k /= 10;
		//��λ
		if (ret > 9)
		{
			ret -= 10;
			nextNum = 1;
		}
		else
		{
			nextNum = 0;
		}
		retArr[reti] = ret;
		reti++;
	}



	if (nextNum == 1)
	{
		retArr[reti] = 1;
		reti++;
	}

	//����
	int left = 0, right = reti - 1;
	while (left < right)
	{
		int tmp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = tmp;
		left++;
		right--;
	}

	*returnSize = reti;
	return retArr;
}