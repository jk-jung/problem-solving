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

void solve() {
    int n;
    cin >> n;
    vi v(n);
    int a = 0, b = 0;
    for (int &x: v){
        cin >> x;
        if(x == 100)a ++;
        else b ++;
    }
    if((a + b * 2) % 2 == 0 && (a == 0 && b % 2 == 0 || a >0))cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
