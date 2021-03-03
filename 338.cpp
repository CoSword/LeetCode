#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i = 0; i <= num; i++){
            res[i] =  __builtin_popcount(i);
        }
        return res;
    }
};
