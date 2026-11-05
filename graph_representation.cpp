#include <bits/stdc++.h>
using namespace std;
// --- Companion macros required for this debugger ---
typedef long long ll;
#define f first
#define s second
// --- Master Debugger Block ---
// Debug Overloads
#ifdef SanG_05
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class... Args> void _print(unordered_set <Args...> v);
template <class... Args> void _print(unordered_multiset <Args...> v);
template <class... Args> void _print(unordered_map <Args...> v);
template <class... Args> void _print(unordered_multimap <Args...> v);
template <class... Args> void _print(list <Args...> v);
template <class... Args> void _print(forward_list <Args...> v);
template <class... Args> void _print(stack <Args...> v);
template <class... Args> void _print(queue <Args...> v);
template <class... Args> void _print(priority_queue <Args...> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_set <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_multiset <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_map <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_multimap <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(list <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(forward_list <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(stack <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class... Args> void _print(queue <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << "]";}
template <class... Args> void _print(priority_queue <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}

/*adjacency matrix UNDIRECTED GRAPH sc: o(n^2) where n is number of nodes,
tc for edge lookup of some k node is o(1) and tc for neighbours iterator of k is o(n)
*/
int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    ll n,m; cin>>n>>m;
    vector<vector<ll>>me(n+1,vector<ll>(n+1,0));
    for(ll i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        me[x][y]++; me[y][x]++;
    }
}
/*adjacency list UNDIRECTED GRAPH sc: o(2*e+n) where e is number of edges,
tc for edge lookup of some k node is o(deg(k)) and tc for neighbours iterator of k is o(deg(k))
*/
int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    ll n,m; cin>>n>>m;
    vector<vector<ll>>me(n+1);
    for(int i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        me[x].push_back(y);
        me[y].push_back(x);
    }
}
/*adjacency matrix DIRECTED GRAPH sc: o(n^2) where n is number of nodes,
tc for edge lookup of some k->j is o(1) and tc for neighbours iterator of k is o(n)
*/
int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    ll n,m; cin>>n>>m;
    vector<vector<ll>>me(n+1,vector<ll>(n+1,0));
    for(ll i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        me[x][y]++; //x->y
    }
}
/*adjacency list DIRECTED GRAPH sc: o(e+n) where e is number of edges,
tc for edge lookup of some k node is o(out-deg(k)) and tc for neighbours iterator of k is o(out-deg(k))
as me[i] stores all nodes which are directed from i to those nodes.
*/
int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    ll n,m; cin>>n>>m;
    vector<vector<ll>>me(n+1);
    for(int i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        me[x].push_back(y); //x->y
    }
}
//storing weights for matrix:store weight instead of just 1
//store pair {j,weight} instead of just j
