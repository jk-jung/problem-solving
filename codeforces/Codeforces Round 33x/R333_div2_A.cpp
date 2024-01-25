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


ll read() {
    int n, b;
    cin >> n >> b;
    ll r = 0;
    while (n--) {
        int x;
        cin >> x;
        r = r * b + x;
    }
    return r;
}

void solve() {
    ll a = read();
    ll b = read();
    if (a == b)cout << "=";
    else if (a > b)cout << ">";
    else cout << "<";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
