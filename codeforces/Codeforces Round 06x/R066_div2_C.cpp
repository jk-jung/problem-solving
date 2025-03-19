#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int c[255][255];
int d[105][105][255];


void set_max(int &r, int t) {
    r = max(r, t);
}

void solve() {
    string s;
    int k, n;
    cin >> s >> k >> n;
    while (n--) {
        string a, b;
        int t;
        cin >> a >> b >> t;
        c[a[0]][b[0]] = t;
    }
    n = s.size();
    memset(d, 129, sizeof(d));
    d[0][0]['a' - 1] = 0;

    int r= -(1 << 30);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int y = 'a'; y <= 'z'; y++) {
                for (int x = 'a' - 1; x <= 'z'; x++) {
                    if (d[i][j][x] == -1)continue;
                    int t = s[i] == y ? 0 : 1;
                    set_max(d[i + 1][j + t][y], d[i][j][x] + c[x][y]);
                    if(i == n - 1 && j + t <= k)
                        set_max(r, d[i + 1][j + t][y]);
                }
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
