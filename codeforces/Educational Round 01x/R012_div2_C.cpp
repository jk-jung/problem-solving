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
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            if (i == s.size() - 1) {
                for (char a = 'a'; a <= 'z'; a++) {
                    if (a != s[i]) {
                        s[i] = a;
                        break;
                    }
                }
            } else {
                for (char a = 'a'; a <= 'z'; a++) {
                    if (a != s[i] && a != s[i + 1]) {
                        s[i] = a;
                        break;
                    }
                }
            }
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
