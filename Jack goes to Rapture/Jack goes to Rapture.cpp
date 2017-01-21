#include <forward_list>
#include <set>
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N, E;
    cin >> N >> E;
    forward_list<pair<int, int>> graph[N];
    int dist[N];
    dist[0] = 0;
    set<pair<int, int>> s;
    s.emplace(dist[0], 0);
    for(auto i = 1; i != N; i++) {
        dist[i] = INT_MAX;
        s.emplace(dist[i], i);
    }
    for(int a, b, c; cin >> a >> b >> c; ) {
        a--;
        b--;
        graph[a].emplace_front(b, c);
        graph[b].emplace_front(a, c);
    }
    while(!s.empty()) {
        auto current = s.begin()->second;
        s.erase(s.begin());
        for(auto& i : graph[current]) {
            auto d = max(i.second - dist[current], 0) + dist[current];
            if(dist[i.first] > d) {
                s.erase({dist[i.first], i.first});
                dist[i.first] = d;
                s.emplace(dist[i.first], i.first);
            }
        }
    }
    if(dist[N - 1] == INT_MAX) {
        cout << "NO PATH EXISTS";
    } else {
        cout << dist[N - 1];
    }
    return 0;
}
