#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n), t;
    for (auto &x: v)cin >> x;
    t = v;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            int c = 0;
            for (int y = 0; y < 3; y++)
                for (int x = 0; x < 3; x++) {
                    if (x == 1 && y == 1)continue;
                    if (v[i + y][j + x] == '#')c++;
                }
            if (c == 8) {
                for (int y = 0; y < 3; y++)
                    for (int x = 0; x < 3; x++) {
                        if (x == 1 && y == 1)continue;
                        t[i + y][j + x] = '.';
                    }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if(t[i][j] == '#'){
                cout << "NO\n";
                return;
            }
        }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
