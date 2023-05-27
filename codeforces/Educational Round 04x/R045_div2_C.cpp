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

    ll a = 0;
    map<int, ll> b, c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int st = 0;
        for (char x: s) {
            st += x == '(' ? 1 : -1;
            if (st < 0) break;
        }
        if (st == 0) {
            a++;
            continue;
        }
        if (st > 0)b[st]++;

        st = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            char x = s[j];
            st += x == ')' ? 1 : -1;
            if (st < 0)break;
        }
        if (st > 0)c[st]++;
    }

    ll r = a * a;
    for (auto [x, y]: b) {
        r += y * c[x];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
