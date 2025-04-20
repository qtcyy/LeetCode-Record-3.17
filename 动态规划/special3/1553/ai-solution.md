# 吃掉 N 个橘子的最少天数 - 解题报告

## 问题分析

题目要求我们找出吃掉 n 个橘子的最少天数，每天可以选择以下三种操作之一：

1. 吃掉 1 个橘子
2. 如果 n 能被 2 整除，吃掉 n/2 个橘子
3. 如果 n 能被 3 整除，吃掉 2\*(n/3)个橘子（即吃掉 2n/3 个橘子）

关键是要找到最优的吃橘子策略，使总天数最少。

## 解法一：记忆化搜索

### 思路

这类问题可以使用动态规划求解。定义函数`minDays(n)`表示吃掉 n 个橘子所需的最少天数。

对于每个状态 n，我们有三种可能的选择：

1. 吃掉 1 个橘子，剩下 n-1 个，需要 1 天 + minDays(n-1)
2. 如果 n 能被 2 整除，吃掉 n/2 个，剩下 n/2 个，需要 1 天 + minDays(n/2)
3. 如果 n 能被 3 整除，吃掉 2n/3 个，剩下 n/3 个，需要 1 天 + minDays(n/3)

但这里有一个关键优化：**如果 n 不能被 2 或 3 整除，我们可以先吃掉几个橘子，使剩余数量能被 2 或 3 整除**。例如，对于 n=10：

- 直接吃 1 个使 n=9（能被 3 整除），然后一次吃掉 2n/3=6 个，剩下 3 个
- 或者不用吃（n=10 本身能被 2 整除），直接一次吃掉 n/2=5 个，剩下 5 个

我们需要考虑所有可能的策略并选择最优的一个。

### 代码实现

```cpp
class Solution {
public:
    unordered_map<int, int> memo;

    int minDays(int n) {
        // 基本情况
        if (n <= 1) return n;

        // 如果已经计算过，直接返回
        if (memo.find(n) != memo.end()) return memo[n];

        // 尝试所有可能的策略

        // 策略1：使用操作2（如果n不能被2整除，先吃1个）
        int days1 = 1 + (n % 2) + minDays(n / 2);

        // 策略2：使用操作3（如果n不能被3整除，先吃1或2个）
        int days2 = 1 + (n % 3) + minDays(n / 3);

        // 选择最优策略
        memo[n] = min(days1, days2);
        return memo[n];
    }
};
```

### 关键公式解释

`1 + (n % 2) + minDays(n / 2)` 的含义：

- 如果 n 能被 2 整除，这就是 `1 + 0 + minDays(n/2)`，直接吃 n/2 个橘子用 1 天
- 如果 n 不能被 2 整除，这就是 `1 + 1 + minDays((n-1)/2)`，先吃 1 个橘子，然后再吃(n-1)/2 个

`1 + (n % 3) + minDays(n / 3)` 的含义：

- 如果 n 能被 3 整除，这就是 `1 + 0 + minDays(n/3)`，直接吃 2n/3 个橘子用 1 天
- 如果 n 除以 3 余 1，这就是 `1 + 1 + minDays((n-1)/3)`，先吃 1 个，然后再吃 2(n-1)/3 个
- 如果 n 除以 3 余 2，这就是 `1 + 2 + minDays((n-2)/3)`，先吃 2 个，然后再吃 2(n-2)/3 个

### 复杂度分析

- 时间复杂度：O(log n)。每次递归都会将问题规模缩小到原来的 1/2 或 1/3，递归深度为 O(log n)。
- 空间复杂度：O(log n)，用于存储记忆化数组和递归调用栈。

## 解法二：广度优先搜索(BFS)

### 思路

我们可以将这个问题视为一个图论问题，其中：

- 节点：表示剩余橘子数量
- 边：表示吃橘子的操作
- 目标：找到从 n 到 0 的最短路径

BFS 是解决最短路径问题的标准方法。

### 代码实现

```cpp
class Solution {
public:
    int minDays(int n) {
        // 使用队列进行BFS
        queue<int> q;
        q.push(n);

        // 使用集合记录已访问的状态
        unordered_set<int> visited;
        visited.insert(n);

        int days = 0;

        while (!q.empty()) {
            int size = q.size();

            // 处理当前层的所有节点
            for (int i = 0; i < size; i++) {
                int oranges = q.front();
                q.pop();

                // 如果已经吃完所有橘子，返回天数
                if (oranges == 0) return days;

                // 尝试三种操作

                // 操作1：吃1个橘子
                if (oranges > 0 && visited.find(oranges - 1) == visited.end()) {
                    q.push(oranges - 1);
                    visited.insert(oranges - 1);
                }

                // 操作2：如果能被2整除，吃n/2个橘子
                if (oranges % 2 == 0 && visited.find(oranges / 2) == visited.end()) {
                    q.push(oranges / 2);
                    visited.insert(oranges / 2);
                }

                // 操作3：如果能被3整除，吃2n/3个橘子
                if (oranges % 3 == 0 && visited.find(oranges / 3) == visited.end()) {
                    q.push(oranges / 3);
                    visited.insert(oranges / 3);
                }
            }

            // 天数增加
            days++;
        }

        return -1;  // 正常情况下不会到达这里
    }
};
```

