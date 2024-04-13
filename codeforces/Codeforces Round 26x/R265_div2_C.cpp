
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

int n, m;
string s;

void check(int i) {
    for (int j = s[i] - 'a' + 1; j < m; j++) {
        char t = 'a' + j;
        char x = i - 1 >= 0 ? s[i - 1] : ' ';
        char y = i - 2 >= 0 ? s[i - 2] : ' ';
        if (t != x && t != y) {
            cout << s.substr(0, i) + t;
            char a = s[i - 1];
            char b = t;
            for (int k = i + 1; k < n; k++) {
                char c = 'a';
                while (c == a || c == b) c++;
                cout << c;
                swap(a, b);
                swap(b, c);
            }
            exit(0);
        }
    }

}

void solve() {
    cin >> n >> m >> s;

    if (n == 1) {
        for (int i = 0; i < m; i++) {
            if (s[0] < 'a' + i) {
                cout << (char) ('a' + i) << endl;
                return;
            }
        }
        cout << "NO" << endl;
    } else if (n == 2) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if(i == j)continue;
                string t = "";
                t += (char) ('a' + i);
                t += (char) ('a' + j);
                if (t > s) {
                    cout << t << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    } else {
        for (int i = n - 1; i >= 0; i--)
            check(i);
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
