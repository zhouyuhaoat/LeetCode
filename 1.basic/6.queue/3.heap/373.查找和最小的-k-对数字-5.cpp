/*
 *   author:    zhouyuhao
 *   created:   2025-03-03 09:44:46
 *   modified:  2025-03-03 10:55:03
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
public:
    long long count(vector<int>& nums1, vector<int>& nums2, int e) {
        long long cnt = 0;
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (nums1[i] + nums2[j] <= e) {
                cnt += j + 1;
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }
    int lower_bound(vector<int>& nums1, vector<int>& nums2, int k) {
        int lo = nums1[0] + nums2[0], hi = nums1.back() + nums2.back() + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (count(nums1, nums2, mi) >= k) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
    vector<vector<int>> less_sum(vector<int>& nums1, vector<int>& nums2, int& k, int sum) {
        vector<vector<int>> res;
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (nums1[i] + nums2[j] < sum) {
                for (int kk = 0; kk <= j; kk++, k--) {
                    res.emplace_back(vector<int>{nums1[i], nums2[kk]});
                }
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
    vector<vector<int>> equal_sum(vector<int>& nums1, vector<int>& nums2, int& k, int sum) {
        vector<vector<int>> res;
        int m = nums1.size(), n = nums2.size();
        for (int i = 0, j = n - 1; i < m && k > 0; i++) {
            int ii = i;
            while (i < m - 1 && nums1[i] == nums1[i + 1]) {
                i++;
            }
            while (j >= 0 && nums1[i] + nums2[j] > sum) {
                j--;
            }
            int jj = j;
            while (j > 0 && nums2[j] == nums2[j - 1]) {
                j--;
            }
            if (nums1[i] + nums2[j] != sum) continue;
            int cnt = (long long)(i - ii + 1) * (jj - j + 1);
            for (int kk = 0; kk < cnt && k > 0; kk++, k--) {
                res.emplace_back(vector<int>{nums1[i], nums2[j]});
            }
        }
        return res;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int sum = lower_bound(nums1, nums2, k);
        vector<vector<int>> res = less_sum(nums1, nums2, k, sum);
        vector<vector<int>> equ = equal_sum(nums1, nums2, k, sum);
        res.insert(res.end(), equ.begin(), equ.end());
        return res;
    }
};
// @lc code=end
