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
    cin>>s;
    map<char, int> ck;
    for (int i = 25; i < s.size(); i++) {
        vi v(26);
        int t = 0, cc = 0;
        for (int k = i - 25; k <= i; k++) {
            if (s[k] != '?') {
                if (v[s[k] - 'A']++ == 0)cc++;
            } else t++;
        }
        if (cc + t == 26) {
            for (int k = i - 26; k <= i; k++) {
                if (s[k] == '?') {
                    for (int j = 0; j < 26; j++) {
                        if (v[j] == 0) {
                            s[k] = 'A' + j;
                            v[j] = 1;
                            break;
                        }
                    }
                }
            }
            for (int k = 0; k < s.size(); k++)if (s[k] == '?')s[k] = 'A';
            cout << s << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
