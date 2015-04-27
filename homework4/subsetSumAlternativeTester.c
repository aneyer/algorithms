// Driver program to test above function
#include <stdbool.h> //Allison's addition to this code (added so program would support bool variables)
#include "subsetSumAlternativeApproach.c" //Allison's addition to this code so tester file can see subsetSum.c file

void test(int set[], int n, int sum){
  if (isSubsetSum(set, n, sum) == true){
     printf("Found a subset with given sum");
  }
  else{
     printf("No subset with given sum");
  }
}

int main(){
  int set[] = {3, 34, 4, 12, 5, 2};
  int set2[] = {3, 7, 77,1};
  int set3[]= {0, 12344, 9,2};
  int zeroSet[]= {0,0,0};
  int threeSet[] = {3};
  int repeated3Set[] = {3,3};
  int zeroSum = 0;
  int sum = 9;
  int sixSum = 6;
  int n = sizeof(set)/sizeof(set[0]);
  int n2 = sizeof(set2)/sizeof(set2[0]);
  int nZeroSet = sizeof(zeroSet)/sizeof(zeroSet[0]);
  int n3 = sizeof(set3)/sizeof(set3[0]);
  int threeSetN = sizeof(threeSet)/sizeof(threeSet[0]);
  int repeated3SetN = sizeof(repeated3Set)/sizeof(repeated3Set[0]);
  printf("\n threeSet Test:");
  test(threeSet, threeSetN, sixSum); //I assume that function can't use one element repeatedly to make the sum. So, for example, can't repeatedly add 3 to get 6
  printf("\n repeated3Set Test:");
  test(repeated3Set, repeated3SetN, sixSum);
  printf("should find subset since 3+3 = 6");
  printf("\n\n\n*********");
  printf("\n\nTest 1:");
  test(set, n, sum);
  printf("\nshould be: true; has subset");
  printf("\n\nTest 2:");
  test(set2, n2, sum);
  printf("\nshould be: false; has NO subset");
  printf("\n\nTest 3 (zeroSum):");
  test(set3, n3, zeroSum);
  printf("\nshould be: true; has subset");  
  printf("\n\nTest 3:");
  test(set3, n3, sum);
  printf("\nshould be: true; has subset");
  printf("\n\nZero Set Test:");
  test(zeroSet, nZeroSet, sum);
  printf("\nshould be: false; has NO subset");
  printf("\n\nZero Set Test (zeroSum):");
  test(set3, n3, zeroSum);
  printf("\nshould be: true; has subset");
  
  return 0;
}