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
    vi v(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        r[i] = i;
    }
    for (int k = 0; k < 2000; k++) {
        if (v == r) {
            cout << "Yes";
            return;
        }
        for (int i = 0; i < n; i++) {
            if (i % 2)v[i] = (v[i] - 1 + n) % n;
            else v[i] = (v[i] + 1) % n;
        }
    }
    cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
