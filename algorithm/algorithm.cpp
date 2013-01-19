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
/*   һ���������������м������ĺͣ���ô����⼸������
                                                                   */
/************************************************************************/
int sumInArray(const int *src[], const int srcLength, int *des, const int desLength)
{
	if(src == NULL || srcLength < 2 || des == NULL || desLength < 2) return -1;

//	const int *p = src;
	return -1;
}


/************************************************************************/
/* ���֮��2.2������һ����N��
��N!ĩβ�м�����                                                                     */
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
/* �ж�N!�Ķ������������λ1��λ��
�ⷨһ��
 ��Ŀ����һ���࣬��һ����0�ĸ��������������λ1��λ�ã������Ƶġ�
���ڶ������г���2������Ϊ0�����ԣ����������������������2��������*/
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
/* �ж�N!�Ķ������������λ1��λ��
�����
*/
/************************************************************************/
int numberOfZeroInBinary2(int n)
{
	return n - numberOfOne(n);
	
}


//����N�Ķ������к���1�ĸ���
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

//�����n�Ķ����Ʊ�ʾ
void printNumberOfBinary(int n)
{
	if(n != 0) printNumberOfBinary(n / 2);
	cout<<n % 2;
}

/************************************************************************/
/* ���֮��2.6
��ȷ���һ�������� ����С��X= 0.a1a2a3...an(b1b2b3...bm)
 decimal ��ʾС���ĸ���a1a2a3...an�����ָ���
repetend ��ʾb1b2b3...bm�����ָ���������������ڼ���Ƚϴ����������bug��
����int��λ���������������
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


	//���Ӻͷ�ĸ����Լ�ֵõ���С�ķ��Ӻͷ�ĸ��Ȼ�������
	int ngcd = gcd(numerator, denominator);

	cout<<numerator / ngcd<<endl;
	cout<<denominator / ngcd<<endl;
}

/************************************************************************/
/* ���֮��2.7�����Լ��
                                                                     */
/************************************************************************/
int gcd(int x, int y)
{
	return (!y) ? x : gcd(y, x % y);
}