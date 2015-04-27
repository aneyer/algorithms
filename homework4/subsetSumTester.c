// Driver program to test above function
#include <stdbool.h> //Allison's addition to this code (added so program would support bool variables)
#include "subsetSum.c" //Allison's addition to this code so tester file can see subsetSum.c file

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
  
  printf("Test 1:");
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