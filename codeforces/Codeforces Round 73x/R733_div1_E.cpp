#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

vector<int> prefix_function(string s) {
    vector<int> pi(s.size());
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void test(string s) {
    auto t = prefix_function(s);
    for (int i = 0; i < t.size(); i++)cout << t[i] << " ";
    cout << endl;
}

void solve() {
    string s;
    cin >> s;
    vector<int> v(26);
    for (int i = 0; i < s.size(); i++) {
        v[s[i] - 'a']++;
    }

    int k = -1;
    int k2 = -1;
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (v[i] > 0 && k == -1) {
            k = i;
        }
        if (v[i] == 1 && k2 == -1) {
            k2 = i;
        }
        if (v[i] > 0)cnt++;
    }

    string r;
    if (k2 != -1) {
        r += char(k2 + 'a');
        v[k2] -= 1;
        for (int i = 0; i < 26; i++) {
            while (v[i]--) {
                r += char(i + 'a');
            }
        }
    } else if (v[k] >= 3 && v[k] != s.size()) {
        int nk = v[k] - 2;
        int rest = int(s.size()) - v[k];

        if (nk <= rest) {
            r += char(k + 'a');
            r += char(k + 'a');
            v[k] -= 2;
            for (int i = k + 1; i < 26; i++) {
                while (v[i]--) {
                    r += char(i + 'a');
                    if (v[k] > 0) {
                        r += char(k + 'a');
                        v[k]--;
                    }
                }
            }
        } else if (cnt == 2) {
            r += char(k + 'a');
            v[k] -= 1;
            for (int i = k + 1; i < 26; i++) {
                while (v[i]--) {
                    r += char(i + 'a');
                }
            }
            while (v[k] > 0) {
                r += char(k + 'a');
                v[k]--;
            }
        } else {
            r += char(k + 'a');
            v[k] -= 1;
            bool flag = true;
            for (int i = k + 1; i < 26; i++) {
                while (v[i]--) {
                    r += char(i + 'a');
                    if (flag) {
                        while (v[k] > 0) {
                            r += char(k + 'a');
                            v[k]--;
                        }
                        for (int j = i + 1; j < 26; j++) {
                            if (v[j] > 0) {
                                r += char(j + 'a');
                                v[j]--;
                                break;
                            }
                        }
                        flag = false;
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < 26; i++) {
            while (v[i]--)r += char(i + 'a');
        }
    }
    if(r.size() != s.size()) exit(1);
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
