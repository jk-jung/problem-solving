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


constexpr int P = 1000000007;

// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Z {
    int x;

    Z(int x = 0) : x(norm(x)) {}

    int val() const {
        return x;
    }

    Z operator-() const {
        return Z(norm(P - x));
    }

    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }

    Z &operator*=(const Z &rhs) {
        x = ll(x) * rhs.x % P;
        return *this;
    }

    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }

    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }

    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }

    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }

    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }

    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }

    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

void solve() {
    int n, m, y, x, rd, cd, pp;
    cin >> n >> m >> y >> x >> rd >> cd >> pp;

    x--, y--;
    rd--, cd--;

    Z p = Z(pp) / 100;
    Z q = 1 - p;

    int dy = y == n - 1 ? -1 : 1;
    int dx = x == m - 1 ? -1 : 1;
    auto init = tuple(y, x, dy, dx);

    Z u = 0, v = 1;
    do {
        if (y == rd || x == cd) v *= q;
        u += v;

        y += dy;
        x += dx;

        if (y == 0 || y == n - 1) dy = -dy;
        if (x == 0 || x == m - 1) dx = -dx;
    } while (tuple(y, x, dy, dx) != init);
    Z r = u / (1 - v);
    cout << r.val() << endl;
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
