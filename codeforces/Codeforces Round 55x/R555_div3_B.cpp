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
    string s;
    vi v(10);
    cin >> n >> s;
    for (int i = 1; i < 10; i++)cin >> v[i];
    for (int i = 0, flag = 0; i < n; i++) {
        int x = s[i] - '0';
        if (flag <= 1 && x < v[x]) {
            flag = 1;
            s[i] = v[x] + '0';
        } else if (flag && x > v[x])flag = 2;
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
