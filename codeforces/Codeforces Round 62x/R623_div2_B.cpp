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
    int a, b, p;
    string s;
    cin >> a >> b >> p >> s;
    int n = s.size();

    int r = n, cost = 0;
    s[n - 1] = 'F';
    for (int i = n - 2; i >= 0; i--) {
        if(s[i] != s[i + 1]) cost += s[i] == 'A' ? a : b;
        if (cost > p)break;
        r = i + 1;
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
