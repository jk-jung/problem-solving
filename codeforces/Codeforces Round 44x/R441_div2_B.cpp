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

vi v[100005];

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x % m].pb(x);
    }
    for (int i = 0; i < m; i++) {
        if (v[i].size() >= k) {
            cout << "Yes" << endl;
            for (int j = 0; j < k; j++)cout << v[i][j] << " ";
            cout << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
