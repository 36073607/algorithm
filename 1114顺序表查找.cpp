#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//顺序表查找
int search(int* arr, int sz, int value)
{
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] == value)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 15,54,76,6,9,45,12 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int pos = search(arr, sz, 6);
	printf("%d\n", pos);

	return 0;
}

//顺序表查找优化
#define MAXSIZE 100
int search_pro(int* arr, int sz, int value)
{
	int i = sz;
	arr[0] = value;//在查找方向的尽头设置“哨兵”，免去了在查找过程中每一次比较后都要判断查找位置是否越界
	while (arr[i] != value)
	{
		i--;
	}
	return i;//返回0则查找失败
}
int arr[100];
int main()
{
	int i = 1;//下标
	while (cin >> arr[i] && i <100)
	{
		i++;
	}
	int pos = search_pro(arr, i - 1, 6) - 1;//这里返回下标，需要减1
	cout << pos;

	return 0;
}



//有序表查找
//1.折半查找(二分查找)
//注：折半查找的前提是：
//查找表必须是有序的，这一点非常关键。无序的数据使用折半查找是完全没有意义1的
int Binary_search(int* arr, int sz, int value)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > value)
		{
			right = mid--;
		}
		else if (arr[mid] < value)
		{
			left = mid++;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[] = { 2,13,22,38,46,58,66,77,85,98 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int pos = Binary_search(arr, sz, 66);
	printf("%d\n", pos);

	return 0;
}

//2.插值查找
//前提：查找表必须有序
//对于表长较大，而关键字分布又比较均匀的查找表来说，插值查找算法的平均性能比折半查找要好很多
//反之，数组中如果分布极端不均匀的数据，用插值查找未必合适
int Interpolation_Search(int* arr, int sz, int value)//数组中元素已经按升序处理
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) * (value - arr[left]) / (arr[right] - arr[left]);//这个公式是核心
		if (value < arr[mid])
			right = mid--;
		else if (value > arr[mid])
			left = mid++;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[] = { 2,13,22,38,46,58,66,77,85,98 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int pos = Interpolation_Search(arr, sz, 66);
	printf("%d\n", pos);

	return 0;
}

//3.斐波那契查找   蕴含递推思想
//f[k] = f[k - 1] + f[k - 2]
//f[k] - 1 = (f[k - 1] - 1) + (f[k - 2] - 1) + 1(mid)
int F[] = { 1,1,2,3,5,8,13,21,34,55,89,144 };
int Fib_Search(int* arr, int sz, int value)
{
	int low = 0;
	int high = sz - 1;
	int k = 0;//斐波那契数列下标
	while (high > F[k] - 1)
		k++;
	for (int i = sz; i < F[k] - 1; i++)
		arr[i] = arr[high];//补全待查找数组

	while (low <= high)
	{
		int mid = low + F[k - 1] - 1;
		if (arr[mid] < value)
		{
			low = mid + 1;
			k -= 2;
			//为什么是k-2；
				//说明：
				//1.全部元素=前边元素+后边元素
				//2.f[k] = f[k-1] + f[k-2]
				//3.后面右 f[k-2] 个元素，继续拆分
				//即下次循环 mid = f[k-1-2] - 1。
		}
		else if (arr[mid] > value)
		{
			high = mid - 1;
			k -= 1;
			//为什么是k--;
				//说明：
				//1.全部元素=前边元素+后边元素
				//2.f[k] = f[k-1] + f[k-2]
				//因为前面的 f[k-1] 个元素，所以我们可以继续拆分，f[k-1] = f[k-2] + f[k-3]
				//即再f[k-1]的前面继续查找，k--
		}
		else
		{
			if (mid <= high)
				return mid;
			else
				return high;//若mid>n说明是补全数值，返回原先数组长度sz即可
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 2,13,22,38,46,58,66,77,85,98 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int pos = Fib_Search(arr, sz, 66);
	printf("%d\n", pos);

	return 0;
}