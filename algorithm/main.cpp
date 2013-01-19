#include "algorithm.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	display();

	int array[] = {7, 2, 38, 11, 5, 31, 29, 1, 39, 79, 56};

//	QucikSortHelp(array, 0, sizeof(array) / sizeof(int) - 1);
//	KBig(array, 0, sizeof(array) / sizeof(int) - 1, 3);

//	heapSort(array, sizeof(array) / sizeof(int));	

	KBig(array, 5, sizeof(array) / sizeof(int));

	cout<<"numberOfZero: "<<numberOfZero(25)<<endl;;
	cout<<"numberOfZero2: "<<numberOfZero2(25)<<endl;
	cout<<"numberOfZeroInBinary: "<<numberOfZeroInBinary(8)<<endl;
	cout<<"numberOfZeroInBinary2: "<<numberOfZeroInBinary2(8)<<endl;

	cout<<"numberOfOne: "<<numberOfOne(7)<<endl;
	
	printNumberOfBinary(6);
}