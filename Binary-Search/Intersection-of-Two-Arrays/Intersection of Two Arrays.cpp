//Source : https://leetcode.com/problems/intersection-of-two-arrays/
//Author : Mao Jiachen
//Date   : 2016/06/06

/***********************************************************************************************
 *
 * Approach1: Set
 * Approach2: Two Pointers
 * Approach3: Binary Search
 * Approach4: Set function
 *
 ***********************************************************************************************/

// #1
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end()), res;
        for (auto a : nums2) {
            if (s.count(a) != 0)
                res.insert(a);
        }
        return vector<int>(res.begin(), res.end());
    }
};
// #2
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
            } 
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
        }
        return res;
    }
};
// #3
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums1.begin(), nums1.end());
        for (auto a : nums2) {
            if (binarySearch(nums1, a)) {
                res.insert(a);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
    
    bool binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
// #4
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};