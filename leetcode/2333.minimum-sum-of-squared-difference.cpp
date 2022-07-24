/*
 * @lc app=leetcode id=2333 lang=cpp
 *
 * [2333] Minimum Sum of Squared Difference
 */

// @lc code=start
#include <bits/stdc++.h>
#define ll long long
class Solution {
   public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        // bucket sort solution
        ll n = nums1.size();
        vector<ll> diff(n, 0);
        for (ll i = 0; i < n; i++) diff[i] = abs(nums1[i] - nums2[i]);

        // creating bucket
        ll m = *max_element(diff.begin() , diff.end());
        vector<ll> bucket(m + 1, 0);
        for (ll i = 0; i < n; i++) bucket[diff[i]]++;

        ll k = k1+k2;

        for(ll i=m; i>0; i--){
            if(bucket[i] > 0 ){
                int minus = min(k , bucket[i]);
                bucket[i] -= minus;
                bucket[i-1] += minus;
                k -= minus;
            }
        }

        ll ans = 0;
        for(ll i=m; i>0; i--){
            ans += i*i*bucket[i];
        }

        return ans;
    }
};
// @lc code=end
