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

int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    ll n,m; cin>>n>>m;
    vector<bool>vis(n+1,0); 
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
    vector<vector<pair<ll,ll>>>me(n+1);
    for(int i=0;i<m;i++){
        ll x,y,w; cin>>x>>y>>w;
        //works only on undirected graph
        me[x].push_back({y,w}); me[y].push_back({x,w});
//In a directed graph, just because you can travel from Node A → B does not mean you can go from B → A.
//so growing tree from src, might make some nodes unreachable.
    }
    //above we created adjcancy list of n+1 size
    vector<ll>min_dist(n+1,LLONG_MAX);
    min_dist[0]=0;
    ll count_vis=0; //maintain this-helps in optimizing-if all nodes got visited-break
    ll mst_sum=0;
    vector<pair<ll,ll>>edge_save;
    pq.push({0,1,-1});
    while(!pq.empty()){
        if(count_vis>=n){break;}
        ll my=pq.top()[1]; 
        ll parent=pq.top()[2];
        ll dist=pq.top()[0]; 
        pq.pop();
        if(vis[my]){continue;}
//the above is important: imagine neighbour1, neighbour2 pushed me to the queue at some point(and they were able to push me into the pq)
//since both the times-I never surfaced to the top(hence I never becme visited).
//but now let us say neighbour1's(as my parent) version came to top and hence I got visited.
//so my second/stale version still in pq, should never get the right to (add my neighbours,incremenet count_vis,etc).
//so simply skip doing below code-If I had got visited earlier.
        mst_sum+=dist;
        vis[my]=true;
        count_vis++;
        if(parent!=-1){
            edge_save.push_back({parent,my}); //parent->me; 
            edge_save.push_back({my,parent}); //me->parent
            //since Prim's and Kruskal's algo help us find ONLY undirected spanning T/MST
        }
        if(count_vis>=n){break;}
        for(int i=0;i<me[my].size();i++){
            ll neighbor = me[my][i].first;
            ll weight = me[my][i].second;
            if(!vis[neighbour] && min_dist[neighbour]>weight){
                pq.push({weight,neighbour,my});
                min_dist[neighbour]=weight;
            }
//logic for min_dst
//Let I have 2 neighbours. let us say 1 share dist=2 with neighbour1, and dist=4 with neighbour2.
//so in MINIMUM SPANNING TREE- IT MAKES SENSE THAT (IF NOT ISSUE WITH NEIGHBOUR1)-THEN I SHOULD BE REACHABLE THROUGH NEIGHBOUR1 RATHER THAN THROUGH THE 2ND ONE
        }
    }
        if(count_vis<n){
            //spanning tree not even possible in disconnected graph
            cout<<-1; return;
        }
}  

