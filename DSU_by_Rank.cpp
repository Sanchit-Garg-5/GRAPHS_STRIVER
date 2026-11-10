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
    
class DisjointSet{
        private:
        vector<ll>parent,rank; ll count; ll V;
        public:
        DisjointSet(ll n){
            count=n; V=n; 
            parent.push_back(0); rank.push_back(0);
            for(int i=1;i<n+1;i++){
                parent.push_back(i); rank.push_back(0);
            }
        }
        ll findparent(ll u){
            if(parent[u]==u){return u;}
            return parent[u]= findparent(parent[u]);
        }
        void unionfunc(ll u, ll v){
            ll pu=findparent(u); ll pv=findparent(v);
            if(pu==pv){return;}
            count--;
            if(rank[pu]==rank[pv]){
                rank[pv]++; parent[pu]=pv;
                return;
            }
            if(rank[pu]>rank[pv]){
                parent[pv]=parent[pu]; return;
            }
            parent[pu]=parent[pv]; return;
        }
        bool cycledetect(ll u,ll  v){
            return findparent(u)==findparent(v);
        }
        bool samecompo(ll u,ll v){
            return findparent(u)==findparent(v);
        }
        ll size_compo(ll u){ ll count1=0;
            for(int i=1;i<=V;i++){
                if(findparent(u)==findparent(i)){count1++;}
            } 
            return count1; //It works in o(V)
            // THIS MIGHT GIVE TLE, IN CASE TOO MANY QUERIES, AND TOO MANY NODES
        }
        ll distinct_compo(){
            return count;
        }
};
int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    ll n,m; cin>>n>>m;
    DisjointSet dsu(n);
}  










