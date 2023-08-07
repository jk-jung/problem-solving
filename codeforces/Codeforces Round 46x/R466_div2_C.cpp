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
    string t = s;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    if (n < k) {
        cout << s;
        for (int i = 0; i < k - n; i++)cout << t[0];
    } else {
        for (int i = k - 1; i >= 0; i--) {
            if (s[i] != t.back()) {
                for (int j = 0; j < i; j++)cout << s[j];
                for(char x: t) {
                    if(x > s[i]) {
                        cout << x;
                        break;
                    }
                }
                for(int j=i + 1;j<k; j++)cout << t[0];
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
