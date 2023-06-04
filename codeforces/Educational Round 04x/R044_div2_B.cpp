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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &s: v)cin >> s;
    vi c(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[j] += v[i][j] == '1';
        }
    }
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for(int j=0;j<m;j++)if(v[i][j] == '1' && c[j] == 1)ok = false;
        if(ok){
            cout <<"YES";
            return;
        }
    }
    cout <<"NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
