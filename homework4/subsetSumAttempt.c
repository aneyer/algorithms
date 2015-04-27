// A Dynamic Programming solution for subset sum problem
#include <stdio.h>
#include <stdbool.h> //Allison's addition to this code (added so program would support bool variables)
 
// Returns true if there is a subset of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
 
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
     // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } 
 
     return subset[sum][n];
}

void test(int set[], int n, int sum){
  if (isSubsetSum(set, n, sum) == true){
     printf("Found a subset with given sum");
  }
  else{
     printf("No subset with given sum");
  }
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int set2[] = {3, 7, 77,1};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  int n2 = sizeof(set2)/sizeof(set2[0]);
  
 // isSubSetSum(set, n, sum);
  isSubSetSum(set2, n2, sum);
/*  printf("Test 1:");
  test(set, n, sum);
  printf("Test 2:");
  test(set2, n2, sum);
/*  if (isSubsetSum(set, n, sum) == true){
     printf("Test 1: Found a subset with given sum");
  }
  else{
     printf("No subset with given sum");
  }
  printf("Starting Test 2");
  if (isSubsetSum(set2, n2, sum) == true){
	  printf("Test 2: Found a subset with given sum");
  }
  else{
	printf("Test 2: No subset with given sum");
  }
  
  **/
  return 0;
}