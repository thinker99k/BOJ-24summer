#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<string, int> m1; // 이름 -> 번호
map<int, string> m2; // 번호 -> 이름

int N, M;
char tmp[21];

int main(void){
    ios::sync_with_stdio(false);

    cin >> N >> M; // 마리 수, 문제 수
    getchar();

    for(int i=1; i<=N; i++){
        memset(tmp, 0, 21);
        cin >> tmp;
        m1[string(tmp)] = i;
        m2[i] = string(tmp);
    }

    for(int i=0; i<M; i++){
        memset(tmp, 0, 21);
        cin >> tmp;

        if(atoi(tmp) == 0){ // 이름 -> 번호
            cout << m1[tmp] << "\n";
        }
        else{ // 번호 -> 이름
            cout << m2[atoi(tmp)] << "\n";
        }
    }
}