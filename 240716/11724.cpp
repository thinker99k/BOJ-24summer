#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E;
vector<int> Vertex[1001];
bool visited[1001];

int ans = 0;

void bfs(int s){
    queue<int> q;

    q.push(s);
    visited[s] = true;

    int changes = 1;

    while (true) {
        size_t sz = q.size();

        for(int z=0; z<(int)sz; z++){
            int p = q.front();
            q.pop();

            int k;
            for(int i=0; i<Vertex[p].size(); i++){
                k = Vertex[p][i];
                if (!visited[k]){
                    q.push(k);
                    visited[k] = true;
                    changes++;
                }
            }
        }

        if(q.empty()) break;
    }

    //cout << s << " changes: " << changes << endl;

    if(changes > 1){
        ans++;
    }
}

int main(){
    cin >> V >> E;

    int tmp1, tmp2;
    for(int i=0; i<E; i++){
        cin >> tmp1 >> tmp2;

        Vertex[tmp1].push_back(tmp2);
        Vertex[tmp2].push_back(tmp1);
    }

    for(int i=1; i<=V; i++){
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    for(int i=1; i<=V; i++){
        bfs(i);
    }

    cout << ans;

}