#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

double p = 3.14159265358979;

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    int s = n % 2 ? 0 : 1;
    double l = s == 0 ? 0 : v[0];
    double r = (v[s] * v[s] - l * l) * p;
    for (int i = s + 2; i < n; i += 2) {
        r += (v[i] * v[i] - v[i - 1] * v[i - 1]) * p;
    }
    printf("%.10lf", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
