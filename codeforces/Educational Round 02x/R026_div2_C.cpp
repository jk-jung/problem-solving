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
    int n, a, b;
    cin >> n >> a >> b;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;

    if (a > b)swap(a, b);

    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                swap(v[i].F, v[i].S);
                for (int l = 0; l < 2; l++) {
                    swap(v[j].F, v[j].S);
                    int t = v[i].F * v[i].S + v[j].F * v[j].S;
                    if (v[i].F + v[j].F <= a && max(v[i].S, v[j].S) <= b) r = max(r, t);
                    if (max(v[i].F, v[j].F) <= a && v[i].S + v[j].S <= b) r = max(r, t);
                }
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
