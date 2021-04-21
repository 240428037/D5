void Swap(int*p1, int*p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Selectsort(int*a, int n)
{
	int begin = 0, end = n - 1;
	while (begin<end)
	{	
		int min = begin, max = min;
		for (int i = begin; i <= end;i++)
		{
			if (a[i]>a[max])
				max = i;
			if (a[i]<a[min])
				min = i;
		}
		Swap(&a[begin], &a[min]);
		if (begin==max)
			max = min;
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}