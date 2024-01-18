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
    if(n == 0){
        cout << '+';
        return;
    }
    vector<string> r = {"++", "*+"};

    for (int i = 2; i <= n; i++) {
        vector<string> t;
        for (auto x: r) t.pb(x + x);
        for (auto x: r) {
            string y;
            for (auto c: x) y += (c == '+' ? '*' : '+');
            t.pb(x + y);
        }
        r = t;
    }
    for (auto &x: r)cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
