# Generate the README.md file content for the "Group Anagrams" problem

content = """

# Group Anagrams (Hash Map + Sorting Key Pattern)

> To solve this problem, we use a **Hash Map with Sorted String Key Pattern**.
>
> The idea is simple:
> If two strings are anagrams, their **sorted form will be identical**.

This is a classic hashing + string manipulation problem frequently asked in coding interviews.

---

## 🧠 How to Recognize the Pattern

### 🔎 Signal 1: The word "Anagram"

If the problem mentions:

- Anagram
- Rearranging characters
- Same characters different order
- Group words with similar characters

👉 Immediately think:

**Characters are the same, only order changes.**

This means we need a **canonical representation** of the string.

---

### 🔎 Signal 2: Grouping Required

If the problem says:

- Group strings
- Cluster similar words
- Return list of lists

👉 That strongly suggests using a **Hash Map**.

We map a **key → list of strings**.

---

### 🔎 Signal 3: Order Doesn't Matter

Because anagrams share the same characters, if we **sort the characters**, all anagrams become identical.

Example:

eat → aet  
tea → aet  
ate → aet

All map to the same key.

---

# 🔥 The Core Pattern (Sorted Key Hashing)

The trick:

1. Convert each word to a sorted version.
2. Use the sorted string as the key in a hash map.
3. Store the original word in the map.

This groups all anagrams together automatically.

---

# ✅ Step-by-Step Approach

### Step 1: Create a Hash Map

Key → sorted string  
Value → list of anagram words

Example:

```
"aet" → ["eat", "tea", "ate"]
```

---

---

### Step 2: Traverse the Input Array

For each word:

1. Copy the word to a temporary string.
2. Sort the temporary string.
3. Use it as the key in the hash map.
4. Insert the original word into that key's vector.

---

### Step 3: Build Result

After filling the map, extract all vectors from the map and push them into the result array.

---

# 📌 Why This Works

All anagrams share identical sorted representations.

Example:

Input:

```
["eat","tea","tan","ate","nat","bat"]
```

Sorted Keys:

```
aet → ["eat","tea","ate"]
ant → ["tan","nat"]
abt → ["bat"]
```

---

# ⏱ Complexity

Sorting each string costs:

- **O(k log k)** where k = length of string

For n strings:

- **Time Complexity: O(n \* k log k)**
- **Space Complexity: O(n \* k)**

---

# 💻 Solution

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> vec_freq;
        string temp;

        for(string str: strs){
           temp = str;
           sort(temp.begin(), temp.end());

           auto it = vec_freq.find(temp);
           if(it != vec_freq.end())
                it->second.push_back(str);
           else
                vec_freq[temp].push_back(str);
        }

        for(auto &p : vec_freq)
            res.push_back(p.second);

        return res;
    }
};
```

🎯 Interview Takeaway

Whenever you see:

Group anagrams

Same characters different order

Cluster strings

Immediately think:

✔ Sort each word
✔ Use sorted word as hash key
✔ Store original strings in hashmap

This is a very important hashing pattern in string problems.
