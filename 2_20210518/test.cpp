class Solution {
public:
	void adjustdown(vector<int>&nums, int n, int root){
		int parent = root;
		int child = parent * 2 + 1;
		while (child<n){
			//选出左右孩子中大的那一个
			if (child + 1 < n&&nums[child + 1] > nums[child]){
				child++;
			}
			//如果孩子比父亲大 交换 继续向下调整
			//如果孩子小于父亲 则调整结束
			if (nums[child]>nums[parent]){
				swap(nums[child], nums[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else{
				break;
			}
		}
	}
	void heapsort(vector<int>&nums){
		int n = nums.size();
		//堆排升序 建大堆 O(N)
		for (int i = (n - 1 - 1) / 2; i >= 0; i--){
			adjustdown(nums, n, i);
		}
		int end = n - 1;
		while (end > 0){
			//把堆顶当前最大的数依次换到最后
			swap(nums[0], nums[end]);
			//调堆选出剩下的数当中最大的
			adjustdown(nums, end, 0);
			end--;
		}

	}
	vector<int> sortArray(vector<int>& nums) {
		heapsort(nums);
		return nums;
	}
};


class Solution {
public:
	void selectsort(vector<int>&nums){
		int n = nums.size();
		int left = 0, right = n - 1;
		while (left < right){
			int mini = left, maxi = right;
			for (int i = 0; i <= right; i++){
				if (nums[i]<nums[mini]){
					mini = i;
				}
				if (nums[i]>nums[maxi]){
					maxi = i;
				}
			}
			swap(nums[left], nums[right]);
			if (left == maxi){
				maxi = mini;
			}
			swap(nums[right], nums[maxi]);
			left++;
			right--;
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		selectsort(nums);
		return nums;
	}
};




class Solution {
public:
	void shellsort(vector<int>&nums){
		int n = nums.size();
		//gap>1为预排序-接近有序
		//gap=1为插排-有序
		int gap = n;
		while (gap > 1){
			gap = gap / 3 + 1;//+1是为了确保最后一次gap一定为1
			for (int i = 0; i<n - gap; i++){
				int end = i;
				int tmp = nums[end + gap];
				while (end >= 0){
					if (nums[end]>tmp){
						nums[end + gap] = nums[end];
						end -= gap;
					}
					else{
						break;
					}
				}
				nums[end + gap] = tmp;
			}
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		shellsort(nums);
		return nums;
	}
};



class Solution {
public:
	int partsort(vector<int>&nums, int left, int right){
		//right作key left先走
		int key = nums[right];
		int keyindex = right;
		while (left < right){
			//<=和>=不加=会死循环 5-最左 5 5-最右 三个数永远动不了
			//left找大-找到出while
			while (left < right&&nums[left] <= key){
				left++;
			}
			//right找小-找到出while
			while (left < right&&nums[right] >= key){
				right--;
			}
			//交换
			swap(nums[left], nums[right]);
		}
		swap(nums[left], nums[keyindex]);
		return left;//返回相遇的位置
	}
	void quicksort(vector<int>&nums, int left, int right){
		if (left >= right){
			return;//这个区间没有值了 不用排了 return 
		}
		int pos = partsort(nums, left, right);
		quicksort(nums, left, pos - 1);
		quicksort(nums, pos + 1, right);
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksort(nums, left, right);
		return nums;
	}
};



class Solution {
public:
	void quicksort1(vector<int>&nums, int left, int right){
		//right作key left先走
		int key = nums[right];
		int keyindex = right;
		while (left < right){
			//<=和>=不加=会死循环 5-最左 5 5-最右 三个数永远动不了
			//left找大-找到出while
			while (left < right&&nums[left] <= key){
				left++;
			}
			//right找小-找到出while
			while (left < right&&nums[right] >= key){
				right--;
			}
			//交换
			swap(nums[left], nums[right]);
		}
		swap(nums[left], nums[keyindex]);
		if (left >= right){
			return;//这个区间没有值了 不用排了 return 
		}
		int pos = left;
		quicksort1(nums, left, pos - 1);
		quicksort1(nums, pos + 1, right);
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksort1(nums, left, right);
		return nums;
	}
};



void quicksort2(vector<int>&nums, int left, int right){
	int key = nums[right];
	while (left < right){
		//找大
		while (left < right&&nums[left] <= key){
			left++;
		}
		nums[right] = nums[left];//找到大扔到右边的坑里去 同时right形成新的坑
		while (left < right&&nums[right] >= key){
			right--;
		}
		nums[left] = nums[right];//找到小扔到左边的坑里去 同时left形成新的坑
	}
	nums[left] = key;
	if (left >= right){
		return;//这个区间没有值了 不用排了 return 
	}
	int pos = left;
	quicksort2(nums, left, pos - 1);
	quicksort2(nums, pos + 1, right);

}
vector<int> sortArray(vector<int>& nums) {
	int left = 0;
	int right = nums.size() - 1;
	quicksort2(nums, left, right);
	return nums;
}
};


//前后指针法
void quicksort3(vector<int>&nums, int left, int rihgt){
	int prev = left - 1;
	int cur = left;
	int key = nums[right];//?
	while (cur < rihgt){
		if (nums[cur] < key&&prev++ != cur){
			swap(nums[prev], nums[cur]);
		}
		cur++;
	}
	prev++;
	swap(nums[prev], nums[right]);
	if (left >= right){
		return;//这个区间没有值了 不用排了 return 
	}
	int pos = prev;
	quicksort3(nums, left, pos - 1);
	quicksort3(nums, pos + 1, right);
}
vector<int> sortArray(vector<int>& nums) {
	int left = 0;
	int right = nums.size() - 1;
	quicksort3(nums, left, right);
	return nums;
}
};



int getmid(vector<int>& nums, int left, int right){
	int mid = (left + right) >> 1;
	//left right
	if (nums[left] < nums[right]){
		//left mid right
		if (nums[mid] < nums[right]){
			return mid;
		}
		//a[mid]>a[right]
		//left right mid
		else if (nums[left] < nums[right]){
			return right;
		}
		//mid left right
		else{
			return left;
		}
	}
	//nums[mid]<nums[left]
	//mid left
	else{
		//right mid left 
		if (nums[right] < nums[mid]){
			return mid
		}
		//mid left right
		else if (nums[left] < nums[mid]){
			return left;
		}
		//right mid left
		else{
			return mid;
		}
	}
}




class Solution {
public:
	// //左右指针法-hoare法
	// void quicksort1(vector<int>&nums,int left,int right){
	//     //right作key left先走
	//     int key=nums[right];
	//     int keyindex=right;
	//     while(left<right){
	//         //<=和>=不加=会死循环 5-最左 5 5-最右 三个数永远动不了
	//         //left找大-找到出while
	//         while(left<right&&nums[left]<=key){
	//             left++;
	//         }
	//         //right找小-找到出while
	//         while(left<right&&nums[right]>=key){
	//             right--;
	//         }
	//         //交换
	//         swap(nums[left],nums[right]);
	//     }
	//     swap(nums[left],nums[keyindex]);
	//     if(left>=right){
	//         return;//这个区间没有值了 不用排了 return 
	//     }
	//     int pos=left;
	//     quicksort1(nums,left,pos-1);
	//     quicksort1(nums,pos+1,right);
	// } 
	//挖坑法
	void quicksort2(vector<int>&nums, int left, int right){
		int mid = getmid(nums, left, right);
		swap(nums[right], nums[mid]);
		int key = nums[right];
		while (left < right){
			//找大
			while (left < right&&nums[left] <= key){
				left++;
			}
			nums[right] = nums[left];//找到大扔到右边的坑里去 同时right形成新的坑
			while (left < right&&nums[right] >= key){
				right--;
			}
			nums[left] = nums[right];//找到小扔到左边的坑里去 同时left形成新的坑
		}
		nums[left] = key;
		if (left >= right){
			return;//这个区间没有值了 不用排了 return 
		}
		int pos = left;
		quicksort2(nums, left, pos - 1);
		quicksort2(nums, pos + 1, right);

	}
	//前后指针法
	// void quicksort3(vector<int>&nums,int left,int rihgt){
	//     int prev=left-1;
	//     int cur=left;
	//     int key=nums[right];
	//     while(cur<rihgt){
	//         if(nums[cur]<key&&prev++!=cur){
	//             swap(nums[prev],nums[cur]);
	//         }
	//         cur++;
	//     }
	//     prev++;
	//     swap(nums[prev],nums[right]);
	//     if(left>=right){
	//         return;//这个区间没有值了 不用排了 return 
	//     }
	//     int pos=prev;
	//     quicksort3(nums,left,pos-1);
	//     quicksort3(nums,pos+1,right);
	// }
	int getmid(vector<int>& nums, int left, int right){
		int mid = (left + right) >> 1;
		//left right
		if (nums[left] < nums[right]){
			//left mid right
			if (nums[mid] < nums[right]){
				return mid;
			}
			//a[mid]>a[right]
			//left right mid
			else if (nums[left] < nums[right]){
				return right;
			}
			//mid left right
			else{
				return left;
			}
		}
		//nums[mid]<nums[left]
		//mid left
		else{
			//right mid left 
			if (nums[right] < nums[mid]){
				return mid;
			}
			//mid left right
			else if (nums[left] < nums[mid]){
				return left;
			}
			//right mid left
			else{
				return mid;
			}
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksort2(nums, left, right);
		return nums;
	}
};


class Solution {
public:
	// //左右指针法-hoare法
	// void quicksort1(vector<int>&nums,int left,int right){
	//     //right作key left先走
	//     int key=nums[right];
	//     int keyindex=right;
	//     while(left<right){
	//         //<=和>=不加=会死循环 5-最左 5 5-最右 三个数永远动不了
	//         //left找大-找到出while
	//         while(left<right&&nums[left]<=key){
	//             left++;
	//         }
	//         //right找小-找到出while
	//         while(left<right&&nums[right]>=key){
	//             right--;
	//         }
	//         //交换
	//         swap(nums[left],nums[right]);
	//     }
	//     swap(nums[left],nums[keyindex]);
	//     if(left>=right){
	//         return;//这个区间没有值了 不用排了 return 
	//     }
	//     int pos=left;
	//     quicksort1(nums,left,pos-1);
	//     quicksort1(nums,pos+1,right);
	// } 
	//挖坑法
	void quicksort2(vector<int>&nums, int left, int right){
		int mid = getmid(nums, left, right);
		swap(nums[right], nums[mid]);
		int key = nums[right];
		while (left < right){
			//找大
			while (left < right&&nums[left] <= key){
				left++;
			}
			nums[right] = nums[left];//找到大扔到右边的坑里去 同时right形成新的坑
			while (left < right&&nums[right] >= key){
				right--;
			}
			nums[left] = nums[right];//找到小扔到左边的坑里去 同时left形成新的坑
		}
		nums[left] = key;
		if (left >= right){
			return;//这个区间没有值了 不用排了 return 
		}
		int pos = left;
		quicksort2(nums, left, pos - 1);
		quicksort2(nums, pos + 1, right);

	}
	//前后指针法
	// void quicksort3(vector<int>&nums,int left,int rihgt){
	//     int prev=left-1;
	//     int cur=left;
	//     int key=nums[right];
	//     while(cur<rihgt){
	//         if(nums[cur]<key&&prev++!=cur){
	//             swap(nums[prev],nums[cur]);
	//         }
	//         cur++;
	//     }
	//     prev++;
	//     swap(nums[prev],nums[right]);
	//     if(left>=right){
	//         return;//这个区间没有值了 不用排了 return 
	//     }
	//     int pos=prev;
	//     quicksort3(nums,left,pos-1);
	//     quicksort3(nums,pos+1,right);
	// }
	int getmid(vector<int>& nums, int left, int right){
		int mid = (left + right) >> 1;
		//left mid
		if (nums[left] < nums[mid]){
			//left mid right
			if (nums[mid] < nums[right]){
				return mid;
			}
			//left right mid
			else if (nums[left] < nums[right]){
				return right;
			}
			//right left mid
			else{
				return left;
			}
		}
		//mid left
		else{
			//right mid left 
			if (nums[right] < nums[mid]){
				return mid;
			}
			//mid left right
			else if (nums[left] < nums[mid]){
				return left;
			}
			//mid left right
			else{
				return right;
			}
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksort2(nums, left, right);
		return nums;
	}
};

class Solution {
public:
	void quicksortstack(vector<int>& nums, int left, int right){
		stack<int>st;
		st.push_back(left);
		st.push_back(right);

	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksortstack(nums, left, right);
		return nums;
	}
};