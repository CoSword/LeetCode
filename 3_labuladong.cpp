#include<iostream> 
#include<string.h>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	unordered_map<char,int> window;
		int left = 0;
		int right = 0;
		int max = 0;
		int temp = 0;
		
		while(right < s.size()){
			char c = s[right];
            right++;
			window[c]++;
			// 为什么if不行 
			while(window[c] > 1){
                char d = s[left];
                left++;
                window[d]--;
			}
			// 计算当前子串长度 
            temp = right - left;
            if(temp > max){
                max = temp;
            }
		}
        return max;
    }
};
