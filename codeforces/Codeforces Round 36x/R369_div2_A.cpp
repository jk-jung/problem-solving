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
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        if (v[i][0] == 'O' && v[i][1] == 'O') {
            v[i][0] = v[i][1] = '+';
            cout << "YES" << endl;
            for(auto x: v)cout << x << endl;
            return;
        }
        if (v[i][3] == 'O' && v[i][4] == 'O') {
            v[i][3] = v[i][4] = '+';
            cout << "YES" << endl;
            for(auto x: v)cout << x << endl;
            return;
        }
    }
    cout <<"NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
