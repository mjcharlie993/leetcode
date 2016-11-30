//Source : https://leetcode.com/problems/move-zeroes/
//Author : Mao Jiachen
//Data   : 2016/11/30

/*****************************************************************************************
 *
 * #1
 * Approach :Space Sub-Optimal
 * We must notice two requirements of the question.
 * 1.Move all the 0`s to the end of array.
 * 2.All the non-zero elements must retain their original order.
 * 
 * #2
 * Approach :Space Optimal, Operation Sub-Optimal
 * This approach works the same way as above, first fulfills one requirement
 * and then another. The catch? It does it in a clever way. The above program
 * can also be stated in alternate way, "Bring all the non 0 elements to the 
 * front of array keeping their relative other same".
 * This is a 2 pointer approach. The fast pointer which is denoted by variable 
 * "cur" does the job of processing new elements. If the newly found element 
 * is not a 0, we record it just after the last found non-0 element. The position 
 * of last found non-0 element is denoted by the slow pointer 
 * "lastNonZeroFoundAt + 1"`th index. This overwrite will not result in any loss of
 * data because we already processed what was there(if it were non-0, it already
 * is now written at it`s corresponding index, or if it were 0 it will be handled 
 * later in time).
 * After the "cur" index reaches the end of array, we now know that all the non-0 
 * elements have been moved to beginning of array in their  original order. Now
 * comes the time to fulfill other requirement, "Move all 0`s to the end". We now
 * simply need to fill all the indexes after the "lastNonZeroFoundAt" index with 0.
 *
 * #3
 * Approach :Optimal
 * The total number of operations of the previous approach is sub-optimal. For example,
 * the array which has all (except last) leading zeroes:[0,0,0,...,0,1]. How many write
 * operations to the array? For the previous approach, it writes 0`s n-1 times, which
 * is not necessary. We could have instead written just once. How? .....
 * By only fixing the non-0 element.
 * The optimal approach is again a subtle extension of above solution. A simple realization
 * is if the current element is non-0, its` correct position can at best be it`s current
 * position or a position earlier. If it's the latter one, the current position will be 
 * eventually occupied by a non-0, or a 0, which lies at a index greater than 'cur' index.
 * We fill the current position by 0 right away, so that unlike the previous solution,
 * we don`t need to come back here in next iteration.
 * the code will maintain the following invariant:
 * 1. All elements before the slow pointer are non-zeroes.
 * 2. All elements between the current and slow pointer are zeroes.
 * Therefore, when we encounter a non-zero element, we need to swap elements pointered
 * by current and slow pointer, then advance both pointers. If it`s zero element, we 
 * just advance current pointer.
 *
 *****************************************************************************************/
 
 
 
 //#1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        // Count the zeroes
        int numZeroes = 0;
        for (int i = 0; i < n; i++) 
            numZeroes += (nums[i] == 0);
        
        // Make all the non-zero elements retain their original order
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (nums[i] != 0)
                ans.push_back(nums[i]);
        
        // Move all zeroes to the end
        while (numZeroes--)
            ans.push_back(0);
        
        // Combine the result
        for (int i = 0; i < n; i++)
            nums[i] = ans[i];
    }
};


 //#2
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int lastNonZeroFoundAt = 0;
         // If the current element is not 0, then we need to
         // append it just in front of last non 0 element we found.
         for (int i = 0; i < nums.size(); i++) 
             if (nums[i] != 0)
                 nums[lastNonZeroFoundAt++] = nums[i];
         
         // After we have finished processing new element,
         // all the non-zero elements are already at beginning of array.
         // We just need to fill remaining array with 0`s.
         for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
             nums[i] = 0;
    }
};


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
