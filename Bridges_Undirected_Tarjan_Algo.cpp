//https://leetcode.com/problems/critical-connections-in-a-network/
class Solution {
public: int count=0;
    void dfs(int i,vector<vector<int>>&al,int parent,vector<vector<int>>&ans,vector<bool>&vis,vector<int>&time,vector<int>&mintime){
        time[i]=count; vis[i]=true; mintime[i]=min(mintime[i],time[i]);
        for(int j=0;j<al[i].size();j++){
            if(vis[al[i][j]] && al[i][j]==parent){continue;}
            if(vis[al[i][j]] && al[i][j]!=parent){mintime[i]=min(mintime[i],mintime[al[i][j]]);}
            else{ count++;
                dfs(al[i][j],al,i,ans,vis,time,mintime);
                mintime[i]=min(mintime[i],mintime[al[i][j]]);
                if(time[i]<mintime[al[i][j]]){ans.push_back({i,al[i][j]});}
            }
        }
    }
    vector<vector<int>>criticalConnections(int n,vector<vector<int>>& connections){
        vector<vector<int>>al(n);
        for(int i=0;i<connections.size();i++){
            al[connections[i][0]].push_back(connections[i][1]);  al[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>>ans;
        vector<bool>vis(n,0); vector<int>time(n); vector<int>mintime(n,INT_MAX); int count=0;
        dfs(0,al,-1,ans,vis,time,mintime);
        return ans;
    }
};
