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
    string s;
    cin >> s;
    int n;
    cin >> n;
    vi v(s.size());
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x - 1]++;
    }
    v[0] %= 2;
    for (int i = 1; i < s.size() / 2; i++)v[i] = (v[i] + v[i - 1]) % 2;
    for (int i = 0; i < s.size() / 2; i++) {
        if (v[i]) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
