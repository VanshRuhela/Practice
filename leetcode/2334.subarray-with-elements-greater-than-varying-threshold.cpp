/*
 * @lc app=leetcode id=2334 lang=cpp
 *
 * [2334] Subarray With Elements Greater Than Varying Threshold
 */

// @lc code=start

struct DSU {
    int mx;
    vector<int> par, size;

    DSU(int n) {
        mx = 1;
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int j = 1; j <= n; j++) par[j] = j;
    }

    int Leader(int x) {
        if (par[x] == x) return x;
        return (par[x] = Leader(par[x]));
    }

    void merge(int x, int y) {
        x = Leader(x);
        y = Leader(y);

        if (x == y) return;
        if (size[x] > size[y]) swap(x, y);

        size[y] += size[x];
        par[x] = y;

        mx = max(mx, size[y]);
    }
};

class Solution {
   public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<pair<double, int>> vi;
        for (int j = 0; j < n; j++) {
            vi.push_back({nums[j], j + 1});
        }

        sort(vi.begin(), vi.end());

        vector<bool> active(n + 1, false);

        DSU dsu(n);
        int k = 1;
        for (int j = n - 1; j >= 0 && k <= n;) {
            double kTH = (double)threshold / k;

            while (j >= 0 && vi[j].first > kTH) {
                int idx = vi[j].second;
                active[idx] = true;
                if (active[idx - 1]) dsu.merge(idx, idx - 1);
                if (active[idx + 1]) dsu.merge(idx, idx + 1);

                j--;
            }

            if (j < n - 1 && dsu.mx >= k) return k;
            k++;
        }

        return -1;
    }
};
// @lc code=end
