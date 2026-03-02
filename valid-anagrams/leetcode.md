# Valid Anagram (Frequency Counting Pattern)

> To solve this problem, we use the **Character Frequency Counting
> Pattern**.
>
> The idea is simple: If two strings are anagrams, they must have
> identical character frequencies.

This is a very common and fundamental string pattern in coding
interviews.

---

## 🧠 How to Recognize the Pattern

### 🔎 Signal 1: Word "Anagram"

Whenever you see:

- Anagram
- Rearranging characters
- Permutation of string
- Same characters different order

👉 Immediately think: This is a **frequency comparison problem**.

---

### 🔎 Signal 2: Only Lowercase Letters

If the problem states:

- Only lowercase English letters

👉 That means: We can use a fixed array of size 26 instead of a hash
map.

This gives O(1) space complexity.

---

### 🔎 Signal 3: Need Efficient Solution

Brute force method:

- Sort both strings → O(n log n)

Optimized method:

✔ Count frequencies → O(n)

Interview usually expects the optimized one.

---

# 🔥 The Core Pattern (Frequency Difference Technique)

Instead of:

- Counting both strings separately and comparing

We do something smarter:

1.  Increment count for characters in first string
2.  Decrement count for characters in second string
3.  If all values are zero → valid anagram

This reduces passes and improves clarity.

---

# ✅ Step-by-Step Approach

### Step 1: Length Check

If lengths differ → cannot be anagram.

---

### Step 2: Create Frequency Array

Size = 26 (for lowercase letters).

---

### Step 3: Single Loop Update

For each index:

- Increase count for s\[i\]
- Decrease count for t\[i\]

---

### Step 4: Verify All Zero

If any frequency is not zero → not an anagram.

---

# 📌 Why This Works

If two strings are anagrams:

Total increment and decrement operations cancel out.

Example:

s = "anagram"\
t = "nagaram"

After processing:

All frequencies become zero.

---

# ⏱ Complexity

- Time Complexity: **O(n)**
- Space Complexity: **O(1)** (since 26 is constant)

---

# 💻 Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);

        if(s.size()!=t.size())
            return false;
        for(int i=0; i<s.size();i++)
        {
           freq[s[i]-'a']++;
           freq[t[i]-'a']--;
        }
       for (int count : freq) {
            if (count != 0)
                return false;
        }

        return true;
    }
};
```

---

# 🎯 Interview Takeaway

Whenever you see:

- Anagram
- Permutation check
- Same characters

Immediately think:

✔ Frequency array (size 26)\
✔ Increment + Decrement trick\
✔ Check all zeros

This is a **core string pattern** every candidate must master.
