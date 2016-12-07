//Source : https://leetcode.com/problems/container-with-most-water/
//Author : Mao Jiachen
//Date   : 2016/12/07

/****************************************************************************************
 *
 * Approach: Two Pointer
 * Algorithm: The container with most water is depended on the lowest edge. So define two 
 * pointer from the head and the end. If the height[left] > height[right], set the right 
 * edge as the current edge, and set the right sub one. On the contrary, just like this 
 * contrary situation. 
 * Finally, set the area as the maxArea and return it.
 * 
 ***************************************************************************************/

class Solution {
public:
    int maxArea(vector<int> height) {
        int maxArea = 0, Area = 0;
        int n = height.size();
        if (n == 0)
            return 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (height[left] > height[right]) {
                Area = height[right] * (right - left);
                right--;
            } else {
                Area = height[left] * (right - left);
                left++;
            }
            if (Area > maxArea)
                maxArea = Area;
        }
        return maxArea;
    }
};