#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

int d[1005][1005][2][2], ck;

int go(int a, int b, int m, int u) {
    if(a == 0 && b == 0 && m == 0) return 0;

    int &r = d[a][b][m][u];
    if (r != ck) return r;

    if (a) r = min(r, 1 - go(a - 1, b + 1, m, 0));
    if (b) r = min(r, 1 - go(a, b - 1, m, 0));
    if (m) r = min(r, 1 - go(a, b, m - 1, 0));
    if (b > 0 && u == 0) r = min(r, - go(a, b, m, 1));

    return r;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0, m;

    for (int i = 0; i < n / 2; i++) {
        char z1 = s[i];
        char z2 = s[n - i - 1];
        if (z1 == '0' && z2 == '0') a++;
        else if (z1 == '0' || z2 == '0') b++;
    }
    m = (n % 2 == 1 && s[n / 2] == '0' ? 1 : 0);

    int r = go(a, b, m, 0);
    if (r < 0) cout << "ALICE\n";
    if (r > 0) cout << "BOB\n";
    if (r == 0) cout << "DRAW\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(d, 63, sizeof(d));
    ck = d[0][0][0][0];

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
