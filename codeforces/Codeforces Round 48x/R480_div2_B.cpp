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
    int n, k;
    cin >> n >> k;
    string r1 = string(n, '.');
    string r2 = string(n, '.');


    if (k % 2 == 0) {
        for (int i = 1; i <= k / 2; i++)r1[i] = '#';
        r2 = r1;
    } else {
        int m = n / 2;
        r1[m] = '#', k--;
        for (int s = m - 1, e = m + 1; e < n - 1 && k > 0; s--, e++, k -= 2)r1[s] = r1[e] = '#';
        for (int i = 1; k > 0; k -= 2, i++)r2[i] = r2[n - i - 1] = '#';
    }
    cout << "YES\n";
    cout << string(n, '.') << endl;
    cout << r1 << endl << r2 << endl;
    cout << string(n, '.') << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
