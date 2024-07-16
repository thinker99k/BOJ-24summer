#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct {
    vector<char> vf;
    int visz;
    vector<int> vi;
} Case;

int t;

char tmp1[100000];
char tmp2[200000];

void parser1(vector<char> &v) {
    int len = strlen(tmp1);
    for(int i=0; i<len; i++){
        v.push_back(tmp1[i]);
    }
}

void parser2(vector<char> &v) {

}

int main(void) {
    cin >> t;

    Case Cases[t];

    int arrsz;

    for (int i = 0; i < t; i++) {
        memset(tmp1, 0, 100000);
        memset(tmp2, 0, 100000);

        // 1. 명령어
        cin >> tmp1;
        parser1(Cases[i].vf);

        // 2. 배열 크기
        cin >> arrsz;
        Cases[i].visz = arrsz;
        Cases[i].vi.resize(arrsz);

        // 3. 배열
        cin >> tmp2;
        parser2();
    }

    return 0;
}