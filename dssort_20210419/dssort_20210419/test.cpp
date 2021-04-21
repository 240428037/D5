#define _CRT_SECURE_NO_WARNINGS 1

//插入排序
//直接插入排序
void InsertSort(int*a, int n)
{
	//控制end的位置从0走到n-2
	for (int i = 0; i < n - 2;i++)
	{
		//单趟排序
		//在[0,end]区间中插入tmp,依旧有序
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

//希尔排序
void ShellSort(int*a, int n)
{	
	//间隔为gap的预排序
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


//希尔排序
void ShellSort(int*a, int n)
{
	//gap>1时为预排序-接近有序
	//gap==1时为直接插入排序 -有序
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3 + 1;//+1是保证最后一次一定为1 -不能/2-死循环
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