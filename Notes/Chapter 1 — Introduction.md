
## Basics 

```cpp
<bits/stdc++.h>
```
Allows to include the entire standard library.


## Printf & Scanf:

```cpp
scanf("format_string", &var1, &var2, ...);
printf("format_string", var1, var2, ...);
```

Each `%` format corresponds to one variable. You **must use `&`** to pass the address (except for arrays).

| C++ Type       | Format Specifier | Example Use          |     |
| -------------- | ---------------- | -------------------- | --- |
| `int`          | `%d`             | `scanf("%d", &a);`   |     |
| `long`         | `%ld`            | `scanf("%ld", &x);`  |     |
| `long long`    | `%lld`           | `scanf("%lld", &x);` |     |
| `unsigned int` | `%u`             | `scanf("%u", &x);`   |     |
| `float`        | `%f`             | `scanf("%f", &f);`   |     |
| `double`       | `%lf`            | `scanf("%lf", &d);`  |     |
| `long double`  | `%Lf`            | `scanf("%Lf", &d);`  |     |
| `char`         | `%c`             | `scanf("%c", &ch);`  |     |
| `char[]`       | `%s`             | `scanf("%s", str);`  |     |

## Inputs

```cpp
string s;
getline(cin, s)
```
Used to get the whole line


```cpp
while (cin>>x)
{
...
}
```
When the amount of input data is unknown



## Integers


```cpp
	int a = 1234 // 2x10^9
	long long x = 123442312313123123LL // LL is important to avoid errors. 9x10^18
	x = a*a // MISTAKE
	x = (long long)a*a // CORRECT
```


## Mod

`(a+b) mod m = (a mod m + b mod m) mod m`

That means mod can be used during the recursion. **Should do +m if the number was negative**

## Floating numbers

- Can't compare them with `==` due to the rounding errors

**Instead this solution should be used:**

```cpp
if(abs(a-b)<1e-9){
//They are equal
}
```

## Shortening code



| n     | Worst AC Algorithm  |
| ----- | ------------------- |
| <10   | O(n!), O(n^6)       |
| <18   | O(2^n x n^2)        |
| <22   | O(2^n x n)          |
| <26   | O(2^n)              |
| <100  | O(n^4)              |
| <450  | O(n^3)              |
| <1.5K | O(n^2.5)            |
| <2.5K | O(n^2 x logn)       |
| <10K  | O(n^2)              |
| <200K | O(n^1.5)            |
| <4.5M | O(nlogn)            |
| <10M  | O(nloglogn)         |
| <100M | O(1), O(logn), O(n) |
