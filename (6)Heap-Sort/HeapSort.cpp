//Tacuma Solomon
//Computer Science 3

//You are asked to create a vector of 1,000 random integers (all < 10,000) and to save them in an output file.  
//Use vectors and iteractors thoughout your code. Your program can use the following code to generate a random number between 1 and 10,000.
//The resulting file of random integers should contain no duplicates.  

//Please write a Heap Sort program in C++ to sort the 1,000 random unique numbers


#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <vector>
#include <fstream>
using namespace std; 


inline void Swap(int& item1, int& item2);
bool check(vector<int>&,int); //checks the vector for duplicates
void outputIntegers(vector<int>&,ofstream&);
void ReheapDown(vector<int>&,int,int);
void HeapSort(vector<int>&, int);
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
	 HeapSort(randomIntegers,randomIntegers.size());
	 outputIntegers(randomIntegers,outData);
	 cout << "Heap Sort complete" << endl;
	 Footer();
	 system("pause");
     return 0;
}

void ReheapDown(vector<int>& values, int root, int bottom)
// Post: Heap property is restored.
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root*2+1;
	rightChild = root*2+2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (values[leftChild] <= values[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (values[root] < values[maxChild])
		{
			Swap(values[root], values[maxChild]);
			ReheapDown(values, maxChild, bottom);
		}
	}
}


void HeapSort(vector<int>& values, int numValues)
// Assumption: Function ReheapDown is available.
// Post: The elements in the array values are sorted by key.
{
	int index;
	
	// Convert the array of values into a heap.
	for (index = numValues/2 - 1; index >= 0; index--)
		ReheapDown(values, index, numValues-1);

	// Sort the array.
	for (index = numValues - 1; index >=1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index -1);
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
void outputIntegers (vector<int>& randomIntegers, ofstream& outData)
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
Heap Sort complete


() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/