#define _CRT_SECURE_NO_WARNINGS 1

int removeDuplicates(int* nums, int numsSize){
	//如果数组为空，则return 0
	if (numsSize == 0)
		return 0;
	//双指针
	//左右指针
	//定义三个指针prev=0,cur=1,dest=0;
	//prev指向左 cur指向右
	//所以prev=0,cur=1;
	//dest用来存放删除后数组的新元素
	int prev = 0, cur = 1, dest = 0;
	//while循环控制条件是cur走到数组的最后一个元素
	//所以是cur<numsSiz
	while (cur < numsSize)
	{
		//因为nums是一个有序数组
		//所以如果prev指向的元素和cur指向的元素不相同
		//那么把prev指向的元素给dest
		//然后prev cur dest分别++；
		if (nums[prev] != nums[cur])
		{
			nums[dest] = nums[prev];
			prev++;
			cur++;
			dest++;
		}
		//如果prev和cur指向的元素相同
		//那么就不把元素往dest里去放
		//比如2 2 3
		//此时prev++ cur++;
		//等到prev指向第二个2 cur指向3
		//才会把2放到dest中
		//因此也不会漏掉元素
		else
		{
			prev++;
			cur++;
		}
	}
	//此时cur已经指向NULL
	//prev指向最后一个元素
	//但是最后一个元素还没有放到dest中
	nums[dest] = nums[prev];
	//因为最后要返回删除后数组的新长度
	//所以不要忘记dest++
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
	//对于OJ题，一上来就先考虑特殊情况，-数组为空的情况
	//所以如果数组为空，直接return 0;
	if (numsSize == 0)
		return 0;
	//双指针问题
	//prev cur
	//dest
	int prev = 0, cur = 1, dest = 0;
	//1 1 2 2 3 numsSize=5
	//0 1 2 3 4 下标
	//当prev指向3，cur指向空的时候循环结束
	//所以while的循环控制条件为cur<numsSize
	while (cur < numsSize)
	{
		//如果prev和cur指向的元素不相等
		//就把这个元素放到dest中
		//同时prev cur dest分别++
		if (nums[prev] != nums[cur])
		{
			nums[dest] = nums[prev];
			prev++;
			cur++;
			dest++;
		}
		//如果prev和cur指向的元素相等
		//那当然不放
		//prev cur++就行
		else
		{
			prev++;
			cur++;
		}
	}
	//       prev cur
	//1 1 2 2 3
	//此时prev指向的最后一个元素还没有放到dest中
	nums[dest] = nums[prev];
	dest++;
	//返回新数组的长度dest
	return dest;
}