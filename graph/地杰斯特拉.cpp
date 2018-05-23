#include <iostream>

using namespace std;
#define  N 4
#define  INF 10000
int maze[N][N]={{0,1,1,0},
                {1,0,1,1},
                {1,1,0,1},
                {0,1,1,0}};
int visited[N]={0};   //访问标志
int dis[N]={0};       //存放起点到此节点的最短距离
int pre[N]={0};    //存放每个结点的前驱

void dij(int start)
{
    for(int i=0;i<N;i++)
    {
        visited[i]=0;
        pre[i]=-1;
        if(maze[start][i]!=0)
            dis[i]=maze[start][i];
        else
            dis[i]=INF;
    }

    visited[start]=1;  //访问起点
    pre[start]=-1;


    for(int j=0;j<N;j++)  //这样是为了找下一个当前最短距离
    {
        int min=INF;
        int min_pos=start;
        for(int i=0;i<N;i++)   //访问其他节点找到最小值
        {
            if(maze[start][i]!=0&&visited[i]==0)  //只看没访问的孩子
            {
                if(dis[i]<min)   //找到最小的
                {
                    min=dis[i];
                    min_pos=i;
                }
            }
        }
        visited[min_pos]=1;  //这里是和start直连的
        if(maze[start][min_pos]!=0)
            pre[min_pos]=start;
        
        for(int i=0;i<N;i++)
        {
            if(maze[min_pos][i]==1&&visited[i]==0)
            {
                if(dis[i]>min+maze[min_pos][i])
                {
                    dis[i]=min+maze[min_pos][i]; //松弛，间接访问距离更小
                    pre[i]=min_pos;   //这里先附上前驱
                    //visited[i]=0;  //不能说明从最小值到现在的距离就是全局最小的距离
                }

            }
        }

    }


}

int main()
{




    return 0;

}
