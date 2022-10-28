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

int cnt(string s) {
    int r = 0;
    for (int i = 1; i < s.size(); i++)if (s[i - 1] == s[i]) r++;
    return r / 2;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << min(cnt("1" + s + "0"), cnt("0" + s + "1")) << endl;
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
