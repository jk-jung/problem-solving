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

class Data {
public:
    vi v;
    int size, keys;
    ll s = 0;

    Data(int n) {
        v.resize(n + 1);
        size = keys = 0;
        s = 0;
    }

    void add(int x) {
        size++;
        if (v[x]++ == 0)keys++;
        s += x;
    }

    void sub(int x) {
        size--;
        if (--v[x] == 0)keys--;
        s -= x;
    }

    bool is_per() {
        ll s2 = (ll) size * (size + 1) / 2;
        return size == keys && s == s2;
    }
};

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    Data a(n), b(n);
    for (int x: v)a.add(x);
    vi r;
    for(int x: v){
        a.sub(x);
        b.add(x);
        if(a.is_per() && b.is_per()){
            r.pb(b.size);
        }
    }
    cout << r.size() << '\n';
    for (int x: r)cout << x << " " << n - x << '\n';
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
