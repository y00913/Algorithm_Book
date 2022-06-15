#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> v;

bool compare(string a, string b) {
    if (a.size() < b.size()) {
        return true;
    }
    else if (a.size() == b.size()) {
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                sum1 += (a[i] - '0');
            }
        }

        for (int i = 0; i < b.size(); i++) {
            if (b[i] >= '0' && b[i] <= '9') {
                sum2 += (b[i] - '0');
            }
        }

        if (sum1 < sum2) {
            return true;
        }
        else if (sum1 == sum2 && a < b) {
            return true;
        }
    }

    return false;
}


void solution() {
    sort(v.begin(), v.end(), compare);

    for (auto elem : v) {
        cout << elem << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }

    solution();

    return 0;
}
