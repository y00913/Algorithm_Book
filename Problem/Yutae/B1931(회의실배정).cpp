#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, res = 0;
vector<pair<int, int>> v;


void solution() {
    sort(v.begin(), v.end());

    int a = 0;
    for (int i = 0; i < v.size(); i++) {
        if (a <= v[i].second) {
            a = v[i].first;
            res++;
        }
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ b,a });
    }

    solution();

    return 0;
}
