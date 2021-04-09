#define _CRT_SECURE_NO_WARNINGS 1
//����


void PrintArray(int* a, int n)
{
	for (size_t i = 0;i <n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void InsertSort(int* a, int n)
{
	//����end��λ�ô�0�ߵ�n-2 
	for (int i = 0; i < n - 1; i++)
	{
		//��������
		//��[0,end]�����в���tmp,��������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end]>tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void ShellSort(int* a, int n)
{
	//gap>1ʱΪԤ����  �ӽ�����
	//gao=1ʱΪֱ�Ӳ������� ����
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3 + 1;//+1�Ǳ�֤���һ��һ����1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end]>tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
	

void TestShellSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin<end)
	{
		//[begin,end]ѡ��һ����С�ģ�ѡ��һ�������±�
		int mini = begin, maxi = end;
		for (int i = begin; i <= end;i++)
		{
			if (a[i]>a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
void TestSelectSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}