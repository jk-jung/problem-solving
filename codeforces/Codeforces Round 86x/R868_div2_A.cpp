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

int f(int x) { return x * (x - 1) / 2; }

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        if(f(i) + f(n - i) == k) {
            cout <<"YES\n";
            for(int j=0;j<i;j++)cout << "1 ";
            for(int j=i;j<n;j++)cout << "-1 ";
            cout << endl;
            return;

        }
    }
    cout <<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
