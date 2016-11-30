//Source : https://leetcode.com/problems/find-the-duplicate-number/
//Author : Mao Jiachen
//Data   : 2016/11/30

/**************************************************************************************************
 *
 * #1
 * Approach: Time o(nlogn)
 * Algorithm: Using the Pigeonhole Principle + Binary Search.
 * firstly find the mid of the array, then traversaling the array and counting the
 * numbers whose value less than and equal to mid.If the counter more than mid, it 
 * explain the duplicate value is in [1,mid],else the duplicate value is in [mid+1, n].
 * until low = high, the duplicate value is low.
 *
 * #2
 * Approach: Time o(n)
 * Algorithm: Amazing way! Turn this array to a cycle.
 * Notice: 
 * There are n+1 numbers from 1 to n in an array. We should consider it to a collection.
 * define f(i) = nums[i]. So the duplicate value is expressed i != j, fulfil f(i) = f(j).
 * We should find this pair(i, j).Finally, through f(i) = A[i] finding the duplicate value.
 * How to find the duplicate value? This is a cycle check program! 
 * Given a function define: 
 * x_0    =    k
 * x_1    =    f(x_0)
 * x_2    =    f(f(X_0))
 * ......
 * x_{n+1}= f(x_n) 
 * define f.
 * 1.If this is no deplicate value, the array is infinite.
 * 2.If the array is a closed cycle, means exist i maked x_0 = x_i. The array has cycle in a part
 * 3.If the array like 'p' shape, means the array start a loop from a value(Enterment).
 * 
 * The specification of this approach via. 
 * http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/
 *
 **************************************************************************************************/
 
 //#1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) * 0.5;
            int count = 0;
            for (auto i : nums)
                if (i <= mid)
                    count++;
            if (count <= mid) 
                low = mid + 1;
            else 
                high = mid;
        }
        return low;
    }
};


 //#2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t)
                break;
        }
        return slow;
    }
};
