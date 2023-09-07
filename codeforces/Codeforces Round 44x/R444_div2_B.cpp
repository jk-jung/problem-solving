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

vi r;

void gen(vi a, vi b = {}, vi c = {}) {
    for (int x: a) {
        string t = to_string(x);
        r.pb(stoi(t));
        for (int y: b) {
            string tt = t + to_string(y);
            r.pb(stoi(tt));
            for (int z: c) {
                string ttt = tt + to_string(z);
                r.pb(stoi(ttt));
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vi> v(3);
    for (int i = 0; i < n; i++) {
        v[i].resize(6);
        for (int &x: v[i])cin >> x;
    }
    gen(v[0], v[1], v[2]);
    gen(v[0], v[2], v[1]);
    gen(v[1], v[0], v[2]);
    gen(v[1], v[2], v[0]);
    gen(v[2], v[0], v[1]);
    gen(v[2], v[1], v[0]);
    r.pb(0);
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    r.pb(-1);
    for (int i = 0; i < r.size(); i++) {
        if (r[i] != i) {
            cout << i - 1<< endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
