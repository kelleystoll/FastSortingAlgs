// Kelley Stoll
// Fast Sorting Algorithms FINAL PROGRAM
// Data Structures and Algorithms II

#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std;

typedef int ItemType;
const int MAX = 100000; // Max number of elements is 100000


// LIST OF FUNCTIONS
void QuickSort(ItemType data[], int first, int last); // Quicksort for integers
void QuickSort(char data1[], int first, int last); // Quicksort for characters

void merge(ItemType list[], int lowerBound, int upperBound, int mid); // Mergesort for integers
void Mergesort(ItemType list[], int lowerBound, int upperBound);
void merge(char list[], int lowerBound, int upperBound, int mid); // Merge sort for characters
void Mergesort(char list[], int lowerBound, int upperBound);

void radixsort(ItemType list[], int arraysize); // Radixsort for integers
void radixsort(char list[], int arraysize); // Radixsort for characters

void DisplayArray(ItemType data[], int N); // Display aray of integers
void DisplayArray(char data1[], int N); // Display array for characters









// MAIN PROGRAM
int main()
{


	int size, choice, reply;
	char finalans, choice1;
	ItemType data[MAX]; // Array where integer data is sorted
	char data1[MAX];

	srand(time(0)); // Used for random num/char generator


	do // Used for ending program or restarting
	{


		do
		{

			cout << "****Welcome to the Fast Sorting Program!****\n";
			cout << "\nEnter the size of the data to sort between ( 1 - " << MAX << ").\n";
			cin >> size;

		} while (size < 0 || size > MAX);

		do
		{
			cout << "What kind of data would you like to sort: integers (1) or characters (2)?\n";
			cin >> reply;

		} while (reply != 1 && reply != 2);

		if (reply == 1) // INTEGERS
		{

			do
			{
				cout << "Would you like to enter the data: manually (1) or randomly (2)?\n";
				cin >> choice;
			} while (choice != 1 && choice != 2);


			if (choice == 1)
			{

				for (int i = 0; i < size; i++)
				{
					cout << "\nEnter the " << i + 1 << "-th data : ";
					cin >> data[i];
				}
			}

			else
			{

				for (int i = 0; i < size; i++)
				{
					data[i] = rand() % 1000; // Numbers ranging from 0-999
				}

			}


			do
			{
				cout << "Do you want to see your data? Y/N\n";
				cin >> choice1;

			} while (choice1 != 'Y' && choice1 != 'y' && choice1 != 'n' && choice1 != 'N');

			if (choice1 == 'Y' || choice1 == 'y') // YES TO DATA SHOWING
			{


				cout << "\nOriginal data before sorting: " << endl;
				DisplayArray(data, size);

				// Timing Elements for QuickSort
				clock_t starttime, endtime, starttime1, endtime1, starttime2, endtime2;
				double elapsedtime, elapsedtime1, elapsedtime2;

				starttime = clock(); // starts the timer
				cout << "\n\nCalling selection sorts... " << endl << endl;
				QuickSort(data, 0, size - 1); // Calls quicksort function
				endtime = clock(); // ends timer
				elapsedtime = (double)(endtime - starttime) / CLOCKS_PER_SEC;

				cout << "\nThe QuickSort algorithm took "; // Displays QuickSort time
				cout << elapsedtime << " seconds to sort.";


				// Timing Elements for Mergesort
				starttime1 = clock();
				Mergesort(data, 0, size - 1); // Calls Mergesort function
				endtime1 = clock();
				elapsedtime1 = (double)(endtime1 - starttime1) / CLOCKS_PER_SEC;

				cout << "\nThe Mergesort algorithm took "; // Displays Mergesort time
				cout << elapsedtime1 << " seconds to sort." << endl;


				// Timing Elements for Radixsort

				starttime2 = clock(); // starts the timer
				radixsort(data, size); // Calls radixsort function
				endtime2 = clock(); // ends timer
				elapsedtime2 = (double)(endtime2 - starttime2) / CLOCKS_PER_SEC;

				cout << "The Radix sort algorithm took "; // Displays QuickSort time
				cout << elapsedtime2 << " seconds to sort." << endl;


				cout << "\nSorted data: " << endl;
				DisplayArray(data, size);



			}
			else // NO TO DATA SHOWING
			{

				// Timing Elements for QuickSort
				clock_t starttime, endtime, starttime1, endtime1, starttime2, endtime2;
				double elapsedtime, elapsedtime1, elapsedtime2;

				starttime = clock(); // starts the timer
				cout << "\nCalling selection sorts... " << endl << endl;
				QuickSort(data, 0, size - 1); // Calls quicksort function
				endtime = clock(); // ends timer
				elapsedtime = (double)(endtime - starttime) / CLOCKS_PER_SEC;

				cout << "\n\nThe QuickSort algorithm took "; // Displays QuickSort time
				cout << elapsedtime << " seconds to sort.";


				// Timing Elements for Mergesort
				starttime1 = clock();
				Mergesort(data, 0, size - 1); // Calls Mergesort function
				endtime1 = clock();
				elapsedtime1 = (double)(endtime1 - starttime1) / CLOCKS_PER_SEC;

				cout << "\nThe Mergesort algorithm took "; // Displays Mergesort time
				cout << elapsedtime1 << " seconds to sort.";


				// Timing Elements for Radixsort
				starttime2 = clock();
				radixsort(data, size); // Calls radixsort function
				endtime2 = clock();
				elapsedtime2 = (double)(endtime2 - starttime2) / CLOCKS_PER_SEC;

				cout << "\nThe Radixsort algorithm took "; // Displays Mergesort time
				cout << elapsedtime2 << " seconds to sort." << endl;

			}

		}

		else  // REPLY IS CHARACTERS
		{
			do
			{
				cout << "Would you like to enter the data: manually (1) or randomly (2)?\n";
				cin >> choice;
			} while (choice != 1 && choice != 2);


			if (choice == 1)
			{

				for (int i = 0; i < size; i++)
				{
					cout << "\nEnter the " << i + 1 << "-th data : ";
					cin >> data1[i];
				}
			}

			else
			{


				// How do you make it to specify length? Below code doesn't work!
				for (int i = 0; i < size; i++)
				{
					//int length = 4;
					//for (int i = 0; i < length; i++)
					//{

					int n = rand() % 26; // Uses ascii values for random character generator
					char c = (char)(n + 65);

					data1[i] = c;
					//}
				}


				do
				{
					cout << "Do you want to see your data? Y/N\n";
					cin >> choice1;

				} while (choice1 != 'Y' && choice1 != 'y' && choice1 != 'n' && choice1 != 'N');

				if (choice1 == 'Y' || choice1 == 'y') // YES TO DATA SHOWING
				{


					cout << "\nOriginal data before sorting: " << endl;
					DisplayArray(data1, size);

					// Timing Elements for QuickSort
					clock_t starttime, endtime, starttime1, endtime1, starttime2, endtime2;
					double elapsedtime, elapsedtime1, elapsedtime2;

					starttime = clock(); // starts the timer
					cout << "\nCalling selection sorts... " << endl << endl;
					QuickSort(data1, 0, size - 1); // Calls quicksort function
					endtime = clock(); // ends timer
					elapsedtime = (double)(endtime - starttime) / CLOCKS_PER_SEC;

					cout << "\nThe QuickSort algorithm took "; // Displays QuickSort time
					cout << elapsedtime << " seconds to sort.";


					// Timing Elements for Mergesort
					starttime1 = clock();
					Mergesort(data1, 0, size - 1); // Calls Mergesort function
					endtime1 = clock();
					elapsedtime1 = (double)(endtime1 - starttime1) / CLOCKS_PER_SEC;

					cout << "\nThe Mergesort algorithm took "; // Displays Mergesort time
					cout << elapsedtime1 << " seconds to sort.";

					// Timing Elements for Radixsort

					starttime2 = clock(); // starts the timer
					radixsort(data1, size); // Calls radixsort function
					endtime2 = clock(); // ends timer
					elapsedtime2 = (double)(endtime2 - starttime2) / CLOCKS_PER_SEC;

					cout << "\nThe Radix sort algorithm took "; // Displays QuickSort time
					cout << elapsedtime2 << " seconds to sort." << endl;




					cout << "\nSorted data: " << endl;
					DisplayArray(data1, size);


				}
				else // NO TO DATA SHOWING
				{

					// Timing Elements for QuickSort
					clock_t starttime, endtime, starttime1, endtime1, starttime2, endtime2;
					double elapsedtime, elapsedtime1, elapsedtime2;

					starttime = clock(); // starts the timer
					cout << "\nCalling selection sorts... " << endl << endl;
					QuickSort(data1, 0, size - 1); // Calls quicksort function
					endtime = clock(); // ends timer
					elapsedtime = (double)(endtime - starttime) / CLOCKS_PER_SEC;

					cout << "\n\nThe QuickSort algorithm took "; // Displays QuickSort time
					cout << elapsedtime << " seconds to sort.";


					// Timing Elements for Mergesort
					starttime1 = clock();
					Mergesort(data1, 0, size - 1); // Calls Mergesort function
					endtime1 = clock();
					elapsedtime1 = (double)(endtime1 - starttime1) / CLOCKS_PER_SEC;

					cout << "\nThe Mergesort algorithm took "; // Displays Mergesort time
					cout << elapsedtime1 << " seconds to sort.";

					// Timing Elements for Radixsort

					starttime2 = clock(); // starts the timer
					radixsort(data1, size); // Calls radixsort function
					endtime2 = clock(); // ends timer
					elapsedtime2 = (double)(endtime2 - starttime2) / CLOCKS_PER_SEC;

					cout << "\nThe Radixsort algorithm took "; // Displays QuickSort time
					cout << elapsedtime2 << " seconds to sort." << endl;

				}

			}

		}


		cout << "\n\n\nWould you like to the program again? Y/N\n";
		cin >> finalans;


	} while (finalans == 'Y' || finalans == 'y');
	cout << "Thank you for using the Fast Sorting Program. Press any button to exit.\n";



	cin.get();
	cin.get();
	return 0;



}



