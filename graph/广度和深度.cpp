#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

#define N 4


int maze[N][N] = { {0,0,1,1}, 
				   {0,0,0,0}, 
				   {1,0,0,1}, 
				   {1,0,1,0}};



int visited[N] = {0};

void bfs(int start)    //图是根据maze[i][j]来找到孩子,通过额外标志visited来防止再次访问，因为图的指向很随便，没层次，还会指回来
{                      //而树一是有层次，所以不需要visited标志；而是有孩子指针，所以不需要判断数组的边权重是否是1
	queue<int> q;
	visited[start] = 1;
	q.push(start);
	cout << start << " ";
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		
		for (int j = 0; j < N; j++)
		{
			if (maze[i][j] == 1 && visited[j] == 0)
			{
				visited[j] = 1;
				cout << j<< " ";
				q.push(j);
			}
		}
	}
	cout << "子连通图遍历完成" << endl;
	
}

void dfs(int start)
{
	if (visited[start] == 1)    //终止条件
		return;    
	cout <<start<<" ";      //访问自己
	visited[start] = 1;   

	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0 && maze[start][i] == 1)  //visited[i] == 0这个写不写都没事
		{
			dfs(i);     //转移到孩子
		}
	}

}

int main()
{
	for (int i = 0; i < N; i++)
	{
		visited[i] = 0;
	}
	
	cout <<"广度优先遍历" << endl;
	for (int i = 0; i < N; i++)  //防止非连通图
	{
		if (visited[i]==0)
		{
			bfs(i);
		}
	}

	//------------------------
	for (int i = 0; i < N; i++)
	{
		visited[i] = 0;
	}

	cout << "深度优先遍历" << endl;
	for (int i = 0; i < N; i++)  //防止非连通图
	{
		if (visited[i] == 0)
		{
			dfs(i);
		}
	}



	while (1);
	return 0;
}
