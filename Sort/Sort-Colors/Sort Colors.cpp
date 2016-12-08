//Source : https://leetcode.com/problems/sort-colors/
//Author : Mao Jiachen
//Date   : 2016/12/06

/****************************************************************************************
 *
 * #1
 * Approach: Counting Sort
 * Algorithm: classic counting sort we need a help vector and a result vector, we need 
 * every number appeared times into the help vector. Then change the help vector, making 
 * the vector as help[i] = help[i] + help[i - 1]. Just like the number is less than someone 
 * into the help vector. Then using the help vector add to result vector. 
 * Finally replace the result vector to nums vector. 
 *
 * #2
 * Approach: Two pointer
 * Algorithm: traverse array only one time. The first pointer is the head one, The last 
 * pointer is the last one. if the number is equal to 0, swap number and first pointer`s
 * number. If the number is equal to 2, swap number and last pointer's number, then make 
 * the i pointer plus one.
 *
 ***************************************************************************************/

 //#1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return;
        vector<int> res(n);
        vector<int> help(3, 0);
        for (auto i : nums)
            help[i]++;
        for (int i = 1; i < 3; i++)
            help[i] += help[i - 1];
        for (int i = 2; i >= 0; i--) {
            for (int j = help[i] - 1; j >= 0; j--) {
                if (help[i] - help[i - 1] > 0) {
                    res[j] = i;
                    help[i]--;
                }
            }
        }
        for (int i = 0; i < n; i++) 
            nums[i] = res[i];
    }
};

 //#2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return;
        int idx0 = 0;
        int idx2 = n - 1;
        int i = 0;
        while (i <= idx2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[idx0]);
                idx0++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[idx2]);
                idx2--;
            }
            else
                i++;
        }
    }
};