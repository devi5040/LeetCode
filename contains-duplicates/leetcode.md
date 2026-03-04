# Contains Duplicate (Hash Set Pattern)

> To solve this problem, we use the **Hash Set Lookup Pattern**.
>
> The idea is simple:
> If we ever see an element that we have already seen before, a duplicate exists.

This is a fundamental hashing pattern asked very frequently in interviews.

---

## 🧠 How to Recognize the Pattern

### 🔎 Signal 1: "Contains Duplicate"

If the problem says:

- Contains duplicate
- Return true if any value appears at least twice
- Check repeated elements

👉 Immediately think:  
This is a **duplicate detection problem**.

---

### 🔎 Signal 2: No Order Requirement

The problem does NOT ask:

- Return indices
- Maintain order
- Count frequency

It only asks whether a duplicate exists.

👉 That means:  
We only need fast lookup, not counting.

---

### 🔎 Signal 3: Better Than O(n²)

Brute force approach:

- Compare every pair → O(n²)

Optimized approach:

✔ Use Hash Set → O(n)

This strongly signals hashing.

---

# 🔥 The Core Pattern (Seen Before Pattern)

We maintain a set of elements we have already seen.

For each number:

1. Check if it exists in the set
2. If yes → duplicate found
3. If no → insert into set

This is called the **Seen-Before Detection Pattern**.

---

# ✅ Step-by-Step Approach

### Step 1: Create an Empty Hash Set

This will store numbers we've seen so far.

---

### Step 2: Traverse the Array

For each number:

- If it exists in set → return true
- Otherwise → insert it

---

### Step 3: If Loop Ends

If no duplicate found → return false.

---

# 📌 Why This Works

Hash set operations:

- Insert → O(1) average
- Find → O(1) average

So overall complexity becomes O(n).

Example:

nums = [1,2,3,1]

Iteration:

1 → insert  
2 → insert  
3 → insert  
1 → already exists → duplicate found

---

# ⏱ Complexity

- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

---

# 💻 Solution

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> freq;
        for(int num:nums){
            if(freq.find(num)!=freq.end())
                return true;
            freq.insert(num);
        }
        return false;
    }
};
```

### 🎯 Interview Takeaway

- Whenever you see:
  - Duplicate detection
  - Repeated elements
  - Boolean result
- Immediately think:
  ✔ Hash Set
  ✔ Seen-before check
  ✔ Single pass
- This is a core hashing pattern you must master.