### 改进版 BFS：优化状态转移

我们可以在 BFS 中加入与记忆化搜索相同的优化，即考虑先吃几个橘子使剩余数量能被 2 或 3 整除：

```cpp
class Solution {
public:
    int minDays(int n) {
        queue<pair<int, int>> q;  // 橘子数量和已用天数
        q.push({n, 0});

        unordered_set<int> visited;
        visited.insert(n);

        while (!q.empty()) {
            auto [oranges, days] = q.front();
            q.pop();

            if (oranges == 0) return days;

            // 优化1：如果剩余很少的橘子，直接吃完
            if (oranges <= 10) {
                return days + oranges;  // 直接一个一个吃完
            }

            // 尝试三种策略

            // 策略1：吃1个橘子
            if (visited.find(oranges - 1) == visited.end()) {
                q.push({oranges - 1, days + 1});
                visited.insert(oranges - 1);
            }

            // 策略2：吃n/2个橘子（如果可能）
            if (oranges % 2 == 0 && visited.find(oranges / 2) == visited.end()) {
                q.push({oranges / 2, days + 1});
                visited.insert(oranges / 2);
            }

            // 策略3：吃2n/3个橘子（如果可能）
            if (oranges % 3 == 0 && visited.find(oranges / 3) == visited.end()) {
                q.push({oranges / 3, days + 1});
                visited.insert(oranges / 3);
            }
        }

        return -1;
    }
};
```

### 复杂度分析

- 时间复杂度：O(log n)。由于可以将橘子数量除以 2 或 3，BFS 搜索深度为 O(log n)。
- 空间复杂度：O(log n)，用于存储队列和已访问节点集合。

## 两种方法的比较

1. **记忆化搜索**

   - 优点：代码简洁，状态转移更自然，能够处理更大的 n
   - 缺点：需要递归，栈溢出风险

2. **BFS**
   - 优点：直观体现了最短路径的思想，易于理解
   - 缺点：需要额外处理边界条件，对于非常大的 n 可能内存占用较高

## 示例分析

以 n=10 为例分析解题过程：

记忆化搜索：

- minDays(10) = min(1 + 0 + minDays(5), 1 + 1 + minDays(3))
  - minDays(5) = min(1 + 1 + minDays(2), 1 + 2 + minDays(1)) = min(4, 4) = 4
  - minDays(3) = min(1 + 1 + minDays(1), 1 + 0 + minDays(1)) = min(3, 2) = 2
- minDays(10) = min(5, 4) = 4

BFS：

- 第 0 天：剩余 10 个橘子
- 第 1 天：剩余 9 个（吃 1 个）或 5 个（吃 5 个，使用操作 2）
- 第 2 天：从 9 可到 8 或 3；从 5 可到 4 或 1
- 第 3 天：可到达多个状态，包括 0 和 1
- 第 4 天：到达 0

两种方法都得到最少需要 4 天。

## 总结

这道题是典型的状态转移问题，通过记忆化搜索或 BFS 都可以高效解决。关键在于正确建模并利用问题特性进行优化，特别是要认识到先吃几个橘子使剩余数量能被 2 或 3 整除的策略。这种"变形"状态转移的思想在很多算法问题中都有应用。

# Dijkstra 算法解决吃橘子问题：建图与边权分析

## 问题回顾

题目要求找出吃掉 n 个橘子的最少天数，每天可选择以下操作之一：

1. 吃掉 1 个橘子
2. 如果 n 能被 2 整除，吃掉 n/2 个橘子
3. 如果 n 能被 3 整除，吃掉 2n/3 个橘子（即 2\*(n/3)）

## Dijkstra 算法建图思路

将这个问题转化为最短路问题的关键在于构建**有向加权图**：

- 每个节点表示剩余橘子数量
- 边表示吃橘子的操作
- 边权重表示执行该操作需要的天数

### 特殊的边权设计

关键的创新点是边权的设计：

- 从 x 到 x-1 的边权为 1（吃一个橘子消耗 1 天）
- 从 x 到 x/2 的边权为(x mod 2) + 1
- 从 x 到 x/3 的边权为(x mod 3) + 1

