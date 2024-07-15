#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    bool w;
    int to;
} warp;

int n, m, w;

warp arr[100];
bool visited[100];
bool checked[100];
int steps[100];

bool val(int pos) {
    // 1. 범위 맞나 검사
    if (pos < 0 || pos >= 100) {
        return false;
    }
    // 2. 방문 했나 검사
    if (visited[pos]) {
        return false;
    }
    // 3. 체크 했나 검사
    if (checked[pos]) {
        return false;
    }

    return true;
}

int move(int pos) {
    if (arr[pos].w) {
        return arr[pos].to;
    } else {
        return pos;
    }
}

void show();

void bfs() {
    queue<int> q;

    int start = 0;
    q.push(start);

    int phase = 0;
    int loops = 1;

    while (true) {
        int nextloops = 0;

        for (int i = 0; i < loops; i++) {
            int pp = q.front();
            q.pop();
            visited[pp] = true;

            steps[pp] = phase;

            int ppp;

            for (int j = 1; j <= 6; j++) {
                if (val(pp + j)) {
                    if(arr[pp+j].w){
                        visited[pp+j] = true;
                    }
                    checked[pp + j] = true;
                    ppp = move(pp + j);
                    q.push(ppp);
                    checked[ppp] = true;
                    nextloops++;
                }
            }

            show();
        }
        printf("\n");

        phase++;
        loops = nextloops;

        if (q.empty()) break;
    }
}

void show(){
    for(int i=0; i<100; i++){
        printf("%3d ", steps[i]);
        if(i%10 == 9)
            printf("|");
    }
    printf("\n");
}

int main() {
    cin >> n >> m;
    w = n + m;

    int f, t;
    for (int i = 0; i < w; i++) {
        cin >> f >> t;
        arr[f].w = true;
        arr[f].to = t;
    }

    bfs();
    cout << steps[99];
}