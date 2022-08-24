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
    cin >> n >> k >> s;
    map<char, int> cnt;
    for (char x: s)cnt[x]++;

    auto it = cnt.begin();
    if (cnt.size() == 1) {
        string r = string((it->S + k - 1) / k, it->F);
        cout << r << endl;
    } else if (it->S < k) {
        while (true) {
            k -= it->S;
            if (k <= 0)break;
            it++;
        }
        cout << it->F << endl;
    } else if (it->S > k) {
        it->S -= k - 1;
        string r;
        for (; it != cnt.end(); it++)
            r += string(it->S, it->F);
        cout << r << endl;
    } else {
        string r = string(1, it->F);
        it++;
        if (cnt.size() == 2) {
            r += string((it->S + k - 1) / k, it->F);
        } else {
            for (; it != cnt.end(); it++)
                r += string(it->S, it->F);
        }
        cout << r << endl;
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
