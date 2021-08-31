// C++ program to check if there is a subset
// with sum divisible by m.
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset
// of arr[] with sum divisible by m
bool modularSum(int arr[], int n, int m)
{
	if (n > m)
		return true;

	// This array will keep track of all
	// the possible sum (after modulo m)
	// which can be made using subsets of arr[]
	// initialising boolean array with all false
	bool DP[m];
	memset(DP, false, m);

	// we'll loop through all the elements of arr[]
	for (int i=0; i<n; i++)
	{
		// anytime we encounter a sum divisible
		// by m, we are done
		if (DP[0])
			return true;

		// To store all the new encountered sum (after
		// modulo). It is used to make sure that arr[i]
		// is added only to those entries for which DP[j]
		// was true before current iteration.
		bool temp[m];
		memset(temp,false,m);

		// For each element of arr[], we loop through
		// all elements of DP table from 1 to m and
		// we add current element i. e., arr[i] to
		// all those elements which are true in DP
		// table
		for (int j=0; j<m; j++)
		{
			// if an element is true in DP table
			if (DP[j] == true)
			{
				if (DP[(j+arr[i]) % m] == false)

					// We update it in temp and update
					// to DP once loop of j is over
					temp[(j+arr[i]) % m] = true;
			}
		}

		// Updating all the elements of temp
		// to DP table since iteration over
		// j is over
		for (int j=0; j<m; j++)
			if (temp[j])
				DP[j] = true;


		// Also since arr[i] is a single element
		// subset, arr[i]%m is one of the possible
		// sum
		DP[arr[i]%m] = true;
	}

	return DP[0];
}

// Driver code
int main()
{
	int arr[] = {1, 3,5,7,9,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int m = 21;

	modularSum(arr, n, m) ? cout << "YES\n" :
							cout << "NO\n";

	return 0;
}
