#include<iostream> 
#include<string.h>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) { 
		unordered_map<char,int>need, window;
		// 初始化 
		for(char c:p){
			need[c]++;
		}
		vector<int> result;
		string temp;
		
		int left = 0;
		int right = 0;
		int valid = 0;
		
		while(right < s.size()){
			char c = s[right];
			right++;
			if(need.count(c)){
				window[c]++;
			   //1表示拼接字符个数 
				temp.append(1,c);
				if(window[c] == need[c]){
					valid++;
				}
			}
			
			while(right - left >= p.size()){
				if(valid == p.size()){
					cout<<temp;
					if(!temp.compare(p)){
						result.push_back(left);
					}
					temp = "";
				}
				char d = s[left];
				left++;
				if(need.count(d)){
					if(window[d] == need[d]){
						valid--;
					}
					window[d]--;
				}
			} 
		} 
		return result;
    }
};
