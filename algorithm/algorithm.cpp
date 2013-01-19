#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "algorithm.h"

void display()
{
	cout<<"display test"<<endl;
}

int printMatrix(int **numbers, int rows, int columns)
{
	return -1;
}


/************************************************************************/
/*   一个数，他是数组中几个数的和，怎么求出这几个数来
                                                                   */
/************************************************************************/
int sumInArray(const int *src[], const int srcLength, int *des, const int desLength)
{
	if(src == NULL || srcLength < 2 || des == NULL || desLength < 2) return -1;

//	const int *p = src;
	return -1;
}


/************************************************************************/
/* 编程之美2.2：给定一个数N，
求N!末尾有几个零                                                                     */
/************************************************************************/
int numberOfZero(int n)
{
	if(n < 0) return -1;
	if(n == 0) return 0;

	int ret = 0;
	for(int i = 1; i <= n; ++i)
	{
		int j = i;
		while(j % 5 == 0)
		{
			ret++;
			j /= 5;
		}
	}

	return ret;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
int numberOfZero2(int n)
{
	if(n < 0) return -1;
	if(n == 0) return 0;

	int ret = 0; 
	while(n)
	{
		ret += n / 5;
		n /= 5;
	}

	return ret;
}


/************************************************************************/
/* 判断N!的二进制数中最低位1的位置
解法一：
 题目和上一题差不多，上一题是0的个数，这里是最低位1的位置，是类似的。
由于二进制中除以2能整除为0，所以，这个问题就是求二进制数种2个个数。*/
/************************************************************************/
int numberOfZeroInBinary(int n)
{
	if(n < 0) return -1;
	if(n == 0) return 0;

	int ret = 0;
	while(n)
	{
		n >>= 1;
		ret += n;
	}

	return ret;
}

/************************************************************************/
/* 判断N!的二进制数中最低位1的位置
解二：
*/
/************************************************************************/
int numberOfZeroInBinary2(int n)
{
	return n - numberOfOne(n);
	
}


//计算N的二进制中含有1的个数
int numberOfOne(int n)
{
	int numberOfOne = 0;
	while(n)
	{
		n &= (n - 1);
		numberOfOne++;
	}
	
	return numberOfOne;
}

//输出数n的二进制表示
void printNumberOfBinary(int n)
{
	if(n != 0) printNumberOfBinary(n / 2);
	cout<<n % 2;
}

/************************************************************************/
/* 编程之美2.6
精确表达一个浮点数 比如小数X= 0.a1a2a3...an(b1b2b3...bm)
 decimal 表示小数的个数a1a2a3...an的数字个数
repetend 表示b1b2b3...bm的数字个数，这个函数对于计算比较大的数还是有bug的
超过int的位数就容易溢出错误。
                                                                  */
/************************************************************************/
void FindFraction(int decimal, int repetend)
{
	unsigned int numOfDecimal = 1;
	unsigned int numOfRepetend = 1;

	int tmp = decimal;
	while(tmp)
	{
		tmp /= 10;
		numOfDecimal *= 10;
	}

	tmp = repetend;
	while(tmp)
	{
		tmp /= 10;
		numOfRepetend *= 10;
	}

	unsigned int numerator = decimal * (numOfRepetend - 1) + repetend;
	unsigned int denominator = (numOfRepetend - 1) * numOfDecimal;


	//分子和分母互相约分得到最小的分子和分母，然后在输出
	int ngcd = gcd(numerator, denominator);

	cout<<numerator / ngcd<<endl;
	cout<<denominator / ngcd<<endl;
}

/************************************************************************/
/* 编程之美2.7求最大公约数
                                                                     */
/************************************************************************/
int gcd(int x, int y)
{
	return (!y) ? x : gcd(y, x % y);
}