#### 为什么这样设计边权？

这种设计体现了"预处理+批量操作"的思想：

1. **x→x/2 的边权分析**：

   - 当 x 为偶数时：可以直接执行操作 2，边权为 1
   - 当 x 为奇数时：需要先吃 1 个橘子（1 天）使其变为偶数，再执行操作 2（1 天），总共需要 2 天，即(1 mod 2) + 1 = 2

2. **x→x/3 的边权分析**：
   - 当 x 能被 3 整除时：直接执行操作 3，边权为 1
   - 当 x 除以 3 余 1 时：需要先吃 1 个橘子（1 天）使其能被 3 整除，再执行操作 3（1 天），总共 2 天，即(1 mod 3) + 1 = 2
   - 当 x 除以 3 余 2 时：需要先吃 2 个橘子（2 天）使其能被 3 整除，再执行操作 3（1 天），总共 3 天，即(2 mod 3) + 1 = 3

相比 BFS 解法，这种建图方式将"预处理+操作"合并为一条边，减少了状态数量，使算法更为简洁。

## 代码实现

```cpp
class Solution {
public:
    int minDays(int n) {
        // 优先队列，按天数升序排列
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // 存储从起点到各节点的最短距离
        unordered_map<int, int> dist;

        // 初始状态：n个橘子，0天
        pq.push({0, n});
        dist[n] = 0;

        while (!pq.empty()) {
            auto [days, oranges] = pq.top();
            pq.pop();

            // 如果当前状态不是最优，跳过
            if (days > dist[oranges]) continue;

            // 目标达成：吃完所有橘子
            if (oranges == 0) return days;

            // 操作1：吃一个橘子
            if (dist.find(oranges - 1) == dist.end() || dist[oranges - 1] > days + 1) {
                dist[oranges - 1] = days + 1;
                pq.push({days + 1, oranges - 1});
            }

            // 操作2：吃n/2个橘子（考虑预处理）
            int cost2 = (oranges % 2) + 1; // 如果是奇数，先吃1个再除以2
            int next2 = oranges / 2;
            if (dist.find(next2) == dist.end() || dist[next2] > days + cost2) {
                dist[next2] = days + cost2;
                pq.push({days + cost2, next2});
            }

            // 操作3：吃2n/3个橘子（考虑预处理）
            int cost3 = (oranges % 3) + 1; // 根据余数决定预处理成本
            int next3 = oranges / 3;
            if (dist.find(next3) == dist.end() || dist[next3] > days + cost3) {
                dist[next3] = days + cost3;
                pq.push({days + cost3, next3});
            }
        }

        return -1; // 理论上不会到达这里
    }
};
```

## 算法分析与优化

### 时间复杂度

- Dijkstra 算法的时间复杂度为 O(E log V)，其中 E 是边数，V 是节点数
- 在本问题中，节点数最多为 n，每个节点最多有 3 条出边
- 考虑到大多数节点只会被访问一次，实际时间复杂度接近 O(log n)

### 空间复杂度

- O(n)，用于存储距离表和优先队列
- 由于问题规模大幅缩小（每次除以 2 或 3），实际使用的空间接近 O(log n)

### 关键优化

1. **无需遍历整个状态空间**：由于使用优先队列，算法会优先处理天数少的状态
2. **合并操作减少状态转移**：将"预处理+批量操作"合并为一条边，避免了中间状态
3. **无需扩展访问过的次优状态**：通过 dist 数组剪枝，避免重复计算

## 与其他方法的比较

1. **相比记忆化搜索**：

   - Dijkstra 更直观地体现了"最短路径"的概念
   - 记忆化搜索通过自顶向下求解，而 Dijkstra 是自底向上

2. **相比普通 BFS**：
   - 普通 BFS 将每个操作视为相同权重（1 天）
   - 改进的 Dijkstra 考虑了"预处理+批量操作"的组合权重，减少了状态数量

## 这种建图方式的智慧

这种建图方式的精妙之处在于：

1. **捕捉了最优策略的本质**：当 n 不能被 2 或 3 整除时，最优策略是先吃掉几个橘子使其能被整除，然后再执行批量操作

2. **边权体现了组合操作**：(x mod k) + 1 的边权公式巧妙地计算了"预处理+批量操作"的总天数

3. **减少了状态空间**：通过合并多步操作为一步，大幅减少了需要考虑的状态数量

这种解法展示了图论建模的强大：将复杂问题转化为图上的最短路径，然后应用成熟的算法求解。边权的设计体现了对问题本质的深刻理解，是算法设计中的一种艺术。
