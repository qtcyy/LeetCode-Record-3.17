# 7.2 进阶

## 知识点介绍(AI)

### 启发式合并

### 直接回答

- 并查集（Union-Find）是一种数据结构，用于管理不重叠的集合，支持合并集合和查找元素所属集合的操作。
- 启发式合并是指在合并两个集合时，使用策略如按秩合并（Union by Rank）或按大小合并（Union by Size），以保持树结构平衡，提高效率。
- 按秩合并根据树的高度（秩）决定合并方向，秩小的树挂到秩大的树下；按大小合并则将小集合挂到大集合下。
- 这些策略与路径压缩结合，可使操作时间复杂度接近常数 O(α(N))，其中 α 是逆阿克曼函数，增长极慢。
- 一个意外的细节是，这两种合并策略在实际性能上差异不大，选择取决于是否需要知道集合大小。

#### 什么是并查集？

并查集用于管理多个不重叠的集合，每个集合用一棵树表示，树的根节点是集合的代表。

- **查找（Find）**：找到某个元素所属集合的根节点，用于判断两个元素是否在同一集合。
- **合并（Union）**：将两个集合合并为一个，通常通过让一个根节点的父节点指向另一个根节点。

#### 为什么需要启发式合并？

如果不优化，树的深度可能变深，查找操作时间复杂度可能达到 O(N)，效率低。启发式合并通过保持树平衡，减少深度。

#### 启发式合并的两种策略

- **按秩合并（Union by Rank）**：
  - 每个节点维护一个秩（树高度的上界）。
  - 合并时，若秩不同，将秩小的树挂到秩大的树下；若相等，任意挂一个并将新根的秩加 1。
  - 优点：直接控制树高度，适合追求效率的场景。
- **按大小合并（Union by Size）**：
  - 每个节点维护集合大小。
  - 合并时，将小集合挂到大集合下，更新大集合的大小。
  - 优点：方便知道集合大小，适合需要统计元素数的应用。

#### 示例

假设有元素 {1, 2, 3, 4}，初始每个元素自成一派，秩为 0：

- Union(1, 2)：1 和 2 秩相等，设 2 的父节点为 1，1 的秩变为 1。
- Union(3, 4)：类似，3 的秩变为 1。
- Union(1, 3)：1 和 3 秩相等，设 3 的父节点为 1，1 的秩变为 2。  
  最终树保持较平，查找效率高。

---

### 详细报告

#### 引言

并查集（Union-Find 或 Disjoint Set Union, DSU）是一种数据结构，用于管理一组不重叠的集合（即集合之间没有公共元素）。它主要用于解决连通性问题，例如图的连通分量或等价关系的分组。启发式合并是并查集优化中的关键策略，通过在合并操作中选择合适的方式保持树结构平衡，从而提高查找和合并的效率。本报告将详细解释并查集的定义、基本操作，以及启发式合并的两种主要策略——按秩合并和按大小合并，分析它们的实现和性能。

#### 并查集的定义与基本操作

并查集存储一组不重叠的集合，每个集合用一棵树表示，树的根节点是集合的代表。每个节点有一个父节点指针，初始时每个元素自成一派（即父节点指向自身）。  
主要操作包括：

- **Find**：给定一个元素，找到它所属集合的代表（通常是根节点），通过递归或迭代向上查找父节点直到根（父节点等于自身）。
- **Union**：将两个集合合并为一个，方法是找到两个元素的根节点，然后让一个根节点的父节点指向另一个根节点。

没有优化时，树的深度可能变深，导致 Find 操作时间复杂度为 O(N)，Union 操作也可能达到 O(N)，整体效率较低。

#### 优化的必要性

为了提高性能，需要对 Find 和 Union 操作进行优化。常用的优化技术包括：

1. **路径压缩（Path Compression）**：在 Find 操作中，将路径上的所有节点直接指向根节点，使树变平。
2. **启发式合并**：在 Union 操作中，选择合适的方式合并两个树，以保持树的高度较低，减少 Find 操作的深度。

路径压缩主要优化 Find 操作，而启发式合并则针对 Union 操作，两种技术结合可使并查集的 amortized 时间复杂度达到近乎常数 O(α(N))，其中 α 是逆阿克曼函数，增长极慢，实际应用中几乎为常数。

#### 启发式合并的策略

启发式合并是指在 Union 操作中，根据某些规则决定如何合并两个树，以保持树结构平衡。以下是两种主要策略：

##### 按秩合并（Union by Rank）

- **定义**：每个节点维护一个秩（rank），初始为 0，秩是树高度的上界。
- **合并规则**：
  - 找到两个集合的根节点（使用 Find 操作）。
  - 比较它们的秩：
    - 若秩不同，将秩小的树的根节点挂到秩大的树的根节点下，不改变秩。
    - 若秩相等，任意选择一个根节点作为新根，另一个根节点的父节点指向它，并将新根的秩加 1。
- **优点**：直接控制树的高度，适合追求效率的场景。
- **实现细节**：需要额外存储每个节点的秩，通常初始化为 0，合并时更新。秩的存储空间为 O(log log N) 位，总空间复杂度为 O(N log log N) 位。
- **时间复杂度**：与路径压缩结合，Find 和 Union 操作的 amortized 时间复杂度为 O(α(N))。

##### 按大小合并（Union by Size）

- **定义**：每个节点维护一个大小（size），表示以该节点为根的子树包含的元素个数，初始为 1。
- **合并规则**：
  - 找到两个集合的根节点。
  - 比较它们的大小：将较小集合的根节点挂到较大集合的根节点下，并更新较大集合的大小（新大小为两集合大小之和）。
