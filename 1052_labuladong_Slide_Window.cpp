#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int left= 0,right = 0;
        int rleft= 0,rright = 0;
        int res = 0,sum = 0;
        int people = 0;

        while(right < customers.size()){
            // 保证窗口大小为X
            if(right - left + 1 <= X){
                if(grumpy[right] == 1)
                    sum += customers[right];
                right++;
            }
            // 此时窗口大小为X+1
            if(sum > res){
              rleft = left;
              rright = right;
              res = sum;
            }
            printf("left:%d,right:%d,sum:%d\n",left,right,sum);
            if(right - left + 1 > X){
                if(grumpy[left] == 1)
                    sum -= customers[left];
                left++;                
            }
        }
        //printf("left:%d,right:%d\n",rleft,rright);
        for(int i = 0;i<customers.size();i++){
            // 滑动窗口左闭右开
            if(grumpy[i] == 0 || (i >= rleft && i < rright)){
                people += customers[i];
            }
        }
        return people;
    }
};
