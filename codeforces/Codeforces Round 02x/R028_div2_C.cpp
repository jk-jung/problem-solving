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

int n, m;
vi v;
double d[55][55][55];

void solve() {
    cin >> n >> m;
    v.resize(m);
    for (int &x: v)cin >> x;

    d[0][0][0] = 1;
    for (int i = 0; i < m; i++) {  // Room
        for (int j = 0; j <= n; j++) { // People
            for (int k = 0; k <= 50; k++) { // Max value
                double remain = n - j;
                double p = 1;
                for (int t = 0; t <= remain; t++) {
                    int q = (t + v[i] - 1) / v[i];
                    d[i + 1][j + t][max(k, q)] += d[i][j][k] * p;
                    p *= (remain - t) / double(t + 1) / double(m);
                }
            }
        }
    }

    double r = 0;
    for (int k = 0; k <= 50; k++)r += d[m][n][k] * k;
    printf("%.10lf", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
