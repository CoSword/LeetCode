#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
using namespace std;

void printHashMap(unordered_map<char,int>& target){
	 cout << "Map:{" ;
	//遍历输出+迭代器的使用
    auto iter = target.begin();//auto自动识别为迭代器类型unordered_map<int,string>::iterator
    while (iter!= target.end())
    {  
        cout << iter->first << ":" << iter->second<<",";  
        ++iter;  
    }
    cout<<"}\n";
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 定义字典 need:固定窗口 window：动态窗口 
		unordered_map<char,int> need,window;
		
		for(char c:s1){
			need[c] ++;
		}
		
		int left = 0; 
		int right = 0;
		int valid = 0;
		
		while(right < s2.size()){
			// c是移入窗口的字符 
			char c = s2[right];
			// 右移窗口
			right++;
			// 如果固定窗口有该字符，窗口数据更新
			if(need.count(c)){
				/*
				方括号访问键对应的值 map[key]。
				注意的是，如果该 key 不存在，C++ 会自动创建这个 key，并把 map[key] 赋值为 0。
				*/
				window[c]++;
				// 比较动态窗口与固定窗口该字符c频率是否一致 need:{a:2}, window{a:1} 
				if(window[c] == need[c]){
					// 频率一致则valid++ 
					valid++;
				}
			}
			 // printf("window: [%d, %d)\n", left, right);
			// 判断左侧窗口是否收缩
			while(right - left >= s1.size()){
				// 收缩时判断 动态窗口频率一致的字符个数是否与固定窗口字符个数相等 
				if(valid == need.size()){
					return true;
				}
				char d = s2[left];
				left++; 
				 // 窗口数据更新
	 			if(need.count(d)){
	 				if(window[d] == need[d]){
	 					valid--;
	 				}
	 				window[d]--;
	 			}
			} 
		}
        return false;
    }
};

string stringToString(string input) {
    //assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        
        bool ret = Solution().checkInclusion("ab", "eidboaoo");

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
