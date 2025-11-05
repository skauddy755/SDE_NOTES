# Prime Numbers


1. Sieve of Eratosthenes to create a boolean array, `sieve` such that, `sieve[i]` is `true` if `i` is prime, and `false` otherwise
2. Sieve of Eratosthenes to create an integer array `sieve` such that, `sieve[i]` stores the lowest prime factor of `i`
3. Using (2) to generate the prime factorization of any number `i` in O(log(N)) time.

> NOTE: Sieve of Eratosthenes is generated in O(N.log(log(N))) time

Refer to [skauddy755/cphb755](https://github.com/skauddy755/cphb755/blob/main/NUMBER_THEORY/numberTheory_1.cpp) for code samples

# Binary Exponentiation

1. Fast calculation of the exponent x raised to y in O(log(y)) time
2. Fast calculation of x raised to y modulo p

Refer to [skauddy755/cphb755](https://github.com/skauddy755/cphb755/blob/main/NUMBER_THEORY/code_snippets.cpp) for code samples

# The world of GCD

## Eucleid's Method of Repeated Division

1. Calculate GCD of two number x and y using Euclidean method of repeated division. Refer [skauddy755/cphb755](https://github.com/skauddy755/cphb755/blob/main/NUMBER_THEORY/numberTheory_3.cpp)
2. Express gcd(x, y) as a linear combination of x and y. You can also express 0 as a linear combination of x and y. Refer [skauddy755/cphb755](https://github.com/skauddy755/cphb755/blob/main/NUMBER_THEORY/gcd_and_linear_combination.cpp)

## Inverse Modulo

### Definition of Inverse Modulo:

`h` is called the inverse modulo of `a` under modulo `p` if the following holds:
```
a.h = 1 (mod p)
```

> NOTE: Inverse modulo of `a` under modulo `p` is possible only if the two are coprime with respect to each other.

### Finding `h` (given `a` and `p`):

```
    gcd(a, h) = Linear_Combination(a, p)
=>  gcd(a, h) = alpha * a + beta * p
=>  1         = alpha * a + beta * p                [since a and b are coprime]
=>  1 % p     = (alpha * a + beta * p) % p          [both sides under modulo p]
=>  1 % p     = (alpha * a) % p + (beta * p) % p    [distributive property]
=>  1 % p     = (alpha * a) % p + 0                 [p divides beta*p]
=>  1 % p     = (alpha * a) % p                     
```

Hence, `alpha` (component of `a` while expressing `gcd(a, p)` as a LC of `a` and `p`) is the required inverse.

### Shortcut to finding inverse modulo using Fermet's Lil Theorem:

```
Fermet's rule states that, for any two numbers a and p the following holds:

    (a^p -  a) is divisible by p
=>  (a.(a^(p-1) - 1)) is divisible by p

Now, we have product of a and (a^(p-1) - 1) being divisible by p
But since, a and p are coprime, so a does not contain any factors of p.
Hence, all the factors must be contributed by (a^(p-1) - 1) alone.
Which means,
    (a^(p-1) - 1) is divisible by p
=>  a^(p-1) - 1 = 0 (mod p)
=>  a^(p-1)     = 1 (mod p)
=> a . a^(p-2)  = 1 (mod p)
```

Hence, `a^(p-2)` is the inverse modulo of `a` with respect to `p`

# Combinatorics

Finding the combination `C(n, r)` for large numbers

### Using Pascal's triangle:

- This method is particularly useful, if you need `C(n, r)` for many values of `n` and `r` and there is no modulo operation associated to it.
- Pascal's Triangle uses the recurence relation: `C(n, r) = C(n-1, r) + C(n-1, r-1)`
- Base cases: `C(1,0) = 0`, `C(1,1) = 1`, `C(n, 0) = 1`

### Using inverse modulo:

- Particularly helpful, if you need to compute the combination only once, and you need to return the result modulo some value (say `1e9 + 7`)

We know that,
```
C(n, r) % p = (factorial(n) / (factorial(n-r) * factorial(r))) % p
            = (factorial(n) * inv_factorial(n-r) * inv_factorial(r)) % p
```

Here, `inv_factorial(x)` is the inverse modulo of `factorial(x)` under p

For populating the `factorial` array, we simply use the recurrence relation:
```
factorial[i] = (i * factorial[i-1]) % p
```
With base case as, `factorial[0] = 1`

For poplulating `inv_factorial` array, we need to be clever:
```
inv_factorial(i) = (1 / factorial(i)) % p
                 = ((i+1) / factorial[i+1]) % p
                 = ((i+1) * inv_factorial[i+1]) % p
```
Base case, (using Fermet's Lil Theorem)
```
inv_factorial[MAX_VALUE] = fastExpo(factorial[MAX_VALUE], p-2)
```

> Solve this [HARD question on Combinatorics](https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/)
> See how they:
> 1. Formulate the problem into easy combinatorics formula
> 2. Use binary expo, and fermet's little theorem.