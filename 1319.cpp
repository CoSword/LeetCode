#include<iostream>
#include<vector>
using namespace std;

class Solution {
private: 
	vector<vector<int> >& edges;
	verctor<int> used; 
public:
    int makeConnected(int n, vector<vector<int> >& connections) {
		// 连通图最少有n-1条边 
		if(connections.size() < n-1){
			return -1;
		}
		
		int record[n];
		// 定义外层大小 
		edges.resize(n);
	    for (auto& conn: connections) {
	    	// 无向图 
	    	// 相当于邻接表一样的动态结构，减少空间复杂度 
            edges[conn[0]].push_back(conn[1]); 
            edges[conn[1]].push_back([conn[0]);
        }
        
		used.resize(n);
		int ants = 0; 
		for(int i=0;i<n;i++){
			if(used[i]!=1){
				// 从未被访问过节点开始DFS 
				DFS(i);
				// 统计DFS的次数
				// 如果没有孤立点，连通图一次DFS就能访问所有节点，则ants=1无需额外操作
				// 两次DFS 说明图至少有一个孤立点，至少需要一条边 
				ants++; 
			}	
		}
		return ants - 1; 	
		}
		
    }
    //深度优先遍历 
    void DFS(int u) {
    	// visit(v) 
    	used[u] = 1;
		for(int v:edges[u]){
			if(used[v] != 1){
				DFS(v); 
			}
		}
	}
};

