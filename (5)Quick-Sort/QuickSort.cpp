//Tacuma Solomon
//Computer Science 3

//You are asked to create a vector of 1,000 random integers (all < 10,000) and to save them in an output file.  
//Use vectors and iteractors thoughout your code. Your program can use the following code to generate a random number between 1 and 10,000.
//The resulting file of random integers should contain no duplicates.  

//Please write a Quick Sort program in C++ to sort the 1,000 random unique numbers


#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <vector>
#include <fstream>
using namespace std; 


inline void Swap(int& item1, int& item2);
bool check(vector<int>&,int); //checks the vector for duplicates
void output(vector<int>&,ofstream&);
void Split(vector<int>&, int, int, int&);
void QuickSort(vector<int>&, int, int);
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
	 QuickSort(randomIntegers,0,randomIntegers.size()-1);
	 output(randomIntegers,outData);
	 cout << "Quick Sort complete." << endl;
	 Footer();
	 system("pause");
     return 0;
}


void Split(vector<int>& values, int first, int last, int& splitPoint)
{
	int splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do
	{
		onCorrectSide = true;
		while (onCorrectSide)				// Move first toward last.
			if (values[first] > splitVal)
				onCorrectSide = false;
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}
			onCorrectSide = (first <= last);
			while (onCorrectSide)
			
				if (values[last] <= splitVal)
					onCorrectSide = false;
				else
				{
					last--;
					onCorrectSide = (first <= last);
				}

			if (first < last)
			{
				Swap(values[first], values[last]);
				first++;
				last--;
			}
	} while (first <= last);

	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);
}
			

void QuickSort(vector<int>& values, int first, int last)
{
	if (first < last)
	{
		int splitPoint;

		Split(values, first, last, splitPoint);
		// values[first]..values[splitPoint-1] <= splitVal
		// values[splitPoint] = spilVal
		// values[splitPoint+1]..values[last] > splitVal

		QuickSort(values, first, splitPoint-1);
		QuickSort(values, splitPoint+1, last);
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
Quick Sort complete.


() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/