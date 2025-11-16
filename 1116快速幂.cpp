#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//快速幂算法
long long quik_power(int base, int power)
{
	long long result = 1;
	while (power > 0)           //指数大于0进行指数折半，底数变其平方的操作
	{
		if (power % 2 == 1)     //指数为奇数
		{
			power -= 1;         //指数减一
			power /= 2;         //指数折半
			result *= base;     //分离出当前项并累乘后保存
			base *= base;       //底数变其平方
		}
		else                    //指数为偶数
		{
			power /= 2;         //指数折半
			base *= base;       //底数变其平方
		}
	}
	return result;              //返回最终结果
}

//优化：
long long quickPow_a(long long base, long long power)
{
	long long ans = 1;
	while (power)
	{
		if (power % 2 == 1)
		{
			ans = ans * base;
			//power--;
		}
		power /= 2;
		base *= base;
	}
	return ans;
}

long long quickPow_b(long long base, long long power)
{
	if (power == 0)
		return 1;
	if (power % 2 == 1)
		return base * quickPow_b(base, power - 1);
	else
	{
		long long half = quickPow_b(base, power / 2);
		return half * half;
	}
}

int main()
{
	cout << quickPow_a(2, 8) << endl;
	cout << quickPow_b(2, 8) << endl;

	return 0;
}


//应用：
//模意义下取幂
//(a + b) % p = (a % p + b % p) % p
//(a - b) % p = (a % p - b % p) % p
//(a * b) % p = (a % p * b % p) % p

long long quickPow_a(long long base, long long power, long long p)
{
	long long ans = 1;
	base %= p;// 先取模，防止初始base过大
	while (power)
	{
		if (power % 2 == 1)
		{
			ans = ans * base % p;
		}
		power /= 2;
		base = base * base % p;
	}
	return ans;
}

long long quickPow_b(long long base, long long power ,long long p)
{
	if (power == 0)
		return 1;
	if (power % 2 == 1)
		return (base * quickPow_b(base, power - 1, p)) % p;
	else
	{
		long long half = quickPow_b(base, power / 2, p);
		return (half * half) % p;
	}
}

int main()
{
	cout << quickPow_a(2, 8, 7) << endl;
	cout << quickPow_b(2, 8, 7) << endl;

	return 0;
}