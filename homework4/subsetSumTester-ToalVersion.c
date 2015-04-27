#include <assert.h>
#include <stdbool.h>
#include "subsetSum.c"
//a better tester: authored by Toal
int main() {
  int set1[] = {3, 34, 4, 12, 5, 2};
  int set2[] = {3, 7, 77, 1};

  assert(!isSubsetSum(set1, 7, 0));
  assert(!isSubsetSum(set1, 7, 1));
  assert(!isSubsetSum(set1, 7, 1347856340));
  assert(isSubsetSum(set1, 7, 4));
  assert(isSubsetSum(set1, 7, 21));

  return 0;
}