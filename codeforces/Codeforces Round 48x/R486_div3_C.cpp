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
    map<int, pi> ck;
    for (int i = 0; i < n; i++) {
        int k, s = 0;
        cin >> k;
        vi v(k);
        for (int &x: v)cin >> x, s += x;
        for (int j = 0; j < k; j++) {
            int t = s - v[j];
            if (ck.count(t)) {
                cout << "YES\n";
                cout << ck[t].F << " " << ck[t].S << endl;
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
        for (int j = 0; j < k; j++) {
            int t = s - v[j];
            ck[t] = {i + 1, j + 1};
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
