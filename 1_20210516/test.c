#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//һά����
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//16 -�����С
	printf("%d\n", sizeof(a + 0));//4
	printf("%d\n", sizeof(*a));//4 -a������Ԫ�صĵ�ַ-int* int*������int
	printf("%d\n", sizeof(a + 1));//4 a-1�ĵ�ַ a+1-2�ĵ�ַ
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4 -����ĵ�ַ ����ָ�� ָ��-4/8
	printf("%d\n", sizeof(*&a));//16 -����ָ�� ������ ����
	printf("%d\n", sizeof(&a + 1));//4
	printf("%d\n", sizeof(&a[0]));//4 ���ȼ�[]>& a[0]�ĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1));//4


	////�ַ�����
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//6 6���ַ�������
	//printf("%d\n", sizeof(arr + 0));
	//printf("%d\n", sizeof(*arr));
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr));//4 -ָ��
	//printf("%d\n", sizeof(&arr + 1));
	//printf("%d\n", sizeof(&arr[0] + 1));
	//printf("%d\n", strlen(arr));//��ȷ�� -��\0
	//printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));//���벻ͨ��
	//printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));


	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));//7 7���ַ�������-\0
	//printf("%d\n", sizeof(arr + 0));
	//printf("%d\n", sizeof(*arr));
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr));//4 -����ָ��-ָ��
	//printf("%d\n", sizeof(&arr + 1));
	//printf("%d\n", sizeof(&arr[0] + 1));
	//printf("%d\n", strlen(arr));//6
	//printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));//
	//printf("%d\n", strlen(arr[1]));//����
	//printf("%d\n", strlen(&arr));//���벻ͨ�� ���ν���char* ���Ͳ�ƥ��
	//printf("%d\n", strlen(&arr + 1));//���벻ͨ��
	//printf("%d\n", strlen(&arr[0] + 1));//5 &arr[0]-a�ĵ�ַ &arr[0]+1-b�ĵ�ַ ��b��ʼ����


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


	////��ά����
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