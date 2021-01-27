#include<iostream>
#include<vector>
using namespace std;

class Solution {
private: 
	vector<vector<int> >& edges;
	verctor<int> used; 
public:
    int makeConnected(int n, vector<vector<int> >& connections) {
		// ��ͨͼ������n-1���� 
		if(connections.size() < n-1){
			return -1;
		}
		
		int record[n];
		// ��������С 
		edges.resize(n);
	    for (auto& conn: connections) {
	    	// ����ͼ 
	    	// �൱���ڽӱ�һ���Ķ�̬�ṹ�����ٿռ临�Ӷ� 
            edges[conn[0]].push_back(conn[1]); 
            edges[conn[1]].push_back([conn[0]);
        }
        
		used.resize(n);
		int ants = 0; 
		for(int i=0;i<n;i++){
			if(used[i]!=1){
				// ��δ�����ʹ��ڵ㿪ʼDFS 
				DFS(i);
				// ͳ��DFS�Ĵ���
				// ���û�й����㣬��ͨͼһ��DFS���ܷ������нڵ㣬��ants=1����������
				// ����DFS ˵��ͼ������һ�������㣬������Ҫһ���� 
				ants++; 
			}	
		}
		return ants - 1; 	
		}
		
    }
    //������ȱ��� 
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

