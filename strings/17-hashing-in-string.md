# Hashing in Strings (Theory)

### What is String Hashing?

String hashing is a technique to convert a **string into a numeric value (hash)** such that:

* Equal strings → same hash value
* Different strings → (with high probability) different hash values

It is mainly used to **compare substrings efficiently** in problems like pattern matching, duplicate substring search, longest common prefix, etc.

---

### Why do we need Hashing?

* **Naive comparison** of substrings takes `O(n)` time.
* If we want to check equality of substrings multiple times → becomes costly.
* **Hashing allows constant-time substring comparison** after preprocessing.

---

### Types of Hashing in Strings

1. **Polynomial Rolling Hash (Most common)**

   * Each character contributes based on its position using powers of a base `p`.

   * Formula (for string `s[0..n-1]`):

     ```
     hash(s) = (s[0]*p^0 + s[1]*p^1 + ... + s[n-1]*p^(n-1)) mod M
     ```

     where:

     * `p` = a prime base (e.g., 31 for lowercase letters, 53 for mixed case)
     * `M` = a large prime modulus (e.g., 1e9+7, 1e9+9)

   * Example: `"abc"` with `p = 31`, `M = 1e9+7`

     ```
     hash("abc") = ('a'*31^0 + 'b'*31^1 + 'c'*31^2) mod M
     ```

---

2. **Double Hashing**

   * Use **two different (p, M)** pairs to reduce collision probability.
   * Example:

     ```
     hash1(s) = (sum(s[i]*p1^i)) % M1
     hash2(s) = (sum(s[i]*p2^i)) % M2
     ```

3. **Other Hash Functions**

   * Rabin-Karp Hash (variation of rolling hash).
   * Cryptographic hashes (MD5, SHA-1, SHA-256) — not used in competitive programming due to slowness.

---

### Prefix Hashing for Substrings

* Precompute prefix hashes to get **O(1) substring hash queries**.

For string `s`, define:

```
prefix[i] = (s[0]*p^0 + s[1]*p^1 + ... + s[i]*p^i) mod M
```

Then substring `s[l..r]` hash can be computed as:

```
hash(l, r) = (prefix[r] - prefix[l-1]) * p^(-l) mod M
```

(using modular inverse for `p^l`).

---

### Applications of String Hashing

1. **Pattern Matching** → Rabin-Karp algorithm.
2. **Duplicate Substring Detection** (using binary search + hashing).
3. **Longest Common Substring** problems.
4. **Palindrome checking** with forward & backward hashes.
5. **Fast string comparison** in suffix arrays and suffix automata.

---

### Pros and Cons

**Pros:**

* Fast substring comparison (`O(1)` after preprocessing).
* Useful in competitive programming.

**Cons:**

* Collisions (two different strings having the same hash).
* Requires careful choice of base `p` and modulus `M`.