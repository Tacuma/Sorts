//Tacuma Solomon
//Computer Science 3

//You are asked to create a vector of 1,000 random integers (all < 10,000) and to save them in an output file.  
//Use vectors and iteractors thoughout your code. Your program can use the following code to generate a random number between 1 and 10,000.
//The resulting file of random integers should contain no duplicates.  

//Please write a Merge Sort program in C++ to sort the 1,000 random unique numbers


#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <vector>
#include <fstream>
using namespace std; 


inline void Swap(int& item1, int& item2);
bool check(vector<int>&,int); //checks the vector for duplicates
void output(vector<int>&,ofstream&);
void Merge(vector<int>&, int, int, int, int);
void MergeSort(vector<int>&, int, int);
void Footer();

int main() 
{     
     srand((unsigned)time(0));
	 vector<int> randomIntegers(1000);
	 ofstream outData;
	 outData.open("output.txt");
	 //Fills the vector with random integers
	 for(vector<int>::iterator i = randomIntegers.begin();i!=randomIntegers.end();
		 ++i)
	 {
		 //Checks for duplicates upon inserting
		 bool inserted = false;
		 while(inserted != true)
		 {
			int num = (rand()%10000)+1;
			if (check(randomIntegers,num) != true){
				*i = num;
				inserted = true;
			}
		 }
	 }
	 MergeSort(randomIntegers,0,randomIntegers.size()-1);
	 output(randomIntegers,outData);
	 cout << "Merge Sort complete." << endl;
	 Footer();
	 system("pause");
     return 0;
}



void Merge(vector<int>& values, int leftFirst, int leftLast,
		   int rightFirst, int rightLast)
// Post: values[leftFirst]..values[leftLast] and
//		 values[rightFirst]..values[rightLast] have been merged.
//		 values[leftFirst]..values[rightLast] are now sorted.
{ 
	vector<int> tempVector(1000);
	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if (values[leftFirst] < values[rightFirst])
		{
			tempVector[index] = values[leftFirst];
			leftFirst++;
		}
		else
		{
			tempVector[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}

	while (leftFirst <= leftLast)
	// Copy remaining items from left half.
	{
		tempVector[index] = values[leftFirst];
		leftFirst++;
		index++;
	}

	while (rightFirst <= rightLast)
	// Copy remaining items from right half.
	{
		tempVector[index] = values[rightFirst];
		rightFirst++;
		index++;
	}

	for (index = saveFirst; index <= rightLast; index++)
		values[index] = tempVector[index];
}

void MergeSort(vector<int>& values, int first, int last)
// Post: The elements in values are sorted by key.
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}


//Post Contents of item1 and item2 have been swapped.
inline void Swap(int& item1, int& item2)
{
	int tempItem;
	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}


 //Outputs the vector contents to a file
void output (vector<int>& randomIntegers, ofstream& outData)
{
	 for(vector<int>::iterator j = randomIntegers.begin();j!=randomIntegers.end();
		 ++j)
	 {
		 outData << *j << endl;
	 }

}

//Checks vector for duplicates
bool check(vector<int>& randomIntegers, int num)
{
	for(vector<int>::iterator i = randomIntegers.begin();i!=randomIntegers.end();++i)
	{
		if (*i == num)
			return true;
	}
	return false;
}

void Footer()
{
	cout << endl << endl;
	cout << "() Code by Tacuma Solomon " << endl;
	cout << "() Not for Redistribution or Reuse." << endl << endl;
}

/*
Merge Sort complete.


() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/