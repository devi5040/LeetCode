# LeetCode

## Arrays Basics

### Prefix Sum

- It is an array where each element represents Sum of all elements from 0 to i.

```cpp
arr = [3, 1, 2, 5]
prefix = [3, 4, 6, 11]
```

- They convert the range sum queries from O(n) to O(1).

Example:-

- Find sum from index [l → r]

```cpp
sum(l, r) = prefix[r] - prefix[l-1]
// if(l==0)
sum(0, r) = prefix[r]
```

**Pattern Recognition — When to Use Prefix Sums**

- [-] Fast range sum queries : Sum of subarray from i to j
- [-] Count of something in a range : How many 1s from index i to j?
- [-] Check if a subarray has some property : Is there a subarray whose sum is k?
- [-] Transform array for fast queries : "Sum of matrix sub-rectangle" → 2D prefix sums
- [-] Find subarray with maximum/minimum sum : Kadane’s + prefix thought process

**Types of Prefix Sum**

1. Normal prefix sum

- Range sum queries
- Subarray sums

2. Prefix Sum of Frequencies

- Count of characters/numbers in a range
  E.g., number of vowels in substring

3. Prefix XOR

- Subarray XOR queries

4. Prefix Mod / Remainder Prefix

- Used in “subarray sum divisible by K”

5. 2D Prefix Sum (Matrix)

- Sum of submatrix in O(1)

**Traps**

1. Trap 1: Not handling l = 0 : Always check for boundary.
2. Trap 2: Using int instead of long : Prefix sum grows fast.
3. Trap 3: Forgetting to use HashMap for target-sum problems : E.g., “Subarray Sum Equals K”
4. Trap 4: Wrong formula for 2D prefix : sum = P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1]

**Formulas**

1. Range Sum
   prefix[i] = prefix[i-1] + arr[i]
   sum(l, r) = prefix[r] - prefix[l-1]
2. 2D Prefix Sum
   P[x][y] = P[x-1][y] + P[x][y-1] - P[x-1][y-1] + A[x][y]
3. Prefix Mod (Subarray Sum = K)
   (prefix[i] - prefix[j]) % k == 0  
    -> prefix[i] % k == prefix[j] % k

**Framework: How to solve prefix sum**
Step 1: Check if the problem asks:
range sum, subarray sum, count in range, matrix sum.
then use prefix sum to solve.
Step 2: Build the prefix array.
Step 3: Apply correct formula based on the case.
Step 4: If target subarray sum=k then use hashmap
key: prefix sum, value: frequency.
Step 5: Be careful with boundary l=0.
