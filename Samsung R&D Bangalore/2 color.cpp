#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

class Graph{
public:
	int V;
	Node **head;

	Graph(int n){
		V = n;
		head = new Node*[n + 1];
		for (int i = 0; i <= n; i++)	head[i] = nullptr;
	}

	void addEdge(int u, int v){
		auto curr = head[u];
		Node *newNode = new Node();
		newNode->data = v;

		if (curr){
			newNode->next = curr;
			head[u] = newNode;
		}
		else{
			newNode->next = nullptr;
			head[u] = newNode;
		}

		curr = head[v];
		newNode = new Node();
		newNode->data = u;

		if (curr){
			newNode->next = curr;
			head[v] = newNode;
		}
		else{
			newNode->next = nullptr;
			head[v] = newNode;
		}
	}

	bool bfs(int src){
		bool *visited = new bool[V];
		int *color = new int[V];

		for (int i = 0; i < V; i++){
			visited[i] = false;
			color[i] = -1;
		}

		int *q = new int[2 * V];
		int front = -1, rear = -1;

		color[src] = 0;
		q[++rear] = src;

		while (front != rear){
			int u = q[++front];
			visited[u] = true;
			for (auto i = head[u]; i != nullptr; i = i->next){
				if (!visited[i->data]){
					q[++rear] = i->data;
					color[i->data] = 1 - color[u];
				}
				else{
					if (color[u] == color[i->data])
						return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	Graph g(6);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(2, 4);
	g.addEdge(2, 6);
	g.addEdge(3, 6);
	g.addEdge(3, 4);


	cout << g.bfs(1);
	getchar();
	return 0;
}
