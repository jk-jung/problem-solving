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
    string s;
    int n;
    vi v(26);
    cin >> s >> n;
    for (int &x: v)cin >> x;
    int r = 0;
    for (int i = 0; i < s.size(); i++) r += v[s[i] - 'a'] * (i + 1);
    sort(v.begin(), v.end());
    for (int i = s.size(); i < s.size() + n; i++) r += v[25] * (i + 1);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
