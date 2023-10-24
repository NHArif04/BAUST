#include<iostream>
#include<queue>

using namespace std;

const int Max_Nodes = 100;

void BFS(int graph[Max_Nodes][Max_Nodes], int numNodes, int startNode){
    bool visited[Max_Nodes] = {false};
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);
    while(!q.empty()){
        int currentNode = q.front();
        cout<<currentNode<<" ";
        q.pop();

        for(int neighbor=0; neighbor<numNodes; ++neighbor){
            if(graph[currentNode][neighbor] == 1 && !visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout<<endl;
}


int main(){
    int numNodes = 4;
    int graph[Max_Nodes][Max_Nodes]={
        {0,1,0,1},
        {1,0,1,1},
        {0,1,0,0},
        {1,1,0,0}
    };

    BFS(graph, 16, 0);
    return 0;
}