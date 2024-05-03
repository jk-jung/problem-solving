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

map<int, int> f(int n) {
    map<int, int> x;
    x[2] = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            x[i]++;
            n /= i;
        }
    }
    if (n > 1)x[n]++;
    return x;

}

void solve() {
    int a, b;
    cin >> a >> b;
    map<int, int> x = f(a), y = f(b);
    int r = 0;
    set<int> t;
    for(auto [k, v]: x)t.insert(k);
    for(auto [k, v]: y)t.insert(k);
    for (int k: t) {
        if(k == 2)continue;
        int xx = x[k], yy = y[k];
        if (xx == yy)continue;
        int dif = ab(xx - yy);
        r += dif;
        if(k == 3){
        }
        else if(k == 5){
        }
        else{
            cout << -1 << endl;
            return;
        }
    }
    cout << r + ab(x[2] - y[2]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
