## Goal:  

Find the **maximum sum of a contiguous subarray** in an array of integers (may include negatives).

## Core Idea:

At each index, decide:

- **Extend** the current subarray, or
- **Start a new** subarray from this index

If the running sum becomes negative → reset to 0 (start over).


```cpp
long long curr_sum = 0, max_sum = LLONG_MIN;
for (int x : nums) {
    curr_sum += x;
    max_sum = max(max_sum, curr_sum);
    if (curr_sum < 0) curr_sum = 0;
}```
