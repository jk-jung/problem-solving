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
    int n, m;
    cin >> n >> m;
    vector<pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F >> v[i].S;
    }
    int x = 0;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (v[i].F <= x && x < v[i].S) {
                x = v[i].S;
                done = false;
            }
        }
        if (done)break;
    }
    cout << (x == m ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
