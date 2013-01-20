//Tacuma Solomon
//Computer Science 3

//You are asked to create a vector of 1,000 random integers (all < 10,000) and to save them in an output file.  
//Use vectors and iteractors thoughout your code. Your program can use the following code to generate a random number between 1 and 10,000.
//The resulting file of random integers should contain no duplicates.  

//Please write a Radix Sort program in C++ to sort the 1,000 random unique numbers


#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <vector>
#include <fstream>
#include <cmath>
#include "QueType.h"
using namespace std; 


inline void Swap(int& item1, int& item2);
bool check(vector<int>&,int); //checks the vector for duplicates
void outputIntegers(vector<int>&,ofstream&);
void CollectQueues(vector<int>&, QueType[], int);
void RadixSort(vector<int>&, int, int, int);
int Position(int,int);
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
	 RadixSort(randomIntegers,randomIntegers.size(),5,10);
	 outputIntegers(randomIntegers,outData);
	 cout << "Radix Sort complete" << endl;
	 Footer();
	 system("pause");
     return 0;
}

void RadixSort(vector<int>& values, int numValues, int numPositions, int radix)
// Post: Elements in values are in order by key.
{
	QueType queues[10];
	// With default constructor, each queue size is 500
	int whichQue;

	for (int position = 1; position <= numPositions; position++)
	{
		for (int counter = 0; counter < numValues; counter++)
		{
			whichQue = Position(values[counter],position);
			queues[whichQue].Enqueue(values[counter]);
		}
		CollectQueues(values, queues, radix);
	}
}

void CollectQueues(vector<int>& values, QueType queues[], int radix)
// Post: queues are concatenated with queue[0]'s on top and 
//	     queue[9]'s on the bottom and copied into values
{
	int index = 0;
	int item;

	for (int counter = 0; counter < radix; counter++)
	{
		while (!queues[counter].IsEmpty())
		{
			queues[counter].Dequeue(item);
			values[index] = item;
			index++;
		}
	}
}

//Returns the digit of the corresponding position
int Position(int itemKey, int position)
{
	int result;
	result = (int)(itemKey/pow(10,position-1)) % 10;
	return result;
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
Radix Sort complete


() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/