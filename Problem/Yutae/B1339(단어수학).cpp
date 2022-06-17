#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, res = 0;
vector<string> v;
int a[26];

void solution() {
    for (int i = 0; i < v.size(); i++) {
        int digit = 1;

        for (int j = v[i].size() - 1; j >= 0; j--) {
            a[v[i][j] - 'A'] += digit;
            digit *= 10;
        }
    }

    sort(a, a + 26);

    int num = 9;
    for (int i = 25; i >= 0; i--) {
        res = res + a[i] * num;
        num--;
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    solution();

    return 0;
}
