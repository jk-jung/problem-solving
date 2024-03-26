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
    vector<pair<string, string> > v(n), t(n);
    for (auto &[x, y]: v)cin >> x >> y;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        t[i] = v[x - 1];
    }
    string r;
    for(auto &[x, y]: t){
        if(r < x && r < y)r = min(x, y);
        else if(r < x)r = x;
        else if(r < y)r = y;
        else {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
