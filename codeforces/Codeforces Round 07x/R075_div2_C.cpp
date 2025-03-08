#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int d[20005][26];

void solve() {
    string a, b;
    cin >> a >> b;

    memset(d, -1, sizeof(d));
    for (int i = a.size() * 2 - 1; i >= 0; i--) {
        int idx = i % a.size();
        for (int x = 'a'; x <= 'z'; x++) {
            d[i][x - 'a'] = d[i + 1][x - 'a'];
            if (x == a[idx])d[i][x - 'a'] = i;
        }
    }
    int cur = 0;
    int r = 1;
    for (int k = 0; k < b.size(); k++) {
        int x = b[k] - 'a';
        if (d[cur][x] == -1) {
            cout << -1 << endl;
            return;
        }
        cur = d[cur][x] + (k == b.size() - 1 ? 0 : 1);
        if (cur >= a.size()) {
            cur -= a.size();
            r++;
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
