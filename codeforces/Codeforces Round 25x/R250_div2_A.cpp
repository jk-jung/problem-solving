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
    vector<string> v(4);
    for (auto &x: v) cin >> x;
    vi t;
    for (int i = 0; i < 4; i++)t.pb(int(v[i].size() - 2));
    vi k = t;
    sort(k.begin(), k.end());
    if (k[0] <= k[1] / 2 && k[2] * 2 <= k[3]) {
        cout << "C" << endl;
    } else if (k[0] <= k[1] / 2) {
        for (int i = 0; i < 4; i++) {
            if (t[i] == k[0]) {
                cout << char('A' + i) << endl;
                return;
            }
        }
    } else if (k[2] * 2 <= k[3]) {
        for (int i = 0; i < 4; i++) {
            if (t[i] == k[3]) {
                cout << char('A' + i) << endl;
                return;
            }
        }
    } else {
        cout << "C";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
