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
    vi v(n);
    map<int, int> ck, ck2;
    int idx = 0;
    for (int &x: v) {
        cin >> x;
        ck[x] = ++idx;
    }
    string s;
    cin >> s;
    for (char c: s) {
        if (c == '0') {
            auto [x, y] = *ck.begin();
            cout << y << " ";
            ck.erase(ck.begin());
            ck2[x] = y;
        } else {
            auto [x, y] = *ck2.rbegin();
            cout << y << " ";
            ck2.erase(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
