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
        vector<ll>parent,size; ll count; ll V;
        public:
        DisjointSet(ll n){
            count=n; V=n; 
            parent.push_back(0); size.push_back(1);
            for(int i=1;i<n+1;i++){
                parent.push_back(i); size.push_back(1);
            }
        }
        ll findparent(ll u){
            if(parent[u]==u){return u;}
            return parent[u]= findparent(parent[u]); //path compression also takes place
        }
        void unionfunc(ll u, ll v){
            ll pu=findparent(u); ll pv=findparent(v);
            if(pu==pv){return;}
            count--; //when two distinct ultimates parent(along with their subtrees) merge-the number of distinct parents must decrement
            if(size[pu]<size[pv]){
                parent[pu]=parent[pv];
                size[pv]+=size[pu];
                return;
            }
            parent[pv]=parent[pu];
            size[pu]+=size[pv];
            return;
        }
        bool cycledetect(ll u,ll  v){
            return findparent(u)==findparent(v);
        }
        bool samecompo(ll u,ll v){
            return findparent(u)==findparent(v);
        }
        ll size_compo(ll u){ 
            return size[findparent(u)]; //works in o(1)
        }
        ll distinct_compo(){
            return count;
        }
};
class someclass{
    public:
    inline static bool customcomp(vector<ll>&obj1, vector<ll>&obj2){ //custom comparator,pass 2 objects of the someclass
        return obj1[2]<obj2[2]; //use strict ()> or <) instead of (>=,<=) while writing custom comparator code
        //the custom compartor must always return false-when comparing 2 equal guys
    }
};
int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    ll n,m; cin>>n>>m;
    DisjointSet dsu(n);
    vector<vector<ll>>me(m,vector<ll>(3)); 
    for(int i=0;i<m;i++){
        cin>>me[i][0]>>me[i][1]>>me[i][2];
    }
    sort(me.begin(),me.end(),someclass::customcomp);
    vector<vector<ll>>ans; ll mst_sum=0;
    for(int i=0;i<m;i++){
        if(ans.size()==n-1){
            break;
        }
        if(dsu.samecompo(me[i][0],me[i][1])){
            dsu.unionfunc(me[i][0],me[i][1]); //can also ignore calling unionfunc here as with same ultimate parents-unionfunc does nothing
            continue;
        }
        dsu.unionfunc(me[i][0],me[i][1]);
        mst_sum+=me[i].weight;
        ans.push_back({me[i][0],me[i][1],me[i][2]});
    }
    if(dsu.distinct_compo()>1){cout<<-1;}
}  










