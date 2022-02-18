#include <string.h>
#include <stdio.h>
#include <math.h>
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

const int mod = 998244353;
int n, m;
ll d[300005];
ll p2[300005];
string v[300005];

void solve() {
    memset(d, -1, sizeof(d));
    d[0] = 0;
    d[1] = 0;
    d[2] = 1;
    p2[0] = 1;
    for (int i = 1; i <= 300000; i++) p2[i] = p2[i - 1] * 2 % mod;
    for (int i = 3; i <= 300000; i++) d[i] = (p2[i - 3] + d[i - 2]) % mod;


    cin >> n >> m;
    int w = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (char x: v[i])w += (x == 'o');
    }

    ll r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0, c = 0; j < m; j++) {
            if (v[i][j] == 'o') {
                c++;
                r = (r + d[c] * p2[w - c]) % mod;
            } else c = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0, c = 0; j < n; j++) {
            if (v[j][i] == 'o') {
                c++;
                r = (r + d[c] * p2[w - c]) % mod;
            } else c = 0;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
