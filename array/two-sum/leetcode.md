# Two Sum (Hash Map / Complement Pattern)

> To solve this problem, we use the **Hash Map Complement Pattern**.
>
> The idea is simple: For every number, check if its complement
> (target - number) already exists.

This is one of the most important and most frequently asked interview
patterns.

---

## 🧠 How to Recognize the Pattern

### 🔎 Signal 1: "Find two numbers"

If the problem says:

- Find two numbers
- Pair with given sum
- Return indices
- Exactly one solution exists

👉 Immediately think: This is a **pair-sum problem**.

---

### 🔎 Signal 2: Target Sum Given

If you see:

target = something

👉 That means: For every number `x`, you should think:

complement = target - x

This is the core insight.

---

### 🔎 Signal 3: Need Better Than O(n²)

Brute force would be:

- Try all pairs → O(n²)

But interview expects:

✔ O(n) time\
✔ Using hashing

That signals **Hash Map usage**.

---

# 🔥 The Core Pattern (Complement Storage Pattern)

Instead of checking future elements, we store what we NEED to find.

For each element:

1.  Check if current number exists in map\
2.  If yes → we found the pair\
3.  If no → store (target - current number) in map

This is called the **Complement First Strategy**.

---

# ✅ Step-by-Step Approach

### Step 1: Create a Hash Map

Store: Key → required complement\
Value → index of element

---

### Step 2: Traverse the Array

For each element:

- If it already exists in map → answer found\
- Otherwise → store its complement

---

### Step 3: Return Indices

Since problem guarantees exactly one solution, we can break once found.

---

# 📌 Why This Works

Instead of searching forward for complement, we prepare in advance what
value we need.

Example:

nums = \[2,7,11,15\]\
target = 9

Iteration:

2 → store (9-2)=7\
7 → 7 exists → pair found

Time Complexity becomes O(n).

---

# ⏱ Complexity

- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

---

# 💻 Solution

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> freq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq.find(nums[i]) != freq.end())
            {
                auto it = freq.find(nums[i]);
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
            else
            {
                freq[target - nums[i]] = i;
            }
        }
        return res;
    }
};
```

---

# 🎯 Interview Takeaway

Whenever you see:

- Two numbers\
- Target sum\
- Return indices

Immediately think:

✔ Hash Map\
✔ Complement = target - current\
✔ Single pass solution

This is a **must-master pattern** for interviews.