// DEFINED FUNCTIONS
void QuickSort(ItemType data[], int first, int last) // Quicksort for integers
{

	int i = first, j = last;
	int tmp; // temporary array
	int pivot = data[(first + last) / 2];

	// partition
	while (i <= j)
	{
		while (data[i] < pivot)
			i++;
		while (data[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++;
			j--;
		}
	}

	//recursion 
	if (first < j)
		QuickSort(data, first, j);
	if (i < last)
		QuickSort(data, i, last);

}

void QuickSort(char data1[], int first, int last) // Quick sort for characters
{

	int i = first, j = last;
	int tmp; // temporary array
	int pivot = data1[(first + last) / 2];

	// partition
	while (i <= j)
	{
		while (data1[i] < pivot)
			i++;
		while (data1[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = data1[i];
			data1[i] = data1[j];
			data1[j] = tmp;
			i++;
			j--;
		}
	}

	//recursion 
	if (first < j)
		QuickSort(data1, first, j);
	if (i < last)
		QuickSort(data1, i, last);

}

void merge(char list[], int lowerBound, int upperBound, int mid) // Mergesort for characters

{
	int* leftArray = NULL;
	int* rightArray = NULL;
	int i, j, k;
	int n1 = mid - lowerBound + 1;
	int n2 = upperBound - mid;
	leftArray = new int[n1];
	rightArray = new int[n2];
	for (i = 0; i < n1; i++)
		leftArray[i] = list[lowerBound + i];
	for (j = 0; j < n2; j++)
		rightArray[j] = list[mid + 1 + j];

	i = 0;
	j = 0;
	k = lowerBound;

	while (i < n1 && j < n2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			list[k] = leftArray[i];
			i++;
		}
		else
		{
			list[k] = rightArray[j];
			j++;
		}

		k++;
	}

	while (i < n1)
	{
		list[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		list[k] = rightArray[j];
		j++;
		k++;
	}

	delete[] leftArray;
	delete[] rightArray;


}


void Mergesort(char list[], int lowerBound, int upperBound) // Same as previous
{
	int mid;

	if (upperBound > lowerBound)
	{
		mid = (lowerBound + upperBound) / 2;
		Mergesort(list, lowerBound, mid);
		Mergesort(list, mid + 1, upperBound);
		merge(list, lowerBound, upperBound, mid);
	}
}

void merge(ItemType list[], int lowerBound, int upperBound, int mid) // Mergesort for integers

{
	int* leftArray = NULL;
	int* rightArray = NULL;
	int i, j, k;
	int n1 = mid - lowerBound + 1;
	int n2 = upperBound - mid;
	leftArray = new int[n1];
	rightArray = new int[n2];
	for (i = 0; i < n1; i++)
		leftArray[i] = list[lowerBound + i];
	for (j = 0; j < n2; j++)
		rightArray[j] = list[mid + 1 + j];

	i = 0;
	j = 0;
	k = lowerBound;

	while (i < n1 && j < n2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			list[k] = leftArray[i];
			i++;
		}
		else
		{
			list[k] = rightArray[j];
			j++;
		}

		k++;
	}

	while (i < n1)
	{
		list[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		list[k] = rightArray[j];
		j++;
		k++;
	}

	delete[] leftArray;
	delete[] rightArray;


}


void Mergesort(ItemType list[], int lowerBound, int upperBound) // Same as previous
{
	int mid;

	if (upperBound > lowerBound)
	{
		mid = (lowerBound + upperBound) / 2;
		Mergesort(list, lowerBound, mid);
		Mergesort(list, mid + 1, upperBound);
		merge(list, lowerBound, upperBound, mid);
	}
}



void DisplayArray(ItemType data[], int N) // Dispplays array of integers
{
	for (int i = 1; i <= N; i++)
	{
		cout << '\t' << data[i - 1];
		if (i % 5 == 0) cout << endl;
	}
}

void DisplayArray(char data1[], int N) // Displays array of characters
{
	for (int i = 1; i <= N; i++)
	{
		cout << '\t' << data1[i - 1];
		if (i % 5 == 0) cout << endl;
	}
}

void radixsort(ItemType list[], int arraysize)
{
	int i, bucket[MAX], maxVal = 0, digitPosition = 1;
	for (i = 0; i < arraysize; i++) {
		if (list[i] > maxVal) maxVal = list[i];
	}

	int pass = 1;
	while (maxVal / digitPosition > 0) {

		int digitCount[10] = { 0 };


		for (i = 0; i < arraysize; i++)
			digitCount[list[i] / digitPosition % 10]++;


		for (i = 1; i < 10; i++)
			digitCount[i] += digitCount[i - 1];


		for (i = arraysize - 1; i >= 0; i--)
			bucket[--digitCount[list[i] / digitPosition % 10]] = list[i];


		for (i = 0; i < arraysize; i++)
			list[i] = bucket[i];


		digitPosition *= 10;
	}
}

void radixsort(char list[], int arraysize)
{
	int i, bucket[MAX], maxVal = 0, digitPosition = 1;
	for (i = 0; i < arraysize; i++) {
		if (list[i] > maxVal) maxVal = list[i];
	}

	int pass = 1;
	while (maxVal / digitPosition > 0) {

		int digitCount[10] = { 0 };


		for (i = 0; i < arraysize; i++)
			digitCount[list[i] / digitPosition % 10]++;


		for (i = 1; i < 10; i++)
			digitCount[i] += digitCount[i - 1];


		for (i = arraysize - 1; i >= 0; i--)
			bucket[--digitCount[list[i] / digitPosition % 10]] = list[i];


		for (i = 0; i < arraysize; i++)
			list[i] = bucket[i];


		digitPosition *= 10;
	}
}

