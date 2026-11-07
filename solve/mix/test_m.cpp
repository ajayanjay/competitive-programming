#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1, 0, 1, 0}; // up, right, down, left
int dc[4] = {0, 1, 0, -1};
int slash[4] = {1, 0, 3, 2};
int bslash[4] = {3, 2, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int r, c, d;
    cin >> r >> c >> d;
    r--; c--; // to 0-index

    vector visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));

    while (true) {
        // Check if out of bounds
        if (r < 0 || r >= n || c < 0 || c >= m) {
            cout << "EXIT\n";
            return 0;
        }

        // Cycle detection
        if (visited[r][c][d]) {
            cout << "LOOP\n";
            return 0;
        }
        visited[r][c][d] = true;

        // Handle mirror
        if (grid[r][c] == '/') {
            d = slash[d];
        } else if (grid[r][c] == '\\') {
            d = bslash[d];
        }

        // Move
        r += dr[d];
        c += dc[d];
    }
}