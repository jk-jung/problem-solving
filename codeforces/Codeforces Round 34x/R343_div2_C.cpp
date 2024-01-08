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


ll mod = 1e9 + 7;
ll d[2005][2005];

ll go(int len, int open) {
    if (len == 0) return open == 0;
    if (len < open)return 0;
    if (open < 0) return 0;

    ll &r = d[len][open];
    if (r != -1) return r;

    return r = (go(len - 1, open + 1) + go(len - 1, open - 1)) % mod;
}

void solve() {
    memset(d, -1, sizeof(d));
    int n, m;
    string s;
    cin >> n >> m >> s;
    int st = 0;
    int mm = 0;
    for (const char x: s) {
        st += x == '(' ? 1 : -1;
        mm = min(mm, st);
    }

    ll r = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = n - m - i;
        for (int t = max(-mm, 0); t <= i; t++) {
            // 길아가 i개고 t 개가 열린 상태로 끝나는 경우
            // 길이가 j 개고 p 개가 닫힌 상태로 끝나는 경우
            int p = st + t;
            r = (r + go(i, t) * go(j, p)) % mod;
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
