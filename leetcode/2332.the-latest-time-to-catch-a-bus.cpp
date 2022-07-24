/*
 * @lc app=leetcode id=2332 lang=cpp
 *
 * [2332] The Latest Time to Catch a Bus
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution {
   public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers,
                              int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size(), m = passengers.size();

        int res = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            int cnt = 0;
            while (j < m && passengers[j] <= buses[i] && cnt < capacity) {
                ++cnt;
                ++j;
            }
            if (i == n - 1) {          // the last bus
                if (cnt < capacity) {  // still have seats
                    int t = buses[i];  // can be as late as the bus arrive time
                    for (int k = j - 1; k >= 0 && passengers[k] == t; --k, --t)
                        ;
                    res = max(res, t);
                } else {  // full of passegers
                    int t =
                        passengers[j - 1] -
                        1;  // should arrive earlier than last passenger aboard
                    for (int k = j - 2; k >= 0 && passengers[k] == t; --k, --t)
                        ;
                    res = max(res, t);
                }
            }
        }

        return res;
    }
};
// @lc code=end
