/**
 * 910. 最小差值 II
 *
 * 1. 对于一个元素,要么是+k,要么是-k
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

int smallestRangeII(int *nums, int numsSize, int k) {

  if (numsSize <= 0) {
    return 0;
  }

  // 排序
  insert_sort(nums, numsSize);

  int max_diff = nums[numsSize - 1] - nums[0]; // 差值最大值
  
  for (int i = 0; i < numsSize; i++)
  {
    
  }
  

  return 0;
}

int main(int argc, char **argv) {
  int nums[12] = {1, 2, 5, 4, 3, 9, 8, 7, 0, 6, 22, 81};
  insert_sort(nums, 12);
  for (int i = 0; i < 12; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}