#define _CRT_SECURE_NO_WARNINGS 1

int removeElement(int* nums, int numsSize, int val){
	//�������Ϊ�գ�ֱ��return 0
	if (numsSize == 0)
		return 0;
	//˫ָ��
	//���¸�һ��ָ��
	//��������ָ��src dest
	//srcָ����
	//destָ����
	//src���ߣ�dest����
	int src = 0, dest = 0;
	while (src<numsSize)
	{
		//��srcָ������ֲ�����valֵ
		//���������dest
		//ͬʱsrc++,dest++
		if (nums[src] != val)
		{
			nums[dest] = nums[src];
			src++;
			dest++;
		}
		//else,��srcָ������������valֵ
		//src++,dest����
		else
		{
			src++;
		}
	}
	//����µ�������±����dest
	//return dest���Ƿ����Ƴ���������³���
	return dest;
}




int removeDuplicates(int* nums, int numsSize){
	//�������Ϊ�գ���return 0
	if (numsSize == 0)
		return 0;
	//˫ָ��
	//����ָ��
	//��������ָ��prev=0,cur=1,dest=0;
	//prevָ���� curָ����
	//����prev=0,cur=1;
	//dest�������ɾ�����������Ԫ��
	int prev = 0, cur = 1, dest = 0;
	//whileѭ������������cur�ߵ���������һ��Ԫ��
	//������cur<numsSiz
	while (cur<numsSize)
	{
		//��Ϊnums��һ����������
		//�������prevָ���Ԫ�غ�curָ���Ԫ�ز���ͬ
		//��ô��prevָ���Ԫ�ظ�dest
		//Ȼ��prev cur dest�ֱ�++��
		if (nums[prev] != nums[cur])
		{
			nums[dest] = nums[prev];
			prev++;
			cur++;
			dest++;
		}
		//���prev��curָ���Ԫ����ͬ
		//��ô�Ͳ���Ԫ����dest��ȥ��
		//����2 2 3
		//��ʱprev++ cur++;
		//�ȵ�prevָ��ڶ���2 curָ��3
		//�Ż��2�ŵ�dest��
		//���Ҳ����©��Ԫ��
		else
		{
			prev++;
			cur++;
		}
	}
	//��ʱcur�Ѿ�ָ��NULL
	//prevָ�����һ��Ԫ��
	//�������һ��Ԫ�ػ�û�зŵ�dest��
	nums[dest] = nums[prev];
	//��Ϊ���Ҫ����ɾ����������³���
	//���Բ�Ҫ����dest++
	dest++;
	return dest;
}




void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	//˫ָ������
	//����һ�������飬������źϲ��������
	//memcpy�Ժ���free��
	int*tmp = (int*)malloc(sizeof(int)*(m + n));
	//��������ָ��i,i1,i2
	//�ֱ�ָ��tmp,nums1,nums2;
	int i = 0, i1 = 0, i2 = 0;
	//whileѭ����ֹ������ֻҪ��һ�������ߵ���ͷ��ѭ���ͽ���
	while (i1<m && i2<n)
	{
		//���������Ԫ�رȽ�
		//��С�ķŵ�������tmp��
		//���nums1[i1]<nums2[i2]
		//��nums1�е����Ԫ�طŵ�tmp��
		//Ȼ��i++��i1++;
		if (nums1[i1]<nums2[i2])
		{
			tmp[i] = nums1[i1];
			i++;
			i1++;
		}
		//���nums2[i2]<nums1[i1]
		//��nums2�е����Ԫ�طŵ�tmp��
		//Ȼ��i++,i2++;
		else
		{
			tmp[i] = nums2[i2];
			i++;
			i2++;
		}
	}
	//�ߵ������Ȼ��nums1����nums2���е�һ������������
	//���ǲ�ȥ�����ĸ���������
	//д����whileѭ��ȥ�жϾͺ�
	//��ʣ���Ǹ�������ʣ�µ�Ԫ�طŵ�tmp��
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
	//��Ϊ��ĿҪ����ǰѺϲ��������ŵ�nums1��
	//���԰���ʱ����tmp�е�Ԫ�ؿ�����nums1��
	//Ȼ���ٰ���ʱ���ٵ�tmp�ͷŵ�
	memcpy(nums1, tmp, sizeof(int)*(m + n));
	free(tmp);
}






void reverse(int* nums, int left, int right)
{
	//ѭ����������left<right
	while (left<right)
	{
		//����һ����ʱ����tmp������nums[left]��nums[right]����
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}
//˼·�����鷭ת
//[1,2,3,4,5,6,7] n=7,k=3
// 0 1 2 3 4 5 6  -�±�
//[1,2,3,4][5,6,7]�Ȱ�0,n-k-1��Ϊһ�飻n-k,n-1��Ϊһ��
//[4,3,2,1][7,6,5]Ȼ������ֱ�ת
//[4,3,2,1,7,6,5]�ٰ��������һ��
//[5,6,7,1,2,3,4]�����巭ת
//�ȼ���
//[1,2,3,4,5,6,7]
//[4,3,2,1,5,6,7]��һ�η�ת0,n-k-1
//[4,3,2,1,7,6,5]�ڶ��η�תn-k,n-1
//[7,6,5,4,3,2,1]�����η�ת0,n-1
//��ΪҪ��ת����,�д����ظ��Դ���
//���Կ��Է�װһ��reverse����
//����Ϊ(int*nums,int left,int right);


void rotate(int* nums, int numsSize, int k){
	//k=k%numsSize
	//1.���k>numsSize
	//����kΪ13��numsSize=9����ô�൱��k=4����Ϊǰ9������û�б�
	//2.��ΪҪ����reverse����
	//numssize-kΪ���������ܴ���Խ������
	k %= numsSize;
	//���η�ת
	//��һ�Σ�0,n-k-1
	//�ڶ��Σ�n-k,n-1
	//������:0,n-1
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}
//ʱ�临�Ӷ�0��N��
//�ռ临�Ӷ�0��1��-û�����ٶ���ռ