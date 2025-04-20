# LeetCode 1992: Finding All Groups of Farmland

## Problem Analysis

In this problem:

1. We have a binary matrix `land` where:
   - `0` represents forest land
   - `1` represents farm land
2. Farm lands form rectangular "farm groups" where each group:
   - Contains only farm land (1's)
   - Forms a complete rectangle
   - Is not adjacent to any other farm group
3. We need to identify all farm groups by returning their coordinates as [r1, c1, r2, c2], where:
   - (r1, c1) is the top-left corner
   - (r2, c2) is the bottom-right corner

## Approach

The most efficient way to solve this is to:

1. Scan the matrix from top to bottom, left to right
2. When we find a '1', check if it's a top-left corner of a farm group
   - It's a top-left corner if there's no '1' above it and no '1' to its left
3. From this top-left corner, expand to find the bottom-right corner
4. Record the farm group and mark it as visited to avoid counting it again

## C++ Solution

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Check if this is the top-left corner of a farm group
                if (land[i][j] == 1 &&
                    (i == 0 || land[i-1][j] == 0) &&
                    (j == 0 || land[i][j-1] == 0)) {

                    int r1 = i, c1 = j;
                    int r2 = i, c2 = j;

                    // Expand to find the bottom-right corner
                    // First, expand right as far as possible
                    while (c2 + 1 < n && land[r2][c2 + 1] == 1) c2++;

                    // Then, expand down as far as possible
                    while (r2 + 1 < m && land[r2 + 1][c1] == 1) r2++;

                    // Add this farm group to the result
                    result.push_back({r1, c1, r2, c2});

                    // Mark this farm group as visited
                    for (int r = r1; r <= r2; r++) {
                        for (int c = c1; c <= c2; c++) {
                            land[r][c] = 0;
                        }
                    }
                }
            }
        }

        return result;
    }
};
```

## Time and Space Complexity

- **Time Complexity**: O(m×n), where m is the number of rows and n is the number of columns. In the worst case, we visit each cell at most twice: once during the scan and once when marking a farm group as visited.
- **Space Complexity**: O(1) excluding the output array. We only use a constant amount of extra space.

## Explanation of Key Steps

1. **Finding the top-left corner**: We check if the current cell is '1' and has no '1' above it and to its left.
2. **Expanding to find the bottom-right corner**:
   - We first expand to the right as far as possible
   - Then we expand downward as far as possible
3. **Marking as visited**: After finding a farm group, we mark all its cells as '0' to avoid counting them again.

The solution correctly handles the constraint that farm groups are rectangular and not adjacent to each other, allowing us to efficiently identify all farm groups in the given matrix.
