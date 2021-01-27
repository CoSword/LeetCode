#include<iostream>
#include<vector>
using namespace std;

class Solution {
private: 
	// 数组表示m叉树 
	vector<int> parent; 
	// 统计连通图数量 
	int ants;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
		int rootX;
		int rootY;
	
		// 连通图最少有n-1条边 
		if(connections.size() < n-1){
			return -1;
		}
		parent.resize(n);
		// 数组初始化 
		for(int i=0; i<n; i++){
			parent[i] = -1;
		}
		
		// 并查集树初始化 
		for (auto& conn: connections) {
			rootX = Find(conn[0]);
			rootY = Find(conn[1]);  
		    // 如果两个顶点的根不相等则合并 
			if(rootX != rootY){
				Union(rootX,rootY);
			}        
		}
		
		for(int i=0; i<n; i++){
			if(parent[i] == -1){ 
				ants++;
			}
		}
		return ants - 1;
    }
	
	int Find(int x){
		int root = x;
		while(parent[root] != -1){
			root = parent[root];
		}
		return root;
	}	
	
	void Union(int rootX, int rootY){
		parent[rootX] = rootY;
	}
  
};
