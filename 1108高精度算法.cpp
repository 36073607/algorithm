#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//一、高精度加法
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int a[510] = { 0 };
	int b[510] = { 0 };
	int c[510] = { 0 };
	for (int i = 0; i < s1.size(); i++)//倒序存储
	{
		a[s1.size() - i - 1] = s1[i] - '0';
	}
	for (int i = 0; i < s2.size(); i++)
	{
		b[s2.size() - i - 1] = s2[i] - '0';
	}

	int length = max(s1.size(), s2.size());

	for (int i = 0; i < length; i++)
	{
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	if (c[length] != 0)//注意，两个数相加后的位数不超过原先数字最大位数+1
		length++;

	for (int i = length - 1; i >= 0; i--)
	{
		cout << c[i];
	}

	return 0;
}


//二、高精度减法
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int a[510] = { 0 };
	int b[510] = { 0 };
	int c[510] = { 0 };

	char flag = '+';
	if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2))//让s1始终为较大的
	{                                                     //字典序比较
		swap(s1, s2);
		flag = '-';
	}

	for (int i = 0; i < s1.size(); i++)
	{
		a[s1.size() - i - 1] = s1[i] - '0';
	}
	for (int i = 0; i < s2.size(); i++)
	{
		b[s2.size() - i - 1] = s2[i] - '0';
	}

	for (int i = 0; i < s1.size(); i++)
	{
		if (a[i] < b[i])
		{
			a[i] += 10;
			a[i + 1]--;
		}
		c[i] = a[i] - b[i];
	}

	int index = 0;//倒序输出第一个数的下标
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		if (c[i] != 0)
		{
			index = i;
			break;
		}
	}

	cout << flag;
	for (int i = index; i >= 0; i--)
		cout << c[i];

	return 0;
}


//三、高精度乘法
//1.高精度数乘低精度数（这里的低是相对于高精度而言的）
int main()
{
	string s;
	int b;//这里假设b<10000 ，则b的位数最多为4
	cin >> s >> b;
	int a[510] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		a[s.size() - i - 1] = s[i] - '0';
	}

	for (int i = 0; i < s.size(); i++)
		a[i] *= b;
	for (int i = 0; i < s.size(); i++)
	{
		if (a[i] >= 10)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}

	int index = 0;
	//两个数相乘的结果的位数 等于 两个数位数之和
	for (int i = s.size() + 4 - 1; i >= 0; i--)
	{
		if (a[i] != 0)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i >= 0; i--)
		cout << a[i];

	return 0;
}

//2.高精度数乘高精度数
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int a[250] = { 0 };
	int b[250] = { 0 };
	int c[500] = { 0 };

	for (int i = 0; i < s1.size(); i++)
		a[s1.size() - i - 1] = s1[i] - '0';
	for (int i = 0; i < s2.size(); i++)
		b[s2.size() - i - 1] = s2[i] - '0';

	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			c[j + i] += c[j] * c[i];//错位相加
			if (c[j + i] >= 10)
			{
				c[j + i + 1] += c[j + i] / 10;
				c[j + i] %= 10;
			}
		}
	}

	int index = 0;
	for (int i = s1.size() + s2.size() - 1; i >= 0; i--)
	{
		if (c[i] != 0)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i >= 0; i--)
		cout << c[i];

	return 0;
}


//四、高精度除法
//1.单精度除以单精度数得到高精度商
int main()
{
	int a = 0;//被除数
	int b = 0;//除数
	int n = 0;//保留小数位数
	cin >> a >> b >> n;
	int tmp = a % b;
	cout << a / b << '.';
	for (int i = 0; i < n; i++)
	{
		tmp *= 10;
		cout << tmp / b;
		tmp %= b;
	}
	
	return 0;
}

//2.高精度数除以单精度数 
// 得到商和余数
int main()
{
	string s;
	int a[250] = { 0 };
	int b = 0;
	int c[250] = { 0 };
	cin >> s >> b;
	for (int i = 0; i < s.size(); i++)
	{
		a[i] = s[i] - '0';//注意这里没有倒序输入
	}
	int t = 0;//余数
	for (int i = 0; i < s.size(); i++)
	{
		t = t * 10 + a[i];
		if (t >= b)
		{
			c[i] = t / b;
			t = t % b;
		}
		else
		{
			c[i] = 0;
		}
	}

	int index = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (c[i] != 0)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i < s.size(); i++)
	{
		cout << c[i];
	}
	cout << " " << t;

	return 0;
}
// 得到高精度商
int main()
{
	string s;
	int a[250] = { 0 };
	int b = 0;//除数
	int c[250] = { 0 };
	int n = 0;//保留几位精度
	cin >> s >> b >> n;
	for (int i = 0; i < s.size(); i++)
		a[i] = s[i] - '0';

	int t = 0;
	for (int i = 0; i < s.size(); i++)
	{
		t = t * 10 + a[i];
		if (t >= b)
		{
			c[i] = t / b;
			t = t % b;
		}
		else
		{
			c[i] = 0;
		}
	}
	int index = 0;
	for (int i = 0; i < s.size(); i++)//删除前导零
	{
		if (c[i] != 0)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i < s.size(); i++)
		cout << c[i];
	cout << '.';

	for (int i = 0; i < n; i++)
	{
		t = t * 10;
		cout << t / b;
		t = t % b;
	}

	return 0;
}

//3.高精度数除以高精度数
#include<iostream>
#include<string>
using namespace std;
void strtoint(string stc, int des[])
{
	for (int i = 1; i <= des[0]; i++)
	{
		des[i] = stc[i - 1] - '0';
	}
}

void cpv(int x[], int y[], int offset)
{
	for (int i = 1; i <= x[0]; i++)
	{
		y[i + offset] = x[i];
	}
	y[0] = x[0] + offset;
}

bool comp(int x[], int y[])
{
	for (int i = 1; i <= x[0]; i++)
	{
		if (x[i] > y[i])
			return true;
		if (x[i] < y[i])
			return false;
	}
	return true;
}

void sub(int x[], int y[])
{
	for (int i = x[0]; i >= 1; i--)
	{
		if (x[i] < y[i])
		{
			x[i] = x[i] + 10;
			x[i - 1] = x[i - 1] - 1;
		}
		x[i] = x[i] - y[i];
	}
}

int main()
{
	string s1, s2;
	int a[250] = { 0 }, b[250] = { 0 }, c[250] = { 0 };
	cin >> s1 >> s2;
	a[0] = s1.size();
	b[0] = s2.size();
	strtoint(s1, a);
	strtoint(s2, b);
	c[0] = a[0] - b[0] + 1;
	int t[500] = { 0 };
	for (int i = 1; i <= c[0]; i++)
	{
		memset(t, 0, sizeof(t));
		cpv(b, t, i - 1);
		a[0] = t[0];
		while (comp(a, t) == true)
		{
			sub(a, t);
			c[i]++;
		}
	}//c数组中存储商，a数组中存储余数
	int lc = 1;
	while (c[lc] == 0 && lc < c[0])
		lc++;
	for (int i = lc; i <= c[0]; i++)
	{
		cout << c[i];
	}
	return 0;
}