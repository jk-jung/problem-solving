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
    int n = (s.size() + 19) / 20;
    int t = (n - s.size() % n) % n;
    int m = (s.size() + t) / n;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        int k = t / (n - i);
        int r = m - k;
        for (int j = 0; j < k; j++)cout << '*', t--;
        while (r--) {
            cout << s[0];
            if(s.size() > 0)
                s = s.substr(1);
        }
        cout << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
