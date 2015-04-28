
// A Dynamic Programming solution for subset sum problem
#include <stdio.h>
#include <stdbool.h> //Allison's addition to this code (added so program would support bool variables)

 
//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
// Returns true if there is a subset of set[] with sum equal to given sum
//assumption: function can't use one element repeatedly to make the sum. So, for example, the function can't repeatedly add one element of 3 to get 6. 
//assumption 2: if sum is 0 it is always true because you just pick nothing (The empty set is always a subset of every set).
bool isSubsetSum(int set[], int n, int sum){
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];
 
    // If sum is 0, then answer is true because just pick nothing (the empty set is always a subset of a set); see assumption 2 above. 
    for (int i = 0; i <= n; i++){
      subset[0][i] = true;
	}
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++){
      subset[i][0] = false;
	}
     // Fill the subset table in bottom up manner
     for (int i = 1; i <= sum; i++){
       for (int j = 1; j <= n; j++){
			subset[i][j] = subset[i][j-1];
			if (i >= set[j-1]){
				subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
			}
       }
     }
 
    /* // uncomment this code to print table
    for (int i = 0; i <= sum; i++){
        for (int j = 0; j <= n; j++){
			printf ("%4d", subset[i][j]);
		}
        printf("\n");
    } */
 
     return subset[sum][n];
}