- **优点**：方便知道集合大小，适合需要统计元素数的应用，如网络连通性分析中计数连通分量的大小。
- **实现细节**：需要额外存储每个节点的大小，空间复杂度为 O(N)。合并时需要更新大小，操作简单。
- **时间复杂度**：与路径压缩结合，Find 和 Union 操作的 amortized 时间复杂度也为 O(α(N))。

#### 两种策略的比较

以下是按秩合并和按大小合并的详细对比：

| 特性         | 按秩合并（Union by Rank）      | 按大小合并（Union by Size）      |
| ------------ | ------------------------------ | -------------------------------- |
| 存储额外信息 | 每个节点的秩，O(log log N) 位  | 每个节点的大小，O(N) 位          |
| 合并决策依据 | 树的高度（秩）                 | 集合的元素个数（大小）           |
| 效率         | 直接控制树高度，Find 更快      | 同样高效，但可能需要更多更新操作 |
| 适用场景     | 追求极致效率，无需知道集合大小 | 需要知道集合大小，如计数连通分量 |
| 实现复杂度   | 稍复杂，需要维护秩             | 简单，维护大小直观               |

从理论上，两种策略的 amortized 时间复杂度相同，但按秩合并在实际性能上可能略优，因为它更直接地控制树的高度。按大小合并在某些应用中更实用，例如需要频繁查询集合大小。

#### 示例分析

假设有元素 {1, 2, 3, 4, 5}，初始每个元素自成一派，秩为 0，大小为 1。

- **按秩合并**：

  - Union(1, 2)：1 和 2 秩相等，设 2 的父节点为 1，1 的秩变为 1。
  - Union(3, 4)：3 和 4 秩相等，设 4 的父节点为 3，3 的秩变为 1。
  - Union(1, 3)：1 的秩为 1，3 的秩为 1，设 3 的父节点为 1，1 的秩变为 2。
  - Union(5, 1)：5 的秩为 0，1 的秩为 2，设 5 的父节点为 1，1 的秩不变。
  - 最终树根为 1，深度较浅，Find 操作高效。

- **按大小合并**：
  - Union(1, 2)：1 和 2 大小相等，设 2 的父节点为 1，1 的新大小为 2。
  - Union(3, 4)：类似，3 的新大小为 2。
  - Union(1, 3)：1 的大小为 2，3 的大小为 2，设 3 的父节点为 1，1 的新大小为 4。
  - Union(5, 1)：5 的大小为 1，1 的大小为 4，设 5 的父节点为 1，1 的新大小为 5。
  - 结果类似，树保持平衡。

#### 路径压缩的补充

虽然用户主要关注启发式合并，但路径压缩是并查集优化的另一重要部分。在 Find 操作中，路径压缩使路径上的所有节点直接指向根节点，与启发式合并结合可进一步提高效率。例如，在上述示例中，Find(2) 时，若路径压缩生效，2 将直接指向根 1，未来查找更快。

#### 实际应用与注意事项

启发式合并广泛用于图算法，如最小生成树（Kruskal 算法）、网络连通性分析等。

- **注意事项**：实现时需正确维护秩或大小，避免错误更新导致树不平衡。常见错误包括忘记路径压缩或秩更新不一致。
- **选择建议**：若只需高效性，选择按秩合并；若需知道集合大小，选择按大小合并。

#### 结论

启发式合并是并查集优化的核心，通过按秩合并和按大小合并保持树结构平衡，与路径压缩结合使操作时间复杂度接近常数 O(α(N))。两种策略各有优势，适合不同应用场景，实际选择需根据需求权衡。

#### 关键引用

- [Disjoint Set Union - Algorithms for Competitive Programming](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
- [Disjoint-set data structure - Wikipedia](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
- [Disjoint Set Union (Union Find) - Prateek Garg](https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/)
- [r/algorithms on Reddit: Union Find Algorithm](https://www.reddit.com/r/algorithms/comments/1e9cxgq/union_find_algorithm/)
- [Disjoint set union data structure | by Oleksandr Klymenko | Medium](https://medium.com/@alxkm/disjoint-set-union-data-structure-7a913b5057f1)
- [Introduction to Disjoint Set (Union-Find Algorithm) - GeeksforGeeks](https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/)
- [Disjoint-Set, Union By Rank & Path Compression :: AlgoTree](https://www.algotree.org/algorithms/disjoint_set/)
- [18.2. Union/Find and the Parent Pointer Implementation — OpenDSA Data Structures and Algorithms Modules Collection](https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/UnionFind.html)
- [Disjoint Set - Scaler Blog](https://www.scaler.in/disjoint-set/)
- [Disjoint–Set Data Structure (Union–Find Algorithm) | Techie Delight](https://www.techiedelight.com/disjoint-set-data-structure-union-find-algorithm/)

---

**题目列表**

- [1202. 交换字符串中的元素](https://leetcode.cn/problems/smallest-string-with-swaps/description/)
- [1061. 按字典序排列最小的等效字符串](https://leetcode.cn/problems/lexicographically-smallest-equivalent-string/description/)
- [765. 情侣牵手](https://leetcode.cn/problems/couples-holding-hands/description/)
- [947. 移除最多的同行或同列石头](https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/description/)
- [839. 相似字符串组](https://leetcode.cn/problems/similar-string-groups/description/)
- [1970. 你能穿过矩阵的最后一天](https://leetcode.cn/problems/last-day-where-you-can-still-cross/description/)
- [2076. 处理含限制条件的好友请求](https://leetcode.cn/problems/process-restricted-friend-requests/description/)
- [1579. 保证图可完全遍历](https://leetcode.cn/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/)

往下部分题目等待二刷
