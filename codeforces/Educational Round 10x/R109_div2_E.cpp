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

ll mod = 998244353;

int n, m;
ll d[22][22][2];
int a[22][50005];
int v[22];

ll go(int x, int burden, int is_completed) {
    if (x == n + 1) return burden == 0 && is_completed == 1;

    ll &r = d[x][burden][is_completed];
    if (r != -1) return r;
    r = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)if (v[i] == x) cnt++;
    int rest = n - cnt - x + 1;


    if(rest) r += rest * go(x + 1, burden + 1, is_completed);
    if(cnt) r += cnt * go(x + 1, burden + cnt - 1, 1);
    if(burden) r += burden * go(x + 1, burden - 1, is_completed);

    return r;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    ll r = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)v[j] = a[j][i];
        memset(d, -1, sizeof(d));
        r += go(1, 0, 0);
        cout << i << " " << go(1, 0, 0) << endl;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
