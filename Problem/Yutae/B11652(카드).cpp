#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; 
long long res;
vector<long long> v;

void countCard() {
    sort(v.begin(), v.end());

    res = v[0];
    long long tmp = v[0]; 
    int cnt = 1, max_cnt = 0;
    for (int i = 1; i < v.size(); i++) {
        if (tmp == v[i]) {
            cnt++;
            if (i == v.size() - 1 && max_cnt < cnt) {
                res = tmp;
            }
        }
        else {
            if (max_cnt < cnt) {
                res = tmp;
                max_cnt = cnt;
            }
            cnt = 1;
        }
        tmp = v[i];
    }
}

void solution() {
    countCard();
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        v.push_back(a);
    }

    solution();

    return 0;
}
