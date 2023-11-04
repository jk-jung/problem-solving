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

int d[1005][1005];
int d2[1005][1005];
int S[1005];
int S2[1005];

int M = 1000000007;

void solve() {
    int n;
    string s;
    vi a(26);
    cin >> n >> s;
    for (int &x: a)cin >> x;
    memset(d2, 63, sizeof(d2));
    memset(S2, 63, sizeof(S2));

    int r1 = 0;
    for (int i = 0; i < n; i++) {
        int limit = 1 << 30;

        for (int j = i; j >= 0; j--) {
            int x = s[j] - 'a';
            limit = min(limit, a[x]);
            if (i - j + 1 > limit)break;
            r1 = max(r1, i - j + 1);
            if (j == 0)d[j][i]++, d2[j][i] = 1;
            else {
                d[j][i] = (d[j][i] + S[j - 1]) % M;
                d2[j][i] = min(d2[j][i], 1 + S2[j - 1]);
            }
            S[i] = (S[i] + d[j][i]) % M;
            S2[i] = min(S2[i], d2[j][i]);
        }
    }
    cout << S[n - 1] << endl << r1 << endl << S2[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
