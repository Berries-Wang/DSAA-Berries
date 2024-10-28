#include <stdio.h>

/**
 * 910. 最小差值 II
 *
 * 1. 对于一个元素,要么是+k,要么是-k
 * 2. nums 的 分数 是 nums 中最大元素和最小元素的差值。
 *   ===> 需要转换后的最大最小值之差,因此，需要先求出最大值和最小值，再比较其差值
 * 3. so , 审题要清楚
 */

/**
 * 插入排序
 */
void insert_sort(int *nums, int numSize)
{
  if (!numSize)
  {
    return;
  }

  for (int i = 0; i < numSize; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (nums[j] < nums[j - 1])
      {
        int tmp_val = nums[j - 1];
        nums[j - 1] = nums[j];
        nums[j] = tmp_val;
      }
    }
  }
}

#define MIN_VAL(val1, val2) (val1) > (val2) ? (val2) : (val1)
#define MAX_VAL(val1, val2) (val1) > (val2) ? (val1) : (val2)

int smallestRangeII(int *nums, int numsSize, int k)
{

  if (numsSize <= 0)
  {
    return 0;
  }

  // 排序
  insert_sort(nums, numsSize);

  int the_diff = nums[numsSize - 1] - nums[0]; // 差值最大值

  for (int i = 0; i < numsSize - 1; i++)
  { // i之前的值都+k , i之后的值都-k ;临界的i怎么找呢?
    int max_val = MAX_VAL(nums[numsSize - 1] - k, nums[i] + k);
    int min_val = MIN_VAL(nums[0] + k, nums[i + 1] - k);

    // 需要符合题干： 分数是调整后数组的最大值 最小值 之差
    the_diff = MIN_VAL(the_diff, max_val - min_val);
  }

  return the_diff;
}

int main(int argc, char **argv)
{
  int k = 3;
  int length = 3;
  int nums[] = {1, 3, 6};
  insert_sort(nums, length);
  for (int i = 0; i < length; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");

  printf("最小差集: %d \n", smallestRangeII(nums, length, k));
  return 0;
}