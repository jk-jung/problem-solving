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

const int N = 33339;
int t[N + 5];
int y[N + 5];
int a, b;
vi p;

void f(int x, map<int, int> &r) {
    for (int i : p) {
        if(a == b) {
            if(i * i * i > x)break;
        }else {
            if(i * i > x)break;
        }
        while (x % i == 0)x /= i, r[i]++;
    }
    if (x != 1 && x < N && !t[x]) {
        r[x]++;
        x = 1;
    }
    if (x != 1)r[-1] = 1;
}

void solve() {
    cin >> a >> b;
    int g = gcd(a, b);
    if(a != 1 && b != 1 && g == 1) {
        cout << "No\n";
        return;
    }
    map<int, int> x;
    f(a, x);
    if (x.count(-1)) {
        cout << "No\n";
        return;
    }
    for (auto &[k, _]: x) {
        if(b % k) {
            cout << "No\n";
            return;
        }
        y[k] = 0;
        while (b % k == 0)b /= k, y[k]++;
    }
    if (b != 1) {
        cout << "No\n";
        return;
    }
    for (auto &[k, v1]: x) {
        int v2 = y[k];
        if (v2 == 0) {
            cout << "No\n";
            return;
        }
        bool ok = false;
        int d = (2 * v1 - v2) / 3;
        int c = (v2 - d) / 2;
        if (c >= 0 && d >= 0 && c + d * 2 == v1 && c * 2 + d == v2)ok = true;
        if (!ok) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i < N; i++) {
        if (!t[i]) {
            p.pb(i);
            for (int j = i + i; j < N; j += i)t[j] = 1;
        }
    }
    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
