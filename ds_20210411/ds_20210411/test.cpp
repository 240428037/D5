#define _CRT_SECURE_NO_WARNINGS 1

int removeElement(int* nums, int numsSize, int val){
	//如果数组为空，直接return 0
	if (numsSize == 0)
		return 0;
	//双指针
	//上下各一个指针
	//定义两个指针src dest
	//src指向上
	//dest指向下
	//src先走，dest再走
	int src = 0, dest = 0;
	while (src<numsSize)
	{
		//当src指向的数字不等于val值
		//把这个数给dest
		//同时src++,dest++
		if (nums[src] != val)
		{
			nums[dest] = nums[src];
			src++;
			dest++;
		}
		//else,当src指向的这个数等于val值
		//src++,dest不动
		else
		{
			src++;
		}
	}
	//最后新的数组的下标就是dest
	//return dest就是返回移除后数组的新长度
	return dest;
}




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
	while (cur<numsSize)
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




void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	//双指针问题
	//开辟一个新数组，从来存放合并后的数组
	//memcpy以后再free掉
	int*tmp = (int*)malloc(sizeof(int)*(m + n));
	//定义三个指针i,i1,i2
	//分别指向tmp,nums1,nums2;
	int i = 0, i1 = 0, i2 = 0;
	//while循环终止条件：只要有一个数组走到尽头，循环就结束
	while (i1<m && i2<n)
	{
		//两个数组的元素比较
		//把小的放到新数组tmp中
		//如果nums1[i1]<nums2[i2]
		//把nums1中的这个元素放到tmp中
		//然后i++，i1++;
		if (nums1[i1]<nums2[i2])
		{
			tmp[i] = nums1[i1];
			i++;
			i1++;
		}
		//如果nums2[i2]<nums1[i1]
		//把nums2中的这个元素放到tmp中
		//然后i++,i2++;
		else
		{
			tmp[i] = nums2[i2];
			i++;
			i2++;
		}
	}
	//走到这里，必然是nums1或者nums2其中的一个数组走完了
	//我们不去管是哪个数组走完
	//写两个while循环去判断就好
	//把剩下那个数组中剩下的元素放到tmp中
	while (i1<m)
	{
		tmp[i] = nums1[i1];
		i++;
		i1++;
	}
	while (i2<n)
	{
		tmp[i] = nums2[i2];
		i++;
		i2++;
	}
	//因为题目要求的是把合并后的数组放到nums1中
	//所以把临时数组tmp中的元素拷贝到nums1中
	//然后再把临时开辟的tmp释放掉
	memcpy(nums1, tmp, sizeof(int)*(m + n));
	free(tmp);
}






void reverse(int* nums, int left, int right)
{
	//循环控制条件left<right
	while (left<right)
	{
		//创建一个临时变量tmp，用于nums[left]和nums[right]交换
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}
//思路：数组翻转
//[1,2,3,4,5,6,7] n=7,k=3
// 0 1 2 3 4 5 6  -下标
//[1,2,3,4][5,6,7]先把0,n-k-1分为一组；n-k,n-1分为一组
//[4,3,2,1][7,6,5]然后两组分别翻转
//[4,3,2,1,7,6,5]再把两组合在一起
//[5,6,7,1,2,3,4]再整体翻转
//等价于
//[1,2,3,4,5,6,7]
//[4,3,2,1,5,6,7]第一次翻转0,n-k-1
//[4,3,2,1,7,6,5]第二次翻转n-k,n-1
//[7,6,5,4,3,2,1]第三次翻转0,n-1
//因为要翻转三次,有大量重复性代码
//所以可以封装一个reverse函数
//参数为(int*nums,int left,int right);


void rotate(int* nums, int numsSize, int k){
	//k=k%numsSize
	//1.如果k>numsSize
	//比如k为13，numsSize=9，那么相当于k=4，因为前9次数组没有变
	//2.因为要调用reverse函数
	//numssize-k为负数，可能存在越界的情况
	k %= numsSize;
	//三次翻转
	//第一次：0,n-k-1
	//第二次：n-k,n-1
	//第三次:0,n-1
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}
//时间复杂度0（N）
//空间复杂度0（1）-没开开辟额外空间