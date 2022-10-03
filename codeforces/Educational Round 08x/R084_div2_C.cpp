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

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<pi> v(k);
    for (auto &[y, x]: v)cin >> y >> x;
    for (auto &[y, x]: v)cin >> y >> x;

    string r;
    for (int i = 1; i < n; i++)r += 'U';
    for (int i = 1; i < m; i++)r += 'L';
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            r += i % 2 == 0 ? 'R' : 'L';
        }
        r += 'D';
    }
    cout << r.size() << endl;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
