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
    cin >> n;
    vector<vi> v(n);
    map<int, int> ck;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v[i].resize(k);
        for (int j = 0; j < k; j++)cin >> v[i][j], ck[v[i][j]]++;
    }

    for (auto &t: v) {
        int k = 2;
        for (int x: t)k = min(k, ck[x]);
        if(k >= 2) {
            cout <<"Yes\n";
            return;
        }
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
