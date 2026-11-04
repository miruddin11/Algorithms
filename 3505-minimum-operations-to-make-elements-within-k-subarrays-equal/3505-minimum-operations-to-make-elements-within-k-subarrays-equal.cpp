class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        if (1LL * x * k > n) return -1;

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        vector<long long> cnt(m + 1), sum(m + 1);

        auto update = [&](int p, int delta, int value) {
            for (; p <= m; p += p & -p) {
                cnt[p] += delta;
                sum[p] += 1LL * delta * value;
            }
        };

        auto query = [&](int p) {
            long long c = 0, s = 0;
            for (; p > 0; p -= p & -p) {
                c += cnt[p];
                s += sum[p];
            }
            return pair<long long, long long>{c, s};
        };

        auto kth = [&](int rank) {
            int p = 0;
            int step = 1;
            while ((step << 1) <= m) step <<= 1;

            for (; step; step >>= 1) {
                int np = p + step;
                if (np <= m && cnt[np] < rank) {
                    rank -= cnt[np];
                    p = np;
                }
            }
            return p + 1;
        };

        vector<long long> ops(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int p = lower_bound(vals.begin(), vals.end(), nums[i])
                    - vals.begin() + 1;
            update(p, 1, nums[i]);
            total += nums[i];

            if (i >= x) {
                int old = lower_bound(vals.begin(), vals.end(), nums[i - x])
                          - vals.begin() + 1;
                update(old, -1, nums[i - x]);
                total -= nums[i - x];
            }

            if (i >= x - 1) {
                int midPos = kth((x + 1) / 2);
                long long mid = vals[midPos - 1];

                auto [lc, ls] = query(midPos);
                long long rc = x - lc;
                long long rs = total - ls;

                ops[i] = mid * lc - ls + rs - mid * rc;
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> pre(n + 1, 0);
        vector<long long> cur(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), INF);

            for (int i = j * x; i <= n; i++) {
                cur[i] = min(cur[i - 1],
                             pre[i - x] + ops[i - 1]);
            }

            swap(pre, cur);
        }

        return pre[n];
    }
};