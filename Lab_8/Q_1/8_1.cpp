#include <bits/stdc++.h> 
using namespace std; 

class DSU { 
	int* parent; 
	int* rank; 

public: 
	DSU(int n){ 
		parent = new int[n]; 
		rank = new int[n]; 

		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 

	int find(int i) { 
		if (parent[i] == -1) return i; 
		return parent[i] = find(parent[i]); 
	} 

	void UnionByRank(int x, int y) { 
		int p1 = find(x); 
		int p2 = find(y); 

		if (p1 != p2) { 
			if (rank[p1] < rank[p2]) { 
				parent[p1] = p2; 
			} 
			else if (rank[p1] > rank[p2]) { 
				parent[p2] = p1; 
			} 
			else { 
				parent[p2] = p1; 
				rank[p1] += 1; 
			} 
		} 
	} 
}; 

class Graph{ 
	vector<vector<int>> Edges; 
	int V; 

public: 
	Graph(int V){ 
        this->V = V; 
    } 

	static bool compare(const std::vector<int>& a, const std::vector<int>& b) {
 		return a[0] > b[0];
	}

	void addEdge(int x, int y, int w){ 
		Edges.push_back({ w, x, y }); 
	} 

	void MST(){ 
		sort(Edges.begin(), Edges.end(), compare); 

		DSU s(V); 
		int minPath = 0; 

		cout << "The maximum spanning tree is :\n";

		for (auto edge : Edges) { 
			int n1 = edge[1]; 
			int n2 = edge[2]; 
			int w = edge[0]; 

			if (s.find(n1) != s.find(n2)) { 
                s.UnionByRank(n1, n2); 
                minPath += w; 
                cout <<"Edge " << n1 << " -- " << n2 << " having weight " << w << "\n"; 
            }  
		}
		cout << "Maximum Cost Spanning Tree: " << minPath; 
	} 
}; 

int main() { 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, e;
    cin >> n >> e;

	Graph g(n); 
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >>a >> b >> c;
        g.addEdge(a, b, c);
    } 

	g.MST(); 
}
