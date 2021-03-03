#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i = 0; i <= num; i++){
            // i&1保留奇数末位的1
            // i为奇数时，二进制的1个数为前一个数1的数目+1;
			// i为偶数时，二进制的1个数与i/2相同           
            res[i] =  res[i>>1] + (i & 1);
        }
        return res;
    }
};
