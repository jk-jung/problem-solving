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
    cin >> n >> s;

    map<char, int> ck;
    for (int i = 0; i < n; i++) {
        for (char x = s[i] + 1; x <= 'z'; x++) {
            if (ck.count(x)) {
                cout << "YES\n";
                cout << ck[x] + 1 << " " << i + 1<< endl;
                return;
            }
        }
        ck[s[i]] = i;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
