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
    int n;
    string a, b;
    cin >> n >> a >> b;
    vi v(4);
    vector<vi> idx(4);
    for (int i = 0; i < n; i++) {
        int st = (a[i] == '1' ? 1 : 0) + (b[i] == '1' ? 2 : 0);
        v[st]++;
        idx[st].pb(i + 1);
    }
    int m = n / 2;
    for (int i = 0; i <= v[1]; i++) {
        for (int j = 0; j <= v[3]; j++) {
            int x = i + j;
            int y = v[3] - j;
            int diff = x - y;
            int rest = m - y - (v[1] - i);
            int v2_to_x = v[2] - diff;
            if (x + v2_to_x > m || x > m || diff < 0 || rest < 0 || diff > v[2] || rest < diff) continue;

            for (int k = 0; k < i; k++)cout << idx[1][k] << " ", m--;
            for (int k = 0; k < j; k++)cout << idx[3][k] << " ", m--;
            for (int k = 0; k < v[2] - diff; k++) cout << idx[2][k] << " ", m--;
            for (int k = 0; k < m; k++)cout << idx[0][k] << " ";
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
