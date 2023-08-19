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
    cin >> s;
    int t = 0, k = 1 << 30;
    for (int i = s.size() - 1; i >= 0; i--) {
        s[i] += t;
        if (s[i] >= '5') t = 1, k = i;
        else t = 0;
    }
    if (t) {
        cout << 1;
    }
    if(k == (1 << 30))k = s.size();
    for (int i = 0; i < k; i++)cout << s[i];
    for (int i = k; i < s.size(); i++)cout << 0;
    cout << endl;
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
