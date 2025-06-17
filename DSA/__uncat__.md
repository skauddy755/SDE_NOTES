
## Number Theory

By Heart the following topics:
1. Prime Factorization using sieve
2. Find GCD(a, b)
3. Express GCD(a, b) as a linear combination of a and b
4. Calculate Inverse Modulo using:
	- Linear Combination of GCD(a, p): `alpha * a + beta * p = 1 (mod p)` => `alpha * a = 1 (mod p)` => `alpha` is the inverse of a under modulo p
	- Fermet's Little theorem: `a^p - a is div by p` Now if (a, p) coprime, then => `a^(p-2)` is the inverse of a under modulo p
5. Calculate combination (n, r) using:
	- Pascal Triangle: C(n, r) = C(n-1, r) + C(n-1, r-1)
	- Using `n! / ((n-r)! * r!)` and hence uses inverse modulo

Solve this HARD question on Combinatorics: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/?envType=daily-question&envId=2025-06-17 (1) See how they formulate the problem into easy combinatorics formula (2) Uses binary expo, and fermet's little theorem.
## Strings

Why can't [[https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2025-06-08]] be solved using Digit DP

Also see HARD version:
https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/?envType=daily-question&envId=2025-06-09
Much like trie

https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/?envType=daily-question&envId=2025-06-11
- Range query (including rearranging of equation)
- Plus sliding window in a very complicated way

