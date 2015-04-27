#include <assert.h>
#include <stdbool.h> //Allison's addition to this code (added so program would support bool variables)
#include "originalSubsetSum.c" //Allison's addition to this code so tester file can see originalSubsetSum.c file

int main() {
  int set1[] = {3, 34, 4, 12, 5, 2};
  int set2[] = {3, 7, 77, 1};

  int set3[]= {0, 12344, 9,2};
  int zeroSet[]= {0,0,0};
  int threeSet[] = {3};
  int repeated3Set[] = {3,3};
  int zeroSum = 0;
  int sum = 9;
  int sixSum = 6;
  int n = sizeof(set1)/sizeof(set1[0]);
  int n2 = sizeof(set2)/sizeof(set2[0]);
  int nZeroSet = sizeof(zeroSet)/sizeof(zeroSet[0]);
  int n3 = sizeof(set3)/sizeof(set3[0]);
  int threeSetN = sizeof(threeSet)/sizeof(threeSet[0]);
  int repeated3SetN = sizeof(repeated3Set)/sizeof(repeated3Set[0]);

  assert(isSubsetSum(set1, n, 0)); //assumption: null set is always a subset of set
  assert(!isSubsetSum(set1, n, 1));
  assert(!isSubsetSum(set1, n, 1347856340));
  assert(isSubsetSum(set1, n, 4));
  assert(isSubsetSum(set1, n, 21));
	
  assert(!isSubsetSum(threeSet, threeSetN, sixSum)); //I assume that function can't use one element repeatedly to make the sum. So, for example, can't repeatedly add 3 to get 6
  assert(isSubsetSum(repeated3Set, repeated3SetN, sixSum));
  assert(isSubsetSum(set1, n, sum));
  assert(!isSubsetSum(set2, n2, sum)); // should be false; has NO subset; so use ! to flip false to true and assert true
  assert(isSubsetSum(set3, n3, zeroSum));
  assert(isSubsetSum(set3, n3, sum));
  assert(!isSubsetSum(zeroSet, nZeroSet, sum));
  assert(isSubsetSum(set3, n3, zeroSum));
  
  return 0;
}
