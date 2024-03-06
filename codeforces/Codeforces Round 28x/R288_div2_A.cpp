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
    int n, m, k;
    cin >> n >> m >> k;
    set<pi> s;
    for(int r = 1;r<=k;r++){
        int a, b;
        cin >> a >> b;
        s.insert(mp(a, b));
        for (int i = -1; i <= 0; i++) {
            for (int j = -1; j <= 0; j++) {
                int y = a + i, x = b + j;
                if (y < 1 || y > n || x < 1 || x > m) continue;
                int c = 0;
                for(int ii = 0; ii <= 1; ii++) {
                    for(int jj = 0; jj <= 1; jj++) {
                        int yy = y + ii, xx = x + jj;
                        if (yy < 1 || yy > n || xx < 1 || xx > m) continue;
                        c += s.count(mp(yy, xx));
                    }
                }
                if(c == 4) {
                    cout << r << endl;
                    return;
                }
            }
        }
    }
    cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
