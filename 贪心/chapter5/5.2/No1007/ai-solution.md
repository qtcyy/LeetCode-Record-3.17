# LeetCode 1007: Minimum Domino Rotations For Equal Row

## Problem Analysis

In this problem:

1. We have a row of dominoes, each with a top and bottom value (from 1 to 6)
2. We can rotate any domino, swapping its top and bottom values
3. We need to find the minimum number of rotations needed to make either all tops the same or all bottoms the same
4. If it's impossible, we should return -1

## Key Insights

The key insight is that if we want to make all tops (or all bottoms) equal to a certain value, then every domino must have that value on either its top or bottom. If any domino doesn't have that value on either side, it's impossible to achieve our goal.

Given these constraints, we only need to check two possible values:

1. The value on the top of the first domino
2. The value on the bottom of the first domino

This is because for a solution to exist, all dominoes must have the target value on at least one side. So the target value must be present on the first domino.

## Solution Approach

For each of the two candidate values:

1. Check if it's possible to make all tops equal to that value
2. Check if it's possible to make all bottoms equal to that value
3. Return the minimum number of rotations needed

For a specific value, to make all tops equal to it:

- Count how many dominoes don't have this value on top (these need to be rotated)
- If any domino doesn't have this value on either side, it's impossible

Similarly for making all bottoms equal to the value.

## C++ Implementation

```cpp
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        // Check if it's possible with the value on top of the first domino
        int result = checkValue(tops[0], tops, bottoms);
        if (result != -1) return result;

        // If that didn't work, check with the value on bottom of the first domino
        if (bottoms[0] != tops[0]) {
            return checkValue(bottoms[0], tops, bottoms);
        }

        return -1;  // No solution found
    }

    int checkValue(int value, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int topRotations = 0;  // Rotations needed to make all tops equal to value
        int bottomRotations = 0;  // Rotations needed to make all bottoms equal to value

        for (int i = 0; i < n; i++) {
            // If the domino doesn't have value on either side, it's impossible
            if (tops[i] != value && bottoms[i] != value) {
                return -1;
            }

            // Count rotations needed for each approach
            if (tops[i] != value) {
                topRotations++;
            }
            if (bottoms[i] != value) {
                bottomRotations++;
            }
        }

        // Return the minimum number of rotations
        return min(topRotations, bottomRotations);
    }
};
```

## Time and Space Complexity

- **Time Complexity**: O(n), where n is the number of dominoes. We scan through the array at most three times.
- **Space Complexity**: O(1), as we only use a constant amount of extra space.

## Example Analysis

Consider `tops = [2,1,2,4,2,2]` and `bottoms = [5,2,6,2,3,2]`:

1. First we try value = 2 (top of first domino):

   - To make all tops 2, we need to rotate dominoes at positions 1 and 3
   - To make all bottoms 2, we need to rotate dominoes at positions 0, 2, and 4
   - Minimum rotations = min(2, 3) = 2

2. We don't need to try value = 5 (bottom of first domino) since we already found a solution.

The minimum number of rotations needed is 2.
