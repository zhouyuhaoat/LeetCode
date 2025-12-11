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
private:
    vector<vector<int>> res;

    long long zigzag_count(vector<int>& nums1, vector<int>& nums2, int e) {
        long long cnt = 0;
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (nums1[i] + nums2[j] > e) {
                j--;
            } else {
                cnt += j + 1; // row by row
                i++;
            }
        }
        return cnt;
    }

    int lower_bound(vector<int>& nums1, vector<int>& nums2, int k) {
        int lo = nums1[0] + nums2[0], hi = nums1.back() + nums2.back() + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (zigzag_count(nums1, nums2, mi) >= k) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }

    void lessThan(vector<int>& nums1, vector<int>& nums2, int& k, int sum) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (nums1[i] + nums2[j] >= sum) {
                j--;
            } else { // less than sum
                for (int col = 0; col <= j && k > 0; col++, k--) {
                    res.emplace_back(vector<int>{nums1[i], nums2[col]});
                }
                i++;
            }
        }
    }

    void equalTo(vector<int>& nums1, vector<int>& nums2, int& k, int sum) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (nums1[i] + nums2[j] > sum) {
                j--;
            } else if (nums1[i] + nums2[j] < sum) {
                i++;
            } else { // equal to sum
                int cnt1 = 0, cnt2 = 0;
                int val1 = nums1[i], val2 = nums2[j];
                while (i < m && nums1[i] == val1) {
                    cnt1++;
                    i++;
                }
                while (j >= 0 && nums2[j] == val2) {
                    cnt2++;
                    j--;
                }
                long long cnt = (long long)cnt1 * cnt2;
                while (cnt-- > 0 && k-- > 0) {
                    res.emplace_back(vector<int>{val1, val2});
                }
            }
        }
    }

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int sum = lower_bound(nums1, nums2, k);
        lessThan(nums1, nums2, k, sum);
        equalTo(nums1, nums2, k, sum);
        return res;
    }
};
// @lc code=end
