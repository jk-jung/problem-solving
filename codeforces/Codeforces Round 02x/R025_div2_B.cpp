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
    int n;
    string s;
    cin>> n >> s;

    if (s.size() % 2)cout << s.substr(0, 3), s = s.substr(3);
    else cout << s.substr(0, 2), s = s.substr(2);
    for (int i = 0; i < s.size(); i += 2) {
        cout << "-" << s[i] << s[i + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
