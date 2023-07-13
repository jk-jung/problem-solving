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
    vi v(n), r;
    for (int &x: v)cin >> x;
    reverse(v.begin(), v.end());
    set<int> ck;
    for (int x: v) {
        if(!ck.count(x))r.pb(x);
        ck.insert(x);
    }
    reverse(r.begin(), r.end());
    cout << r.size() << endl;
    for(int x:r)cout <<x <<" ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
