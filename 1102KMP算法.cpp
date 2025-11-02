#define _CRT_SECURE_NO_WARNINGS
//字符串匹配-KMP匹配
//KMP算法是建立在BF算法基础上的，KMP算法与BF算法的最大区别在于，BF算法只能一位一位匹配，而KMP算法能够省去不必要的匹配步骤，从而实现跳位的匹配
//KMP算法中的next数组存放了模式串T出现重复字符的信息，
// 利用已经部分匹配这个有效信息，保持i指针不回溯，通过修改j指针，让模式串尽量地移动到有效的位置，而避免模式串移动到无效位置
#include <stdio.h>
#include <string.h>
//Next数组的含义
//next[i] 表示：当模式串在第 i 个字符匹配失败时，应该回溯到模式串的 next[i] 位置继续与主串比较。
void get_next(char s[], int next[]) {
	int len = strlen(s);
	int i = 0;// 主指针，遍历模式串
	int j = -1;//前缀指针，记录当前匹配的前缀长度
	next[0] = -1;// 第一个字符的next值固定为-1
	while (i < len - 1)
	{
		if (j == -1 || s[i] == s[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];// 回溯到前一个匹配位置
		}
	}
}
int KMP(char s1[], char s2[], int next[])
{
	int i = 0;
	int j = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	while (i < len1 && j < len2)
	{
		if (j == -1 || s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= len2)
	{
		return i - len2; // 匹配成功，返回模式串在主串中的起始位置
	}
	else
	{
		return -1; // 匹配失败
	}
}
int main() {
	char s1[] = "ababcabcacbab";
	char s2[] = "abcac";
	int next[1000];
	get_next(s2, next);
	int position = KMP(s1, s2, next);
	printf("%d\n", position);
	return 0;

}


int KMP(char* s1,char* s2, int* next)
{
	int j = 0;
	int i = 0;
	while(j<strlen(s2))
	{
		if (j==-1||s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == strlen(s2))
		return i - j;
	return -1;
}
