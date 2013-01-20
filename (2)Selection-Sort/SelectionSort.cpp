//Tacuma Solomon
//Computer Science 3

//You are asked to create a vector of 1,000 random integers (all < 10,000) and to save them in an output file.  
//Use vectors and iteractors thoughout your code. Your program can use the following code to generate a random number between 1 and 10,000.
//The resulting file of random integers should contain no duplicates.  

//Please write a Selection sort program in C++ to sort the 1,000 random unique numbers


#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <vector>
#include <fstream>
using namespace std; 


inline void Swap(int& item1, int& item2);
bool check(vector<int>&,int); //checks the vector for duplicates
void output(vector<int>&,ofstream&);
int MinIndex(vector<int>& values, int startIndex, int endIndex);
void SelectionSort(vector<int>& values, int numValues);
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
	 SelectionSort(randomIntegers, randomIntegers.size());
	 output(randomIntegers,outData);
	 cout << "Selection Sort complete." << endl;
	 Footer();
	 system("pause");
     return 0;
}


//Post Contents of item1 and item2 have been swapped.
inline void Swap(int& item1, int& item2)
{
	int tempItem;
	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}


//Post: Returns the index of the smallest value in 
//		values[startIndex]..values[endIndex].
int MinIndex(vector<int>& values, int startIndex, int endIndex)
{
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
		if (values[index] < values[indexOfMin])
			indexOfMin = index;
	return indexOfMin;
}


//Post: The elements in the array values are sorted key.
void SelectionSort(vector<int>& values, int numValues)
{
	int endIndex = numValues-1;
	for (int current = 0; current < endIndex; current++)
		Swap(values[current], 
			values[MinIndex(values, current, endIndex)]);
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
Selection Sort complete.


() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/