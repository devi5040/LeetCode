# Reverse Words in a String (String Manipulation + Reverse Pattern)

> To solve this problem, we use a **3-step reverse pattern**:
>
> 1.  Clean the string (remove extra spaces)
> 2.  Reverse the entire string
> 3.  Reverse each word individually

This is a **classic string manipulation pattern** frequently asked in
interviews.

---

## 🧠 How to Recognize the Pattern

### 🔎 Signal 1: "Reverse Words" (Not Characters)

If the problem says:

- Reverse words
- Reverse order of words
- Words separated by spaces
- Maintain word integrity

👉 Think: We are not reversing characters inside words permanently.\
We are reversing the _order_ of words.

---

### 🔎 Signal 2: Extra Spaces Mentioned

If the problem mentions:

- Leading spaces
- Trailing spaces
- Multiple spaces between words

👉 That means: First clean the string before applying logic.

This is a strong indicator of **string parsing + reconstruction**.

---

### 🔎 Signal 3: In-place or O(1) Extra Space Hint

If constraints push toward optimization, think:

✔ Reverse entire string\
✔ Then reverse individual words

This avoids using stack/vector.

---

# 🔥 The Core Pattern

This problem follows the **Three-Step Reverse Pattern**

---

## ✅ Step 1: Remove Extra Spaces

We: - Skip leading spaces - Skip multiple spaces - Keep only single
space between words

This creates a clean string.

---

## ✅ Step 2: Reverse Entire String

If:

"the sky is blue"

After full reverse:

"eulb si yks eht"

Now words are in correct order but characters inside words are reversed.

---

## ✅ Step 3: Reverse Each Word Individually

Reverse each word again to fix character order.

Final result:

"blue is sky the"

---

# 📌 Why This Pattern Works

If:

Original: A B C\
Full Rev: C B A (characters reversed too)\
Word Rev: C B A (characters fixed)

This trick is powerful in:

- Reverse words
- Sentence manipulation
- In-place string problems
- Space trimming problems

---

# ⏱ Complexity

- Time Complexity: **O(n)**
- Space Complexity: **O(n)** (due to temp string)

---

# 💻 Solution

```cpp
class Solution
{
public:
    string reverseWords(string s)
    {
        // Step 1: Remove extra spaces
        int n = s.size();
        string temp;

        int i = 0;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++; // skip spaces
            if (i >= n)
                break;

            if (!temp.empty())
                temp += ' ';

            int j = i;
            while (j < n && s[j] != ' ')
                j++;

            temp += s.substr(i, j - i);
            i = j;
        }

        // Step 2: Reverse whole string
        reverse(temp.begin(), temp.end());

        // Step 3: Reverse each word
        int start = 0;
        for (int end = 0; end <= temp.size(); end++)
        {
            if (end == temp.size() || temp[end] == ' ')
            {
                reverse(temp.begin() + start, temp.begin() + end);
                start = end + 1;
            }
        }

        return temp;
    }
};
```

---

# 🎯 Interview Takeaway

Whenever you see:

Reverse words in a string

Immediately think:

✔ Clean spaces\
✔ Reverse entire string\
✔ Reverse each word

This is a **standard interview pattern** you should memorize.
