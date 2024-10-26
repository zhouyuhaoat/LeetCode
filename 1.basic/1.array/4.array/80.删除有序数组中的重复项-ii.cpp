/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 15:42:00
 * 	 modified: 	2024-10-26 15:45:35
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // each value at most k: k = 2
        if (nums.size() <= 2) return nums.size();
        int lo = 2; // write index, also the size or length
        for (int hi = 2; hi < (int)nums.size(); hi++) { // read index for scan
            if (nums[hi] != nums[lo - 2]) { // if not equal, write
                // otherwise, lo - 2 = lo - 1 = hi since sorted
                nums[lo++] = nums[hi];
            }
        }
        return lo;
    }
};
// @lc code=end
