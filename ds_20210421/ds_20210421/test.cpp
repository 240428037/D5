#define _CRT_SECURE_NO_WARNINGS 1
void bubble_sort(int arr[], int sz)
{
	//ȷ��ð�����������
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		//ÿһ��ð������
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void BubbleSort(int*a, int n)
{
	for (int j = 0; j < n - 1;j++)
	{
		if (a[j]>a[j+1])
		{
			int tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
			flag = 0;
		}
		if (flag==1)
		{
			break;
		}
	}
	
}
int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//��arr���������ų�����:��С����
	bubble_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



void bubble_sort(int arr[], int sz)
{
	//ȷ��ð�����������
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//������һ��Ҫ����������Ѿ�����
		//ÿһ��ð������
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//���������������ʵ����ȫ����
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//��arr�������� �ų�����:��С����
	bubble_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



void BubbleSort1(int*a, int n)
{
	for (int end = n - 1; end > 0;end--)
	{
		int flag = 0;
		for (int i = 0; i<end; i++)
		{
			if (a[i]>a[i + 1])
			{
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}



void BubbleSort(int*a, int n)
{
	for (int i = 0; i <n -1-i;i++)
	{
		int flag = 1;
		for (int j = 0; j < n - 1 - i;j++)
		{
			if (a[j]>a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag==1)
		{
			break;
		}
	}
}