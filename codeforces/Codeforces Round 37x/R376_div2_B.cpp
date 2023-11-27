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
    vi v(n);
    for (int &x: v)cin >> x;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] % 2)v[i]--, v[i + 1]--;
    }
    for(int x:v) {
        if(x < 0 || x % 2){
            cout <<"NO\n";
            return;
        }
    }
    cout <<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
