//
//
//

#pragma once
class Quicksort
{
public:
	int* NumbersArray;
	int StartIndex;
	int EndIndex;
	int Pivot_index;

public:
	void QuickSort(int* _numbers, int _startIndx, int _endIndex);
	int find_pivot(int startIndex, int endIndex);
	int Partition(int* numbers, int startIndex, int endIndex);
	void PrintArray(int* numbers, int N);
};

