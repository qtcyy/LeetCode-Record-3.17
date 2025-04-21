# 博弈动态规划详解

博弈动态规划（Game Theory DP）是解决竞争性决策问题的重要算法策略，在算法竞赛中经常出现。我将从基础概念到实际应用进行全面讲解。

## 基本概念

博弈 DP 通常解决两个玩家轮流行动的问题，每个玩家都以最优策略行动。我们通常讨论的是"公平组合游戏"（Impartial Combinatorial Games），具有以下特点：

- 两名玩家交替行动
- 信息完全公开，没有随机因素
- 游戏必然在有限步内结束
- 无法行动的玩家判负

## 必胜态与必败态

博弈问题的核心是分析当前状态是"必胜态"还是"必败态"：

- **必胜态(N 态/N-position)**: 当前玩家通过某种移动可以到达必败态
- **必败态(P 态/P-position)**: 无论当前玩家如何移动，对手都能处于必胜态

## 解题方法

### 1. 记忆化搜索

最直观的博弈 DP 实现是使用记忆化搜索：

```cpp
// 状态表示：true为必胜态，false为必败态
bool dfs(int state) {
    if (state已被计算) return memo[state];
    if (state是终止状态) return false; // 无法移动的玩家失败

    // 尝试所有可能的移动
    for (auto next_state : 所有可能的下一个状态) {
        if (!dfs(next_state)) { // 如果对手处于必败态
            memo[state] = true; // 则当前状态是必胜态
            return true;
        }
    }

    memo[state] = false; // 所有移动都导致对手处于必胜态，则当前状态是必败态
    return false;
}
```

### 2. 经典的 Nim 游戏

最基础的博弈 DP 问题是 Nim 游戏：有 n 堆石子，两名玩家轮流从任一堆取出任意数量的石子，不能取的玩家判负。

**结论**：当所有堆的石子数异或和为 0 时为必败态，否则为必胜态。

```cpp
bool isNimWinning(vector<int>& piles) {
    int xorSum = 0;
    for (int pile : piles) {
        xorSum ^= pile;
    }
    return xorSum != 0; // 异或和不为0时先手必胜
}
```

### 3. SG 函数

Sprague-Grundy 定理扩展了 Nim 游戏的结论，通过计算 SG 函数值来解决更复杂的博弈问题。

SG 函数定义：

- 终止状态的 SG 值为 0
- 非终止状态的 SG 值是所有后继状态的 SG 值的集合的 mex 值
  (mex: Minimum Excludant，即最小的不在集合中的非负整数)

```cpp
int sg(int state) {
    if (sg_memo[state] != -1) return sg_memo[state];
    if (终止状态判断) return 0;

    set<int> s; // 收集所有后继状态的SG值
    for (auto next_state : 所有可能的后继状态) {
        s.insert(sg(next_state));
    }

    // 计算mex值
    int mex = 0;
    while (s.count(mex)) mex++;

    return sg_memo[state] = mex;
}
```

对于多个独立子游戏，总的 SG 值是各子游戏 SG 值的异或和。SG 值为 0 表示必败态，否则为必胜态。

## 经典问题举例

### 例 1：取石子游戏

有一堆 n 个石子，两人轮流取石子，每次只能取 1、3 或 4 个，取走最后一个石子的人获胜。

```cpp
// DP方法计算必胜态
vector<bool> winningStates(int n) {
    vector<bool> dp(n + 1, false);
    // dp[i] = true表示面对i个石子时，当前玩家能获胜

    for (int i = 1; i <= n; i++) {
        // 尝试所有可能的取法
        for (int take : {1, 3, 4}) {
            if (i - take >= 0 && !dp[i - take]) {
                dp[i] = true; // 如果存在一种取法使对手必败，则当前状态是必胜态
                break;
            }
        }
    }
    return dp;
}
```

### 例 2：Nim 变种

有 n 堆石子，每堆石子数分别为 a[1], a[2], ..., a[n]。两名玩家轮流取石子，每次可以从任意一堆中取出任意多个石子，但不能不取。取走最后一个石子的人获胜。

解法：直接使用 Nim 博弈结论，计算异或和。

```cpp
bool canWinNim(vector<int>& piles) {
    int xorSum = 0;
    for (int pile : piles) {
        xorSum ^= pile;
    }
    return xorSum != 0; // 异或和不为0时先手必胜
}
```

### 例 3：有向图游戏

给定一个有向无环图，两名玩家轮流移动一枚棋子从起点到终点。走到终点的玩家获胜。

```cpp
// 示意代码，使用记忆化搜索
vector<int> memo; // -1表示未计算，0表示必败，1表示必胜

int dfs(vector<vector<int>>& graph, int node) {
    if (memo[node] != -1) return memo[node];
    if (graph[node].empty()) return memo[node] = 0; // 终点是必败态

    for (int next : graph[node]) {
        if (dfs(graph, next) == 0) {
            return memo[node] = 1; // 存在让对手必败的移动
        }
    }

    return memo[node] = 0; // 所有移动都让对手必胜
}
```

## 实际应用技巧

1. **状态表示**：清晰地表示游戏状态是关键
2. **状态转移**：明确从当前状态可以到达哪些后继状态
3. **必胜必败判定**：了解"必胜"意味着存在至少一个让对手必败的移动
4. **SG 函数**：复杂博弈问题通常需要计算 SG 函数
5. **优化**：对于状态空间大的问题，寻找游戏的数学规律或者使用记忆化搜索

博弈 DP 是算法竞赛中极具挑战性的一部分，需要对博弈论有深入理解，并熟练运用动态规划技巧。通过练习不同类型的博弈问题，你可以逐渐建立解决这类问题的直觉。
