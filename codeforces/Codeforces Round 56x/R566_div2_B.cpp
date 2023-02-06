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
char a[555][555];

void solve() {
    int n, m, cnt = 0;
    cin >> n >> m;

    int x = 1 << 30, xx = -1;
    int y = 1 << 30, yy = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> a[i][j];
            c = a[i][j];
            if (c == '*') {
                cnt++;
                x = min(x, j), xx = max(xx, j);
                y = min(y, i), yy = max(yy, i);
            }
        }
    }
    if(xx - x + 1 < 3 || yy - y + 1 < 3){
        cout <<"NO\n";
        return;
    }
    int aa = 0;
    set<int> ss;
    for (int i = y; i <= yy; i++) {
        int t = 0, ii = -1;
        for (int j = x; j <= xx; j++) if (a[i][j] == '*') t++, ii = j;
        if (t == 1) ss.insert(ii);
        else if (aa == 0 && i != y && i != yy && t == xx - x + 1) aa++;
        else {
            cout << "NO\n";
            return;
        }
        if (ss.size() > 1) {
            cout << "NO\n";
            return;
        }
    }
    if(aa == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
