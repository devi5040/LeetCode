class Solution
{
    struct Node
    {
        int prod;
        int cnt[5];

        Node()
        {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(Node left, Node right)
    {
        Node res;

        // Product of the whole combined segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside the left segment
        for (int r = 0; r < k; r++)
        {
            res.cnt[r] += left.cnt[r];
        }

        // Prefixes that cross from left into right
        for (int r = 0; r < k; r++)
        {
            int newRemainder = (left.prod * r) % k;
            res.cnt[newRemainder] += right.cnt[r];
        }

        return res;
    }

    void build(vector<int> &nums, int node, int l, int r)
    {
        if (l == r)
        {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, int value)
    {
        if (l == r)
        {
            int rem = value % k;

            tree[node] = Node();

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
        {
            update(node * 2, l, mid, index, value);
        }
        else
        {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr)
    {
        // Completely inside query range
        if (ql <= l && r <= qr)
        {
            return tree[node];
        }

        int mid = l + (r - l) / 2;

        // Completely in left
        if (qr <= mid)
        {
            return query(node * 2, l, mid, ql, qr);
        }

        // Completely in right
        if (ql > mid)
        {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        // Query overlaps both sides.
        // IMPORTANT: left must be merged before right.
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(
        vector<int> &nums,
        int k,
        vector<vector<int>> &queries)
    {
        this->n = nums.size();
        this->k = k;

        tree.resize(4 * n);

        // Build segment tree
        build(nums, 1, 0, n - 1);

        vector<int> answer;

        for (auto &q : queries)
        {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists for future queries
            update(1, 0, n - 1, index, value);

            // We only care about nums[start ... n-1]
            Node res = query(
                1,
                0,
                n - 1,
                start,
                n - 1);

            answer.push_back(res.cnt[x]);
        }

        return answer;
    }
};