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
    string s;
    cin >> n >> k;
    cin >> s;
    map<int, int> ck;
    for (char x: s)ck[x]++;
    int r = 0;
    for (char x = 'a'; x <= 'z'; x++) {
        char y = toupper(x);
        int a = ck[x], b = ck[y];
        r += min(a, b);
        int t = min(ab(a - b) / 2, k);
        r += t;
        k -= t;
    }
    cout << r << endl;
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
