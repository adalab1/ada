#include<bits/stdc++.h>
using namespace std;
int n;
int g[1000][1000],dist[1000],visited[1000];
// vector<int> v;
int TSP(int s){
    visited[s]=1;
    int f,k;
    for(int i=1;i<n;i++){
        if(s!=i&&!visited[i]){
            f=g[i][s]+TSP(i);
            if(dist[s]>f){
                dist[s]=f;
                // k=i;
            }
        }
    }
    // v.push_back(k);
    visited[s]=0;
    if(dist[s]==INT_MAX)return g[0][s];
    return dist[s];
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)dist[i]=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>g[i][j];
    }
    cout<<TSP(0)<<endl;
    // cout<<"0->";
    // for(int i=0;i<n;i++)cout<<v[i]<<"->";
    for(int i=0;i<n;i++)cout<<dist[i]<<" ";
}
