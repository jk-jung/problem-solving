#include <string.h>
#include <stdio.h>
#include <math.h>
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

struct Data {
    int a = 0, b = 0, id = 0;

    void swap() {
        int t = a;
        a = b;
        b = t;
    }
};

bool sf(Data &a, Data &b) {
    return a.a - a.b < b.a - b.b;
}

void solve() {
    int n, m, check = 0;
    ll a = 0, b = 0;
    cin >> n >> m;
    vector<Data> v(n), r(n);


    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b;
        a += v[i].a;
        b += v[i].b;
        v[i].id = i;
    }
    if (a > b) {
        swap(a, b);
        for (auto &x: v)x.swap();
        check = 1;
    }
    sort(v.begin(), v.end(), sf);
    for (auto& x: v) {
        int mm = m, t;
        if (b > a) {
            t = min(b - a, (ll) min(x.b, mm));
            r[x.id].b += t;
            x.b -= t;
            b -= t;
            mm -= t;
        }
        t = max(mm - x.a, min(x.b, (mm + 1) / 2));
        r[x.id].b += t;
        x.b -= t;
        b -= t;
        mm -= t;

        t = mm;
        r[x.id].a += t;
        x.a -= t;
        a -= t;
    }

    if(a > b) {
        check ^= 1;
        swap(a, b);
        for (auto &x: v)x.swap();
        for (auto &x: r)x.swap();
    }

    for (auto& x: v) {
        int i = x.id;
        if ((b - a) / 2 > 0 && r[i].a > 0 && x.b > 0) {
            int t = min((b - a) / 2, (ll)min(r[i].a, x. b));
            r[i].a -= t;
            r[i].b += t;
            a += t;
            b -= t;
        }
    }

    cout << ab(b - a) << '\n';
    if (check)
        for (auto &x: r)x.swap();

    for (auto x: r)cout << x.a << " " << x.b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}