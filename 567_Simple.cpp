#include<iostream> 
#include<string.h>
#include<vector>
using namespace std;
 
void printVector(vector<int>& list){
 	for(int i = 0;i < list.size();i++) {
 		cout<<list[i]<<"-";
 	}
 	cout<<"\n";
 }
/*
滑动窗口法 
给定两个字符串s1和s2，写一个函数来判断 s2 是否包含 s1?的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。
示例 1：

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	// 若s1长度大于s2长度，s2必不存在s1的排列 
        if(s1.size() > s2.size()) return false; 
        
         // 匹配采用的滑动窗口大小为模式串s1大小
		int windowSize = s1.size();
        
        //固定窗口 
        vector<int> hashmap1(26,0);
        //动态窗口 
        vector<int> hashmap2(26,0);
		
		// 默认小写字母的 
		// 创建窗口字典{'a':1,b:'1'....} 
		for(int i = 0; i < windowSize;i++){
			hashmap1[s1[i] - 'a']++;
			hashmap2[s2[i] - 'a']++;
		} 
		
		// 每一轮滑动窗口查询，若窗口字典分布一致，则命中 
		for(int i = windowSize; i < s2.size(); i++){
			if(hashmap1 == hashmap2) return true;
			
			// 窗口向右滑动一格 
			hashmap2[s2[i - windowSize] - 'a']--;
			hashmap2[s2[i] - 'a']++; 
		}
		// 走到最右还有一次未比较 
		return hashmap1 == hashmap2;  
    }
};

