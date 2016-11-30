//Source : https://leetcode.com/problems/move-zeroes/
//Author : Mao Jiachen
//Data   : 2016/11/30

/***************************************************************************
 *
 * #1
 * Approach :Space Sub-Optimal
 * We must notice two requirements of the question.
 * 1.Move all the 0`s to the end of array.
 * 2.All the non-zero elements must retain their original order.
 * 
 * #2
 * Approach :
 *
 *
 *
 *
 *
 *
 *
 *
 ***************************************************************************/
 
 
 
 //#1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        //Count the zeroes
        int numZeroes = 0;
        for (int i = 0; i < n; i++) 
            numZeroes += (nums[i] == 0);
        
        //make all the non-zero elements retain their original order
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (nums[i] != 0)
                ans.push_back(nums[i]);
        
        //move all zeroes to the end
        while (numZeroes--)
            ans.push_back(0);
        
        //combine the result
        for (int i = 0; i < n; i++)
            nums[i] = ans[i];
    }
};


 //#2
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
 
 
 //#3 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                swap(nums[i], nums[j++]);
        }
    }
};
