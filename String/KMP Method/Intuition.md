This solution solves the **Rotate String** problem in **$O(N)$ time** using the **Knuth-Morris-Pratt (KMP)** pattern searching algorithm.

---

### Core Intuition

If string `s` can be rotated to form `goal`:

1. They **must have the exact same length**.
2. `goal` **must be a substring** of `s + s` (the string doubled).

**Example:**

* `s = "abcde"`, `goal = "cdeab"`
* `s + s = "abcdeabcde"`
* `goal` (`"cdeab"`) is clearly inside `"ab[cdeab]cde"`.

Instead of using a simple `find()` method (which can be $O(N^2)$ in worst cases), this code uses **KMP search** to find `goal` inside `s + s` in guaranteed linear time $O(N)$.

---

### Key Components

#### 1. `rotateString(s, goal)` — The Entry Point

* **Length Check:** If `s.size() != goal.size()`, rotation is impossible $\rightarrow$ returns `false`.
* **String Concatenation:** Creates `doubledString = s + s`.
* **Pattern Matching:** Calls `kmpSearch(doubledString, goal)` to check if `goal` exists inside `doubledString`.

---

#### 2. `computeLPS(pattern)` — Precomputing Longest Prefix Suffix Array

The LPS array allows KMP to avoid unnecessary character re-comparisons when a mismatch occurs.

* **Definition:** `lps[i]` store the length of the longest proper prefix of `pattern[0...i]` that is also a suffix of `pattern[0...i]`.
* **How it works:**
* Uses two pointers: `index` (scanning through `pattern`) and `length` (tracking match length).
* **Match (`pattern[index] == pattern[length]`):** Increment `length` and store it in `lps[index++]`.
* **Mismatch (`length > 0`):** Instead of starting over, fallback to `length = lps[length - 1]`.
* **Mismatch (`length == 0`):** Set `lps[index++] = 0`.



---

#### 3. `kmpSearch(text, pattern)` — Linear Search

Searches for `goal` inside `s + s` using the LPS array.

* Maintains `textIndex` (in `s + s`) and `patternIndex` (in `goal`).
* **Match:** Move both pointers forward (`textIndex++`, `patternIndex++`). If `patternIndex == patternLength`, we found the match and return `true`.
* **Mismatch (`patternIndex > 0`):** Jump `patternIndex` back to `lps[patternIndex - 1]`. This skips redundant comparisons.
* **Mismatch (`patternIndex == 0`):** Simply move to the next character in text (`textIndex++`).

---

### Complexity Analysis

| Metric | Complexity | Explanation |
| --- | --- | --- |
| **Time Complexity** | $O(N)$ | Precomputing LPS takes $O(N)$, KMP search takes $O(N)$ where $N$ is the length of `s`. |
| **Space Complexity** | $O(N)$ | $O(N)$ for the `doubledString` and $O(N)$ for the `lps` array. |
