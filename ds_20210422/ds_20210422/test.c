#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



//void BubbleSort(int*a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j<n - 1 - i; j++)
//		{
//			int flag = 1;
//			if (a[j]>a[j + 1])
//			{
//				int tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//				flag = 0;
//			}
//			if (flag == 1)
//				break;
//		}
//	}
//}
//int main()
//{
//	int a[6] = { 2, 3, 7, 6, 5, 8 };
//	int sz = (sizeof(a) / sizeof(a[0]));
//	BubbleSort(a, sz);
//	for (int i = 0; i < sz;i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


//void bubble_sort(int arr[], int sz)
//{
//	//确定冒泡排序的趟数
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//每一趟冒泡排序
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//对arr进行排序，排成升序:从小到大
//	bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}





 


void Swap(int*p1, int*p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//左右指针法-hoare
int PartSort(int*a, int begin, int end)
{
	int key = a[end];
	int keyindex = end;
	while (begin<end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		while (begin < end&&a[end] >= key)
			end--; 
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
void QuickSort(int*a, int begin, int end)
{
	if (begin>=end)
		return;
	int keyindex = PartSort(a, begin, end);
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}


//挖坑法-DigPitMethod
int PartSort2(int*a, int begin, int end)
{
	int key = a[end];
	while (begin<end)
	{
		//找大
		while (begin < end&&a[begin] =< key)
			begin++;
		a[end] = a[begin];//找到大扔到右边的坑里去，同时begin形成新的坑
		while (begin<end&&a[end]>=key)
			end--;
		a[begin] = a[end];//找到小扔到左边的坑里去，同时end形成新的坑
	}
	a[begin] = key;
	return begin;
}


//左右指针法
int PrevCurMethod(int*a, int begin, int end)
{
	int prev=begin-1,cur = begin;
	key = a[end];
	while (cur<end)//遇到key的位置就结束了
	{
		if (a[cur]<key&&prev++!=cur)
			Swap(&a[prev], &a[cur]);
		cur++;
	}
	prev++;
	Swap(&a[prev], &a[end]);
	return prev;
}


#define  MAX