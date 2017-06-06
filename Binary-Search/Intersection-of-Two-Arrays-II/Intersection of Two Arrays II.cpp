//Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/
//Author : Mao Jiachen
//Date   : 2016/06/06

/***********************************************************************************************
 *
 * Approach1: Hash Table
 * Approach2: Two Pointers
 *
 ***********************************************************************************************/

// #1
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto a : nums1)
            m[a]++;
        for (auto a : nums2) {
            if (m[a]-- > 0)
                res.push_back(a);
        }
        return res;
    }
};
// #2
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } 
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        return res;
    }
};
