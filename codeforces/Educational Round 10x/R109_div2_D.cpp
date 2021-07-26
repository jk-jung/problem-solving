#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

int d[2505][5005];

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), a, b;
    memset(d, 63, sizeof(d));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 0)b.pb(i);
        else a.pb(i);
    }

    for (int i = 0; i <= b.size(); i++) d[0][i] = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            d[i + 1][j + 1] = min(d[i + 1][j], d[i][j] + ab(a[i] - b[j]));
        }
    }
    cout << d[a.size()][b.size()] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
