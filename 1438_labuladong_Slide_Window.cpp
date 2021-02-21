#include<iostream> 
#include<string.h>
#include<vector>
#include<set>
using namespace std;

/**
 * 给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。
 如果不存在满足条件的子数组，则返回 0 。
 示例 1：
 
 输入：nums = [8,2,4,7], limit = 4
 输出：2 
 解释：所有子数组如下：
 [8] 最大绝对差 |8-8| = 0 <= 4.
 [8,2] 最大绝对差 |8-2| = 6 > 4. 
 [8,2,4] 最大绝对差 |8-2| = 6 > 4.
 [8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
 [2] 最大绝对差 |2-2| = 0 <= 4.
 [2,4] 最大绝对差 |2-4| = 2 <= 4.
 [2,4,7] 最大绝对差 |2-7| = 5 > 4.
 [4] 最大绝对差 |4-4| = 0 <= 4.
 [4,7] 最大绝对差 |4-7| = 3 <= 4.
 [7] 最大绝对差 |7-7| = 0 <= 4. 
 因此，满足题意的最长子数组的长度为 2 。
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
 **/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       // 可重复元素的有序集合,模拟滑动窗口
       multiset<int> set;
       int left =0 ,right=0;
       int res = 0;

       // labuladong模板
       while(right < nums.size()){
           // 移入窗口的元素
           set.insert(nums[right]);
           // 右移窗口
           right++;
           // 窗口数据无需更新
           // 当窗口中最大与最小元素差大于limit时，左移窗口
           // *是因为成员函数返回的是指针，要取值 
           while(*set.rbegin() - *set.begin() > limit){
               // nums[left]是将移出窗口的元素
               set.erase(set.find(nums[left]));
               // 左移窗口
               left++;
           }
           // 比较窗口大小
           res = max(res,right - left);
       }
       return res;
    }
};
