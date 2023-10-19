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

bool sf(pi &a, pi &b) {
    return double(a.S) / double(a.F) < double(b.S) / double(b.F);
}

void solve() {
    int n, p;
    cin >> n >> p;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;
    sort(v.begin(), v.end(), sf);
    v.pb(pi(1, 1));
    double s = 0, e = 1e20;
    for (int _ = 0; _ < 300; _++) {
        double m = (s + e) / 2;
        double tot = v[0].F, last = double(v[0].S) / v[0].F, rest = last * p;
        for (int i = 1; i <= n; i++) {
            auto [speed, capa] = v[i];
            double t = capa / double(speed);
            if (i == n)t = 1e20;
            double need = t - last;

            double t2 = rest / (tot - p);
            if (t2 >= 0 && t2 <= need) {
                last += t2;
                break;
            }
            rest = rest + need * p - need * tot;
            tot += speed;
            last = t;
        }

        if (last <= m)e = m;
        else s = m;
    }
    if(s > 1e19){
        cout << "-1\n";
    }else
        printf("%.10lf\n", s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
