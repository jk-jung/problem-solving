#include <string.h>
#include <stdio.h>
#include <math.h>
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

int d[1000005];

int go(int x) {
    if(x == 0)return 1;
    if(x < 0)return 2;
    int &r = d[x];
    if(r) return r;
    r = 2;
    if(go(x - 2020) == 1)r = 1;
    if(go(x - 2021) == 1)r = 1;
    return r;
}

void solve() {
    int n;
    cin >> n;
    cout << (go(n) == 1? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
