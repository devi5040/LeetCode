# Longest Substring Without Repeating Characters (Sliding Window Pattern)

> To solve this problem, we use the **Sliding Window Technique**.
>
> The idea is to maintain a window of characters that **contains no duplicates** and expand or shrink the window as needed.

This is one of the **most important sliding window problems** and appears frequently in coding interviews.

---

# 🧠 How to Recognize the Pattern

## 🔎 Signal 1: "Substring"

If the problem says:

- substring
- contiguous characters
- longest substring

👉 Immediately think:

**Sliding Window**

Because substring problems usually involve **continuous segments** of the string.

---

## 🔎 Signal 2: "Without Repeating Characters"

This means we must maintain a **window with unique characters only**.

Whenever a duplicate appears:

👉 We must **shrink the window**.

---

## 🔎 Signal 3: Longest / Maximum Length

If the problem asks for:

- longest substring
- maximum length
- largest window

👉 That strongly suggests **two pointers / sliding window**.

---

# 🔥 Core Pattern (Sliding Window)

Sliding window works using two pointers:

```
left → start of window
right → end of window
```

We expand the window using `right` pointer and shrink it using `left` pointer when constraints break.

---

# Approach 1 — Brute Sliding Window (Vector)

This solution maintains a **vector as a window** and removes elements until the duplicate disappears.

### Steps

1. Maintain a container storing current substring characters.
2. For each new character:
3. Check if it already exists in the container.
4. If yes:
   - Remove characters from the front until duplicate disappears.
5. Insert new character.
6. Update max length.

---

# Approach 2 — Optimal Sliding Window (Hash Set)

Instead of searching in vector, we use a **Hash Set** for O(1) lookup.

### Steps

1. Maintain two pointers:

```
left → start of window
right → end of window
```

2. Use a **set to track characters in current window**.
3. Expand window by moving `right`.
4. If duplicate appears:
   - Remove characters from left until duplicate disappears.
5. Update maximum window size.

---

# Example

Input:

```
s = "abcabcbb"
```

steps:

```
Window: "a" length = 1
Window: "ab" length = 2
Window: "abc" length = 3
Duplicate 'a' → move left
Window becomes "bca"

Final answer = 3
```

---

# ⏱ Complexity

### Approach 1 (Vector + find)

Time Complexity:
O(n²)

Because `find()` takes O(n).

Space Complexity:
O(n)

---

### Approach 2 (Sliding Window + Hash Set)

Time Complexity:
O(n)

Each character is inserted and removed at most once.

Space Complexity:
O(min(n, charset))

---

# 💻 Solution 1 (Vector Window)

```cpp
class Solution {
public:
   int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0, length = 0;
        vector<char> st;

        for (char ch : s)
        {
            auto it = find(st.begin(), st.end(), ch);
            while (it != st.end())
            {
                st.erase(st.begin());
                length--;
                it = find(st.begin(), st.end(), ch);
            }
            st.push_back(ch);
            length++;
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};
```

# 💻 Solution 2 (Optimal Sliding Window)

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, left = 0;
        unordered_set<char> st;

        for(int right = 0; right < s.size(); right++){
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
```

🎯 Interview Takeaway

Whenever you see:

Longest substring

Unique characters

No repetition

Immediately think:

✔ Sliding Window
✔ Two pointers (left, right)
✔ Hash set to track characters
