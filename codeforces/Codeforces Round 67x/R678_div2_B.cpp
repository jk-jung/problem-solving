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

int is_prime(int x) {
    int i = 2;
    while (i * i <= x) {
        if (x % i == 0) return false;
        i++;
    }
    return true;
}

int f(int x) {
    int y = x;
    while (true) {
        x++;
        if (is_prime(x) && !is_prime(x - y)) return x - y;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vi> v(n, vi(n, 1));
    int t = f(n - 1);
    for (int i = 0; i < n - 1; i++) {
        v[i][n - 1] = t;
        v[n - 1][i] = t;
    }
    v[n - 1][n - 1] = f(t * (n - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cout << v[i][j] << " ";
        cout << endl;
    }
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
