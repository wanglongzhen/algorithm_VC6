#ifndef ALGORITHM_H_H_01
#define ALGORITHM_H_h_01

#include <vector>
#include <string>
#include <iostream>
using namespace std;

void display();


int printMatrix(int **numbers, int rows, int columns);

int sumInArray(const int *src[], const int srcLength, int *des, const int desLength);


/************************************************************************/
/* 编程之美的题目：2.5寻找最大的K个数
解法二：*/
/************************************************************************/

template<class Item>
void swap1(Item &rhs, Item &lhs)
{
	Item tmp = rhs;
	rhs = lhs;
	lhs = tmp;
}

/*
*快速排序的分割算法
*/
template<class Item>
int partition(Item a[], int l, int r)
{
	int compare = a[l];
	
	int left = l, right = r;
	while(left < right)
	{
		while(left < right && a[right] >= compare) right--;
		
		swap1(a[right], a[left]);
		
		while(left < right && a[left] <= compare) left++;
		
		swap1(a[right], a[left]);
	}
	
	return left;
}

template<class ElemType>
void QucikSortHelp(ElemType elem[], int low, int high)
{
	if(low < high)
	{
		int pivotLoc = partition(elem, low, high);
		QucikSortHelp(elem, low, pivotLoc - 1);
		QucikSortHelp(elem, pivotLoc + 1, high);
	}
}

template<class Item>
int KBig(Item a[], int l, int r, const int k)
{
	if((r - l) < k || k <= 0) return -1;
	
	int p = partition(a, l, r);	
	
	if((p - l) > k) return KBig(a, l, p, k);
	else if((p - l) <= k) return KBig(a, p + 1, r, k - (p - l));
}		


/************************************************************************/
/* 编程之美的题目：2.5寻找最大的K个数
解法四：先用堆排序把K个数排序，然后依次取数据查到堆中。
*/
/************************************************************************/
template<class Item>
void HeapAjust(Item *pNumber, int i, int length)
{
	if(pNumber == NULL || length <= 0) return;

	int k = i;
	while((2 * k + 1 < length))
	{
		int child = 2 * k + 1;
		if((child +1) < length && (pNumber[child] < pNumber[child + 1])) child++;
		
		if(pNumber[k] < pNumber[child]) swap1(pNumber[k], pNumber[child]);

		k = child;
	}
}

template<class Item>
void HeapAjustSmall(Item *pNumber, int i, int length)
{
	if(pNumber == NULL || length <= 0) return;
	
	int k = i;
	while((2 * k + 1 < length))
	{
		int child = 2 * k + 1;
		if((child +1) < length && (pNumber[child] > pNumber[child + 1])) child++;
		
		if(pNumber[k] > pNumber[child]) swap1(pNumber[k], pNumber[child]);
		
		k = child;
	}
}

template<class Item>
void heapSort(Item pNumber[], int length)
{
	if(pNumber == NULL || length < 2) return;

	for(int i = length / 2 - 1; i >= 0; --i)
	{
		HeapAjust(pNumber, i, length);
	}

	for(i = length - 1; i > 0; --i)
	{
		swap1(pNumber[i], pNumber[0]);
		HeapAjust(pNumber, 0, i);
	}
}

template<typename Item>
void KBig(Item *pNumber, int k, int length)
{
	if(pNumber == NULL || k >= length || length < 2) return;

	Item *pK = new Item[k];

	int i =0;
	while(i < k)
	{
		pK[i++] = pNumber[i];
	//	i++;
	}

	for(i = k / 2 - 1; i >= 0; --i)
	{
		HeapAjustSmall(pK, i, k);
	}

	for(i = k; i < length; ++i)
	{
		if(pNumber[i] > pK[0]) swap1(pNumber[i], pK[0]);

		HeapAjustSmall(pK, 0, k);
	}

	for(i = 0; i < k; ++i) cout<<pK[i]<<endl;
}



/************************************************************************/
/* 编程之美2.2：给定一个数N，
求N!末尾有几个零                                                                     */
/************************************************************************/
int numberOfZero(int n);
int numberOfZero2(int n);

int numberOfZeroInBinary(int n);
int numberOfZeroInBinary2(int n);

//计算N的二进制中含有1的个数
int numberOfOne(int n);

//输出数n的二进制表示
void printNumberOfBinary(int n);



/************************************************************************/
/* 编程之美2.6
精确表达一个浮点数
                                                                     */
/************************************************************************/
void FindFraction(int decimal, int repetend);

/************************************************************************/
/* 编程之美2.7求最大公约数
                                                                     */
/************************************************************************/
int gcd(int x, int y);
#endif //ALGORITHM_H_h_01