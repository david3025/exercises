
#include <bits/stdc++.h> /*sort vecotor iostrem*/

using namespace std;

template <typename T>
void bucketSort(vector<T> &arr, int n)
{

	vector<T> b[n];

	for (int i=0; i<n; i++)
	{
		int bi = n*arr[i]; 
		b[bi].push_back(arr[i]);
	}
	
	for (int i=0; i<n; i++)
		sort(b[i].begin(), b[i].end());

	
	int index = 0;
	arr.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr.push_back(b[i][j]);
}

template <typename T>

void sortMixed(T arr[], int n)
{
	vector<T>Neg ;
	vector<T>Pos;

	
	for (int i=0; i<n; i++)
	{
		if (arr[i] < 0)


			Neg.push_back (-1 * arr[i]) ;
		else
		
			Pos.push_back (arr[i]) ;
	}

	bucketSort<T>(Neg, (int)Neg.size());
	bucketSort<T>(Pos, (int)Pos.size());


	for (int i=0; i < Neg.size(); i++)
		arr[i] = -1 * Neg[ Neg.size() -1 - i];


	for(int j=Neg.size(); j < n; j++)
		arr[j] = Pos[j - Neg.size()];
	printArray<T>(arr, n);
}


