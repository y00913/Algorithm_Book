#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, res = 0;
priority_queue<int, vector<int>, greater<int>> pq;

void solution() {
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        res = res + a + b;

        pq.push(a + b);
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    solution();

    return 0;
}
