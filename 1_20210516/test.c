#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//一维数组
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//16 -数组大小
	printf("%d\n", sizeof(a + 0));//4
	printf("%d\n", sizeof(*a));//4 -a代表首元素的地址-int* int*解引用int
	printf("%d\n", sizeof(a + 1));//4 a-1的地址 a+1-2的地址
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4 -数组的地址 数组指针 指针-4/8
	printf("%d\n", sizeof(*&a));//16 -数组指针 解引用 数组
	printf("%d\n", sizeof(&a + 1));//4
	printf("%d\n", sizeof(&a[0]));//4 优先级[]>& a[0]的地址
	printf("%d\n", sizeof(&a[0] + 1));//4


	////字符数组
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//6 6个字符的数组
	//printf("%d\n", sizeof(arr + 0));
	//printf("%d\n", sizeof(*arr));
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr));//4 -指针
	//printf("%d\n", sizeof(&arr + 1));
	//printf("%d\n", sizeof(&arr[0] + 1));
	//printf("%d\n", strlen(arr));//不确定 -找\0
	//printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));//编译不通过
	//printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));


	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));//7 7个字符的数组-\0
	//printf("%d\n", sizeof(arr + 0));
	//printf("%d\n", sizeof(*arr));
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr));//4 -数组指针-指针
	//printf("%d\n", sizeof(&arr + 1));
	//printf("%d\n", sizeof(&arr[0] + 1));
	//printf("%d\n", strlen(arr));//6
	//printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));//
	//printf("%d\n", strlen(arr[1]));//报错
	//printf("%d\n", strlen(&arr));//编译不通过 传参接收char* 类型不匹配
	//printf("%d\n", strlen(&arr + 1));//编译不通过
	//printf("%d\n", strlen(&arr[0] + 1));//5 &arr[0]-a的地址 &arr[0]+1-b的地址 从b开始计算


	//char *p = "abcdef";
	//printf("%d\n", sizeof(p));
	//printf("%d\n", sizeof(p + 1));
	//printf("%d\n", sizeof(*p));
	//printf("%d\n", sizeof(p[0]));
	//printf("%d\n", sizeof(&p));
	//printf("%d\n", sizeof(&p + 1));
	//printf("%d\n", sizeof(&p[0] + 1));
	//printf("%d\n", strlen(p));
	//printf("%d\n", strlen(p + 1));
	//printf("%d\n", strlen(*p));
	//printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1));
	//printf("%d\n", strlen(&p[0] + 1));


	////二维数组
	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof(a[0][0]));
	//printf("%d\n", sizeof(a[0]));
	//printf("%d\n", sizeof(a[0] + 1));
	//printf("%d\n", sizeof(*(a[0] + 1)));
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(*(a + 1)));
	//printf("%d\n", sizeof(&a[0] + 1));
	//printf("%d\n", sizeof(*(&a[0] + 1)));
	//printf("%d\n", sizeof(*a));
	//printf("%d\n", sizeof(a[3]));

	return 0;
}