#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 动规五部曲
 * 1. 确定dp数组的下标与含义: 因为是斐波那契数列，所以dp数组含义已经确定: dp[i]
 * 表示第i个元素的值为dp[i]
 * 2. 确定递推数组: 因为是斐波那契数列，所以 dp[i] = dp[i-1] + dp[i-2];
 * 3. dp数组初始化 dp[0] = 0; dp[1]=1;
 * 4. 确定遍历顺序
 * 5. 遍历&打印dp数组
 */
int fib(int n) {
  int *dp = (int *)malloc((n + 1) * sizeof(int));
  if (n <= 1) {
    return n;
  }
  dp[0] = 0, dp[1] = 1;
  // printf("dp[0]=0\n");
  // printf("dp[1]=1\n");

  for (int i = 2; i <= n; i++) {
    // printf("dp[%d]=dp[%d] + dp[%d]\n", i, i - 1, i - 2);
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  int res = dp[n];
  free(dp);
  return res;
}

int main(int argc, char **argv) {
  printf("---> %d \n", fib(0));
  return 0;
}