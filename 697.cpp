// 引入min max函数 
#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 建立数组元素对象替代left,right也行
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // 记录元素频数
        // left:最早出现, right:最晚出现
        unordered_map<int,int>left, right, hashmap;
        // 最大频数
        int maxPin = 0;
        // 连续子数组最短长度
        int minLen = numeric_limits<int>::max();;
        // 获取数组元素频数并记录其最早出现和最晚出现位置
        for(int i=0; i < nums.size(); i++){
            if(hashmap[nums[i]] == 0){
                left[nums[i]] = i;
            }
            hashmap[nums[i]]++;
            right[nums[i]] = i;
            // 记录最大频数
            if(hashmap[nums[i]] > maxPin){
                maxPin = hashmap[nums[i]];
            }
        }

        // 遍历元素字典，
        for(auto& kv:hashmap){
            //printf("number:%d,pin:%d\n",kv.first, kv.second);
            if(kv.second == maxPin){
                minLen = min(minLen, right[kv.first] - left[kv.first] + 1);
            }
        }
        return minLen;
    }
};
