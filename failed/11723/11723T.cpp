#include <iostream>
#include <cstring>

using namespace std;

int t;

char func[7];
int tmp;

const char *words[6] = {"add", "remove", "check",
                        "toggle", "all", "empty"};

int wordlen[6] = {3, 6, 5,
                  6, 3, 5};

int parser() {
    for (int i = 0; i < 6; i++) {
        if (strcmp(func, words[i]) == 0) {
            return i + 1;
        }
    }

    return -1;
}

bool b[21];

void hdlr() {
    int sel = parser();
    //cout << "case " << sel << endl;
    switch (sel) {
        case 1: // add
            if (!b[tmp]) {
                b[tmp] = true;
            }
            break;

        case 2: // remove
            if (b[tmp]) {
                b[tmp] = false;
            }
            break;

        case 3: // check
            if (b[tmp]) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
            break;

        case 4: // toggle
            b[tmp] = !b[tmp];
            break;

        case 5: // all
            memset(b, true, 21);
            break;

        case 6: // empty
            memset(b, false, 21);
            break;

        default:;
    }
}

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        memset(func, 0, 7);
        tmp = 0;

        cin >> func;
        if (parser() < 5) {
            cin >> tmp;
        } else {
            getchar();
        }

        hdlr();
        /*
        for(int j=1; j<=20; j++){
            printf("%d ", b[j]);
        }
        */
    }
}