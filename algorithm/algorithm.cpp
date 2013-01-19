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

void FindFraction(int decmial, int repetend)
{

}
