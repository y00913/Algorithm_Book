#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int T, n;
string p;
deque<int> d;

void solution() {
    bool tf = true, error = false;

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == 'R') {
            if (tf) tf = false;
            else tf = true;
        }
        else {
            if (d.empty()) {
                error = true;
                break;
            }
            if (tf)
                d.pop_front();
            else
                d.pop_back();
        }
    }

    if (error) {
        cout << "error\n";
    }
    else {
        cout << "[";

        if (tf) {
            for (int i = 0; i < d.size(); i++) {
                cout << d[i];
                if (i != d.size() - 1) cout << ",";
            }
        }
        else {
            for (int i = d.size() - 1; i >= 0; i--) {
                cout << d[i];
                if (i != 0) cout << ",";
            }
        }

        cout << "]\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> p;
        cin >> n;

        string s , tmp = "";
        cin >> s;

        if (n != 0) {
            for (int j = 0; j < s.size(); j++) {
                if (s[j] >= '0' && s[j] <= '9') {
                    tmp = tmp + s[j];
                }
                else if (s[j] == ',' || s[j] == ']') {
                    d.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }

        solution();

        d.clear();
    }

    return 0;
}
