/**
 * 910. 最小差值 II
 *
 */

#include <stdio.h>
/**
 * 插入排序
 */
void insert_sort(int *nums, int numSize) {
  if (!numSize) {
    return;
  }

  for (int i = 0; i < numSize; i++) {
    for (int j = i; j > 0; j--) {
      if (nums[j] < nums[j - 1]) {
        int tmp_val = nums[j - 1];
        nums[j - 1] = nums[j];
        nums[j] = tmp_val;
      }
    }
  }
}

int smallestRangeII(int *nums, int numsSize, int k) { return 0; }

int main(int argc, char **argv) {
  int nums[12] = {1, 2, 5, 4, 3, 9, 8, 7, 0, 6, 22, 81};
  insert_sort(nums, 12);
  for (int i = 0; i < 12; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}