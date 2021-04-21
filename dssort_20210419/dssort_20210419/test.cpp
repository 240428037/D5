#define _CRT_SECURE_NO_WARNINGS 1

//��������
//ֱ�Ӳ�������
void InsertSort(int*a, int n)
{
	//����end��λ�ô�0�ߵ�n-2
	for (int i = 0; i < n - 2;i++)
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
				end--; 
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//ϣ������
void ShellSort(int*a, int n)
{	
	//���Ϊgap��Ԥ����
	int gap = 3;
	for (int i = 0; i < n - gap; i++)
	{
		int end;
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
			a[end + gap] = tmp;
		}
	}
}


//ϣ������
void ShellSort(int*a, int n)
{
	//gap>1ʱΪԤ����-�ӽ�����
	//gap==1ʱΪֱ�Ӳ������� -����
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3 + 1;//+1�Ǳ�֤���һ��һ��Ϊ1 -����/2-��ѭ��
		for (int i = 0; i < n - gap; i++)
		{
			int end;
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
				a[end + gap] = tmp;
			}
		}
	}
}