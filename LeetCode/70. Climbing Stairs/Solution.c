#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 爬楼梯:
 * 动归五部曲：
 * 1. 确定dp数组含义: dp[i]: 表示爬到第i级阶梯有dp[i]种方式
 * 2. 确定递推公式: dp[i] = dp[i-1] + dp[i-2];
 * 3. 初始化dp数组: dp[0] = 0 , dp[1] =1 , dp[2] = 1
 * 4. 确定遍历顺序
 * 5. 遍历/打印dp数组
 *
 */
int climbStairs(int n) {
  if (n <= 1) {
    return 1;
  }
  
  int *dp = (int *)malloc((n + 1) * sizeof(int));
  dp[0] = 1, dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  int res = dp[n];
  free(dp);

  return res;
}

int main(int argc, char **argv) {
  printf("---> %d \n", climbStairs(6));
  return 0;
}