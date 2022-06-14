#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

int N, M;
int A[1001][1001];
int zero_area[1001][1001];
int visit[1001][1001];
int zero_area_cnt = 0;
vector<int> zero_area_v;
vector<pair<int, int>> v;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    int cnt = 1;

    q.push({ a,b });
    visit[a][b] = true;
    zero_area[a][b] = zero_area_cnt;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (visit[ny][nx]) continue;
            if (A[ny][nx] != 0) continue;

            q.push({ ny,nx });
            zero_area[ny][nx] = zero_area_cnt;
            visit[ny][nx] = true;
            cnt++;
        }
    }

    zero_area_v.push_back(cnt);
}

void solution() {
    memset(zero_area, -1, sizeof(zero_area));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 0 && !visit[i][j]) {
                bfs(i, j);
                zero_area_cnt++;
            }
        }
    }

    for (auto elem : v) {
        set<int> s;
        int y = elem.first;
        int x = elem.second;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (A[ny][nx] != 0) continue;

            if (s.find(zero_area[ny][nx]) == s.end()) {
                A[y][x] += zero_area_v[zero_area[ny][nx]];
                s.insert(zero_area[ny][nx]);
            }
        }

        A[y][x] %= 10;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << A[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            A[i][j] = s[j] - '0';

            if (A[i][j] == 1)
                v.push_back({ i,j });
        }
    }

    solution();

    return 0;
}
