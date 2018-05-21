#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define Y second
#define X first

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long llint;

const int INF = 1e9;

map<int, set<int> > graf;
map<string, int> dict;
map<int, string> inv;
map<int, int> par;
stack<int> ans;
set<int> vis;
int n, f;

int conv(string &str) {
    auto it = dict.find(str);
    if (it != dict.end())
        return it -> Y;

    dict[str] = dict.size();
    return dict.size() - 1;
}

void build(string cur) {
    int x = conv(cur);
    if (vis.count(x))
        return;
    vis.insert(x);

    inv[x] = cur;
    for (int i = n - 1; i >= 0; --i) {
        for (char c = 'A'; c <= 'C'; ++c) {
            bool ok = (cur[i] != c);
            for (int j = i + 1; j < n && ok; ++j) {
                if (cur[j] == c || cur[i] == cur[j])
                    ok = false;
            }

            if (ok) {
                string nxt = cur;
                nxt[i] = c;

                build(nxt);
                int y = conv(nxt);
                graf[x].insert(y);
                graf[y].insert(x);
            }
        }
    }
}

int dijkstra(int x, int y) {
    priority_queue<int, vector<pii>, greater<pii> > pq;
    vi dist = vi(dict.size(), INF);
    pq.emplace(0, x);
    dist[x] = 0;
    par[x] = -1;

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        for (auto it: graf[cur.Y])
            if (dist[it] > cur.X + 1) {
                dist[it] = cur.X + 1;
                pq.emplace(dist[it], it);

                par[it] = cur.Y;
            }
    }

    return dist[y];
}

int main() {

    cin >> n;
    build(string(n, 'A'));
    cout << dijkstra(0, f = dict[string(n, 'C')]) << endl;

    for (int i = f; i != -1; i = par[i])
        ans.push(i);
    while (!ans.empty()) {
        cout << inv[ans.top()] << endl;
        ans.pop();
    }

    return 0;
}
