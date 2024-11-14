#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * 动态规划:
 * 1. 确定dp数据含义
 * 2. 递推公式
 * 3. dp数据初始化
 * 4. 遍历顺序/打印dp
 *
 *   dp[i]: 凑成⽬标正整数为i的排列个数为dp[i]
 *   dp[i] += dp[i - nums[j]];
 *
 */
int combinationSum4(int *nums, int numsSize, int target)
{
  int *dp = (int *)malloc((target + 1) * sizeof(int));
  for (int i = 0; i < (target + 1); i++)
  {
    dp[i] = 0;
  }

  // 初始化dp数组
  dp[0] = 1;

  for (int i = 0; i <= target; i++)
  {
    for (int j = 0; j < numsSize; j++)
    {
      if ((i - nums[j] >= 0) && (dp[i] < INT_MAX - dp[i - nums[j]]))
      {
        dp[i] += dp[i - nums[j]];
      }
    }
  }
  return dp[target];
}

int main(int argc, char **argv)
{
  int nums[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111};
  int numsSize = 100;
  int target = 99;
  printf("---> %d \n", combinationSum4(nums, numsSize, target));
  return 0;
}