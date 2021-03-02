#include<vector>
#include<iostream>
using namespace std;
/*
304. 二维区域和检索 - 矩阵不可变
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。
来源：力扣（LeetCode）
*/
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() <= 0)return;
        int row = matrix.size();
        int col = matrix[0].size();
        sum = vector<vector<int>>(row,vector<int>(col+1,0));

        // 计算每一行的前缀和
        for(int i=0; i < row; i++){
            for(int j=0; j < col; j++){
               sum[i][j+1] = sum[i][j] + matrix[i][j];      
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        // 求子矩阵每一行的和
        for(int i = row1; i <= row2; i++){
            res = res + sum[i][col2+1] - sum[i][col1];
        }
        return res;
    }
};
