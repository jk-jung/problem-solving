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

string a, b;
ll A, B;

ll find_zero(int n) {
    for (char i = '1'; i <= '9'; i++) {
        ll x = stoll(string(n, i));
        if (x > B)return 0;
        if (A <= x && x <= B) return x;
    }
    return 0;
}

void solve() {
    cin >> a >> b;
    A = stoll(a);
    B = stoll(b);
    if (a.size() + 1 <= b.size()) {
        cout << string(a.size(), '9') << endl;;
    } else {
        for (int dif = 0; dif <= 9; dif++) {
            for (char x = '0'; x <= '9'; x++) {
                char y = x + dif;
                if (y > '9')continue;
                bool ok = true;
                string r;
                for (int i = 0; i < a.size(); i++) {
                    if (a[i] == b[i]) {
                        if (!(x <= a[i] && a[i] <= y)) {
                            ok = false;
                            break;
                        }
                        r += a[i];
                    } else {
                        string r1 = r + a[i] + string(a.size() - i - 1, y);
                        string r2 = r + b[i] + string(a.size() - i - 1, x);
                        if (x <= a[i] && a[i] <= y && a <= r1 && r1 <= b){r = r1; break;}
                        if (x <= b[i] && b[i] <= y && a <= r2 && r2 <= b){r = r2; break;}

                        bool t = false;
                        for (char c = max(x, char(a[i] + 1)); c <= min(y, char(b[i] - 1)); c++) {
                            string r3 = r + c + string(a.size() - i - 1, y);
                            if (x <= c && c <= y && a <= r3 && r3 <= b){
                                t = true;
                                r = r3; break;
                            }
                        }
                        if(t)break;
                        ok = false;
                    }
                }

                if (ok) {
                    cout << r << endl;
                    return;
                }
            }
        }
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
