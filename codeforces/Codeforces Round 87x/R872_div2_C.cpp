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
    int n, m;
    cin >> n >> m;
    int a = 0, b = 0;
    set<int> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == -1)a++;
        else if (x == -2)b++;
        else v.insert(x);
    }
    vi t = vector<int>(v.begin(), v.end());


    int last = 0, r = t.size() + min(m - (int)t.size(), a);
    for (int i = 0; i <= t.size(); i++) {
        int need = m - last - int(t.size()) + i;
        int left = last - i;
        r = max(r, min(left, a) + min(need, b) + (int) t.size());

        if(i < t.size())
            last = t[i];
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
