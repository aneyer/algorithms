
// A Dynamic Programming solution for subset sum problem
#include <stdio.h>
#include <stdbool.h> //Allison's addition to this code (added so program would support bool variables)

 
// Returns true if there is a subset of set[] with sun equal to given sum
//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
bool isSubsetSum(int set[], int n, int sum){
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];
 
    // Allison's modification to this code: incorrect logic regarding the sum of zero. I rewrote the next for loop below and explained the logic below:
	//If sum is 0, then answer is true for an i that is 0 because only 0 = 0 (Allison modification because despite what the website thinks, adding nonzero numbers will not make it equal to 0. 
	subset[0][0] = true;
    for (int i = 1; i <= n; i++){ ////For all other cases (i.e. 1 to number of elements in set), 
      subset[0][i] = false; //when the sum is 0, then the answer is false because non-zero sums do not equal 0. 
	} 
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++){
      subset[i][0] = false;
	}
	
     // Fill the subset table in bottom up manner
     for (int i = 0; i <= sum; i++){ //Allison modification: changed i to include 0 so the table calculates the formula for all rows. 
        for (int j = 1; j <= n; j++){
			subset[i][j] = subset[i][j-1];
			if (i >= set[j-1]){
			  subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
			}
        }
     }
 
    // uncomment this code to print table
	printf("\nTable: \n");
     for (int i = 0; i <= sum; i++){
       for (int j = 0; j <= n; j++){
          printf ("%4d", subset[i][j]);
	   }
       printf("\n");
     } 
    
     return subset[sum][n];
}