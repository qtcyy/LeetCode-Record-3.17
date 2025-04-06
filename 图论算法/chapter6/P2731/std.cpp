#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int map[10001][10001]; // 记录两个点之间的路径个数
int du[10001];         // 辅助记录奇点
int lu[10001];         // 记录路径
int n, x, y, js = 0;
int maxn = 0;
void find(int i) //
{
  int j;
  for (j = 1; j <= maxn;
       ++j) // 而且这里不是n而是maxn因为n不是点的个数而是下面有多少行
  {
    if (map[i][j] >= 1) {
      map[i][j]--; // 删去边一次吗避免重复
      map[j][i]--; // z这里和一笔画不一样这里是累减而一笔画直接变成0
      find(j);
    }
  }
  lu[++js] = i;
}
int main() {
  freopen("a.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    map[x][y]++;
    map[y][x]++;
    du[x]++;
    du[y]++; // 记录出现的次数
    maxn = max(maxn, max(x, y));
  }
  int start = 1; // 默认奇点是1
  for (int i = 1; i <= maxn; ++i) {
    if (du[i] % 2) // 找到奇点
    {
      start = i; // 记录奇点
      break;     // 然后结束循环
    }
  }
  find(start); // 从奇点开始找
  for (int i = js; i >= 1; i--) {
    printf("%d\n", lu[i]); // 挨个输出路径并且换行
  }
  return 0;
}