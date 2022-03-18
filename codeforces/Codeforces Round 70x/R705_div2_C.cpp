#include <string.h>
#include <stdio.h>
#include <math.h>
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

int n, k;
int nxt[100005];
string s;

map<char, int> cur;

bool can(map<char, int> &cnt, map<char, int> &now, int idx, int m) {
    cur.clear();
    for (auto[c, x]: now) {
        if (x % k == 0)continue;
        int need = k - x % k;
        m -= need;
        cur[c] += need;
        if (m < 0)return false;
    }
    if (m % k)return false;
    cur['z'] += m;

    int i = idx;
    for (char x = 'z'; x >= 'a' && i < n; x--) {
        int c1 = cur[x];
        if (c1 == 0)continue;
        if (x < s[i]) return false;
        if (x > s[i]) return true;

        int c2 = nxt[i] - i;

        if (c1 < c2) return false;
        if (c1 > c2) {
            if(s[nxt[i]] > x) return false;
            return true;
        }
        i = nxt[i];
    }
    return true;
}


void solve() {
    cin >> n >> k >> s;
    if (n % k) {
        cout << -1 << endl;
        return;
    }

    map<char, int> cnt, now;
    for (char x: s)cnt[x]++;
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1)nxt[i] = n;
        else {
            if (s[i] == s[i + 1])nxt[i] = nxt[i + 1];
            else nxt[i] = i + 1;
        }
    }

    string r;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]--;
        now[s[i]]++;
        if (can(cnt, now, i + 1, n - i - 1)) {
            r += s[i];
        } else {
            now[s[i]]--;
            cur.clear();
            int m = n - i;
            for (auto[c, x]: now) {
                if (x % k == 0)continue;
                int need = k - x % k;
                m -= need;
                cur[c] += need;
            }

            for (char x = s[i] + 1; x <= 'z'; x++) {
                if (cur.count(x) && cur[x] > 0) {
                    r += x;
                    cur[x]--;
                    break;
                }else if(m) {
                    cur[x] = k - 1;
                    m -= k;
                    r += x;
                    break;
                }
            }

            while (m--)r += 'a';
            for (auto[c, x]: cur) {
                while (x--) r += c;
            }

            break;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
