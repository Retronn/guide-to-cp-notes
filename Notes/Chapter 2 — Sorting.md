

## Greedy Algorithms

- **Greedy** = making the best local choice to try achieving global optimum.
- Often appears with **sorting + iteration** ([[Movie Festival.cpp]]`, `[[Tasks and Deadlines.cpp]]).
- **Fails when**:
  - Future choices depend on earlier ones.
  - Constraints involve splitting, exact grouping, or complex dependencies.
- **Common patterns**:
  - Sort by `.second` (e.g. end time)
  - Use two pointers
  - Combine with `multiset` for allocation

---

## When Not to Use Greedy

- Local optimum ≠ global optimum.
- Examples:
  - [[Array Division.cpp]]: greedy fails due to segment dependency
  - Prefix sum problems → need hashing or dynamic programming

---

## C++ Containers & Memory

- **Stack**: small, fast memory (used for arrays, function calls)
- **Heap**: dynamic memory (used for vectors, sets)
- Prefer `vector<int>` over raw arrays.

---

## Sets, Multisets & Ordered Sets

- `set` – sorted, unique values, O(log n)
- `multiset` – sorted, allows duplicates
- `unordered_set` – fast but unsorted (O(1) avg)
- **Trick**: `ms.erase(ms.find(x))` removes one instance

### Ordered Set (PBDS)

```cpp
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
```

- `find_by_order(k)` → k-th smallest
- `order_of_key(x)` → # of elements < x

Used in: [[Josephus Problem II.cpp]], [[Nested Ranges Count.cpp]], [[Subarray Sums II.cpp]]

---

## Iterators

- `++it`, `--it`, `*it` → value, `prev(it)`, `next(it)`
- `lower_bound(x)` → first element ≥ x
- `upper_bound(x)` → first element > x


---

## Maps

- `map<K,V>` → O(log n), sorted keys
- `unordered_map<K,V>` → O(1) avg, unsorted
- Prefix sums: `map[prefix - k]` for fast subarray lookups

---

## Prefix Sums + Hashing

```cpp
prefix_counts[0] = 1;
for (i = 0; i < n; ++i) {
    prefix_sum += nums[i];
    ans += prefix_counts[prefix_sum - k];
    prefix_counts[prefix_sum]++;
}
```

Used in: [[Subarray Sums II.cpp]], [[Subarray Divisibility.cpp]]

---

## Binary Search on Answer

- Used to find max/min feasible value
- Pattern:

```cpp
while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) hi = mid - 1;
    else lo = mid + 1;
}
```

Used in: [[Factory Machines.cpp]], [[Array Division.cpp]], [[Maximum Subarray Sum II.cpp]]

---

## Permutations & Index Mapping

- Sorting while tracking original positions:

```cpp
positions[arr[i]] = i;
```

Used in: [[Collecting Numbers.cpp]], [[Playlist.cpp]], [[Nested Ranges Check.cpp]]

---

## Useful Algorithms

### [[Kadane’s Algorithm]]

```cpp
sum = 0; maxsum = LLONG_MIN;
for (x : array) {
    sum += x;
    maxsum = max(maxsum, sum);
    if (sum < 0) sum = 0;
}
```


## Sliding Window + HashMap

Used in:
- [[Distinct Values Subarrays.cpp]]
- [[Playlist.cpp]], [[Apartments.cpp]]

**Pattern**:

```cpp
while (condition not met)
    move left pointer
update hash map
```

---

## Median Minimization

- Minimize `|x_i - m|` by choosing **median**
- Used in: [[Stick Lengths.cpp]]

---

## Long Longs

- `LLONG_MIN`, `LLONG_MAX` from `<climits>`
- Never mix `int` + `long long` in arithmetic

---

## Faster I/O

```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```


