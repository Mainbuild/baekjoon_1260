#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[1001][1001]={0,};
bool visited[1001]={false,};
int N,M,V;

void DFS(int temp){
  cout<<temp <<" ";
  for(int i=1;i<=N;i++){
    if(map[temp][i]&&!visited[i]){
      visited[i]=true;
      DFS(i);
    }
  }
}

void BFS(int temp){
  queue<int> q;
  q.push(temp);
  visited[temp]=true;

  while(!q.empty()){
    temp=q.front();
    q.pop();
    cout<<temp<<" ";

    for(int i=1;i<=N;i++){
      if(map[temp][i]&&!visited[i]){

        visited[i]=true;
        q.push(i);
      }
    }
  }
}

int main(){
    cin>>N>>M>>V;
    for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      map[a][b]=1;
      map[b][a]=1;
    }

    visited[V]=true;
    DFS(V);
    cout<<endl;
    memset(visited, false, sizeof(visited));
    BFS(V);


    return 0;
}
