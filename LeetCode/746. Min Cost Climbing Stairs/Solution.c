#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 动态规划五部曲:
 * 1. 确定dp数组: dp[i] 表示爬上第i级阶梯的最低花费
 * 2. 确定递推公式: dp[i] += MIN(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
 * 因为付费完成后,可以向上爬 1 ~ 2阶梯
 * 3. 初始化dp数组
 * 4. 确定遍历顺序
 * 5. 遍历&打印dp数组
 */
#define MIN(val1, val2) (val1) > (val2) ? (val2) : (val1)
int minCostClimbingStairs(int *cost, int costSize) {
  int *dp = (int *)malloc((costSize + 1) * sizeof(int));
  for (int i = 0; i <= costSize; i++) {
    dp[i] = 0;
  }

  dp[0] = dp[1] = 0;
  for (int i = 2; i <= costSize; i++) {
    int nextMinCost = MIN(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    if (dp[i] < (INT_MAX - nextMinCost)) {
      dp[i] += nextMinCost;
    }
  }
  int res = dp[costSize];
  free(dp);
  return res;
}

int main(int argc, char **argv) {
  int coins[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  int coinsSize = 10;
  printf("---> %d \n", minCostClimbingStairs(coins, coinsSize));
  return 0;
}