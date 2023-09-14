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
    int n, k;
    cin >> n >> k;
    set<int> v;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            s |= x << j;
        }
        v.insert(s);
    }
    for (auto x: v) {
        for (auto y: v) {
            if ((x & y) == 0) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
