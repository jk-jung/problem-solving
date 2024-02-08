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

int c[1000005];
int d[1000005];
int ck[1000005], CK;

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int x: v) {
        cin >> x;
        int cnt = 0;
        ++CK;
        while (x) {
            int cnt2 = cnt + 1;
            int y = x * 2;
            while (y < 1000000 && ck[y] != CK) {
                ck[y] = CK;
                c[y]++;
                d[y] += cnt2;
                y *= 2;
                cnt2++;
            }

            ck[x] = CK;
            c[x]++;
            d[x] += cnt;
            cnt++;
            x /= 2;
        }
    }
    int r = 1 << 30;
    for (int i = 0; i < 1000000; i++) {
        if (c[i] == n) r = min(r, d[i]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
