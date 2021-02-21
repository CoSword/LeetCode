#include<iostream> 
#include<string.h>
#include<vector>
#include<set>

using namespace std;
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
