#include <iostream>
#include <vector>
#include <string>
#include <deque>

using std::cin, std::cout, std::ios_base, std::vector, std::string, std::deque;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)) return 0;
    
    vector<string> g(n);
    for(int i=0;i<n;i++) cin >> g[i];

    int N = n*m;
    vector<char> safe(N, 1);
    auto id = [&](int i,int j){ return i*m + j; };

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(g[i][j] != '.') safe[id(i,j)] = 0;

    for(int i=0;i<n;i++){
        bool active = false;
        for(int j=0;j<m;j++){
            char ch = g[i][j];
            if(ch == '.' && active) safe[id(i,j)] = 0;
            if(ch != '.'){
                if(ch == '>') active = true;
                else active = false;
            }
        }
    }

    // right -> left : '<' watches to the left
    for(int i=0;i<n;i++){
        bool active = false;
        for(int j=m-1;j>=0;j--){
            char ch = g[i][j];
            if(ch == '.' && active) safe[id(i,j)] = 0;
            if(ch != '.'){
                if(ch == '<') active = true;
                else active = false;
            }
        }
    }

    // top -> bottom : 'v' watches down
    for(int j=0;j<m;j++){
        bool active = false;
        for(int i=0;i<n;i++){
            char ch = g[i][j];
            if(ch == '.' && active) safe[id(i,j)] = 0;
            if(ch != '.'){
                if(ch == 'v') active = true;
                else active = false;
            }
        }
    }

    // bottom -> top : '^' watches up
    for(int j=0;j<m;j++){
        bool active = false;
        for(int i=n-1;i>=0;i--){
            char ch = g[i][j];
            if(ch == '.' && active) safe[id(i,j)] = 0;
            if(ch != '.'){
                if(ch == '^') active = true;
                else active = false;
            }
        }
    }

    int start = id(0,0), goal = id(n-1,m-1);
    if(!safe[start] || !safe[goal]){
        cout << -1 << '\n';
        return 0;
    }

    vector<int> parent(N, -1);
    deque<int> q;
    parent[start] = start;
    q.push_back(start);
    const int di[4] = {-1,1,0,0};
    const int dj[4] = {0,0,-1,1};

    while(!q.empty()){
        int u = q.front(); q.pop_front();
        if(u == goal) break;
        int ui = u / m;
        int uj = u % m;
        for(int k = 0; k < 4; k++){
            int ni = ui + di[k];
            int nj = uj + dj[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            int v = id(ni,nj);
            if(parent[v] == -1 && safe[v]){
                parent[v] = u;
                q.push_back(v);
            }
        }
    }

    if(parent[goal] == -1){
        cout << -1 << '\n';
        return 0;
    }

    int cur = goal;
    while(parent[cur] != cur){
        int ci = cur / m;
        int cj = cur % m;
        g[ci][cj] = 'X';
        cur = parent[cur];
    }
    
    g[0][0] = 'X';

    for(int i=0;i<n;i++) cout << g[i] << '\n';
    return 0;
}
