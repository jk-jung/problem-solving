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
    map<int, int> ck;
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++)ck[v[i]] = i;

    int s = (n + 1) / 2, e = (n + 2) / 2;
    if(ck[s] > ck[e])cout << s << endl;
    else {
        while (s >= 2 && ck[s] <= ck[e] && ck[s - 1] < ck[s] && ck[e] < ck[e + 1]) s--, e++;
        cout << s - 1 << endl;
    }

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
