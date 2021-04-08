#define _CRT_SECURE_NO_WARNINGS 1
int* singleNumbers(int* nums, int numsSize, int* returnSize){
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	int m = 0;
	while (m < 32)
	{
		if (ret&(1 << m))
			break;
		else
			m++;
	}
	int x1 = 0, x2 = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] & (1 << m))
			x1 ^= nums[i];
		else
			x2 ^= nums[i];
	}
	int* retarr = (int*)malloc(sizeof(int)* 2);
	retarr[0] = x1;
	retarr[1] = x2;
	*returnSize = 2;
	return retarr;
}



int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	for (int i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	for (int i = 0; i < numsSize + 1; i++)
	{
		x ^= i;
	}
	return x;
}
