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

vi f(int n) {
    if (n == 1) return {1};
    else if (n == 2)return {1, 2};
    else if (n == 3)return {1, 1, 3};
    int m = n / 2;
    vi r(n - m, 1);
    for (int x: f(m))r.pb(x * 2);
    return r;
}

void solve() {
    int n;
    cin >> n;
    for (int x: f(n))cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
