#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 动态规划五部曲:
 * 1. 确定dp数组含义: 数组含义 & 下表含义:
 *    dp[j]：凑成总⾦额j的货币组合数为dp[j]
 * 2. 确定递推公式: dp[i] += dp[i - coins[j]]
 * 3. 初始化dp数组:
 * 4. 确定遍历顺序: 硬币无限个数，所以是求组合数,先遍历元素
 * 5. 遍历&打印dp数组
 */
int change(int amount, int *coins, int coinsSize)
{
  int *dp = (int *)malloc((amount + 1) * sizeof(int));
  for (int i = 0; i <= amount; i++)
  {
    dp[i] = 0;
  }
  dp[0] = 1;
  for (int i = 0; i < coinsSize; i++)
  {
    for (int j = 0; j <= amount; j++)
    {
      if ((j - coins[i] >= 0) && (dp[j] < INT_MAX - dp[j - coins[i]]))
      {
        dp[j] += dp[j - coins[i]];
      }
    }
  }
  int res = dp[amount];
  free(dp);
  return res;
}

int main(int argc, char **argv)
{
  int coins[] = {1, 2, 5};
  int coinsSize = 3;
  int amount = 5;
  printf("---> %d \n", change(amount, coins, coinsSize));
  return 0;
}