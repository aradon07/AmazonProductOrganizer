#include "Quicksort.h"

#include<iostream>

using namespace std;

void Quicksort::QuickSort(int* numbers, int startIndex, int endIndex)
{
	// Only sort if at least two-elements of Array, numbers[], exist.
	if (endIndex <= startIndex)
		return;

	// Partition the array, numbers[]
	int new_pivot = Partition(numbers, startIndex, endIndex);
	
	// Recursively sort the Left-partition
	QuickSort(numbers, startIndex, new_pivot);

	// Recursively sort the Right-partition
	QuickSort(numbers, new_pivot + 1, endIndex);

}


int Quicksort::Partition(int* numbers, int startIndex, int endIndex)
{
	// Select Pivot: {0, N-1, midpoint = (startIndex + endIndex)/2 }
	//int pivot_index = startIndex;
	//int Nsize = 

	int pivot_index = find_pivot(startIndex, endIndex);

	// Pivot-Element,
	int Pivot = numbers[pivot_index];

	int Up = startIndex;
	int Down = endIndex;

	bool partition_Done = false;

	while (!partition_Done)
	{
		//
		while (numbers[Up] < Pivot)
		{
			Up++;	// Up = Up + 1
		}

		//
		while (numbers[Down] > Pivot)
		{
			Down--;		//Down = Down - 1
		}

		//If Up and Down crossed each other, the partition-loop is done!
		if (Up >= Down)
		{
			partition_Done = true;
		}
		else
		{
			// If Up & Down don't crossed yet, Swap the elements
			int temp = numbers[Up];
			numbers[Up] = numbers[Down];
			numbers[Down] = temp;

			//PrintArray(numbers, N);

			// Now increment Up and decrement Down to satisfy the following condidition:
			// (Numbers less than or equal) <= Pivot-element < (Numbers greaters than)
			Up++;
			Down--;
		}

	}//End outer while-loop.

	// Return the new position of the pivot_index

	return Down;

} // End function Partition()


int Quicksort::find_pivot(int startIndex, int endIndex)
{
	// Inspired by OpenDSA: (13.11: Quicksort)
	//
	// Select Pivot: {0, N-1, midpoint = (startIndex + endIndex)/2 }

	int pivot_index = startIndex;

	//int pivot_index = endIndex;
	//int pivot_index = (startIndex + endIndex) / 2;

	return pivot_index;
}


void Quicksort::PrintArray(int* numbers, int N_size)
{
	//int n = numbers.size();

	for (int k = 0; k < N_size; k++)
	{
		cout << numbers[k] << " ";

		if ( (k+1) % 20 == 0)
			cout << endl;
	}
	cout << endl;
}
