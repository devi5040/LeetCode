
class Solution {
    const long long MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;     // Sum of distinct counts
        long long sqSum = 0;   // Sum of squared distinct counts
        long long lazy = 0;    // Pending increment
    };

    vector<Node> tree;
    int n;

    // Add 1 to every value in this segment
    void apply(int node, int l, int r) {
        long long len = r - l + 1;

        tree[node].sqSum =
            (tree[node].sqSum + 2 * tree[node].sum + len) % MOD;

        tree[node].sum = (tree[node].sum + len) % MOD;
        tree[node].lazy++;
    }

    // Pass pending updates to children
    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        long long times = tree[node].lazy;

        // Apply an increment 'times' to each child.
        applyMany(node * 2, l, mid, times);
        applyMany(node * 2 + 1, mid + 1, r, times);

        tree[node].lazy = 0;
    }

    void applyMany(int node, int l, int r, long long x) {
        long long len = r - l + 1;

        tree[node].sqSum =
            (tree[node].sqSum + 2 * x % MOD * tree[node].sum
             % MOD + x * x % MOD * len) % MOD;

        tree[node].sum = (tree[node].sum + x * len) % MOD;
        tree[node].lazy = (tree[node].lazy + x) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            applyMany(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        if (ql <= mid)
            update(node * 2, l, mid, ql, qr);

        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sqSum =
            (tree[node * 2].sqSum + tree[node * 2 + 1].sqSum) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n + 5);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            // Increase distinct counts for these starting indices
            update(1, 0, n - 1, prev + 1, i);

            // Add squares for all subarrays ending at i
            ans = (ans + tree[1].sqSum) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};
