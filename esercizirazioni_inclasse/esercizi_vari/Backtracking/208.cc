#include <iostream>
#include <vector>

using namespace std;

int E ;
vector <int> path;
vector < vector <int> > g;
vector <int> visited;

int  pathcnt = 0;

int check(int st) {
    int Q[25], Qt, i, j, used[25] = {}, tn;
    Q[0] = st;
    Qt = 0;
    for(i = 0; i <= Qt; i++) {
        tn = Q[i];
        if(tn == E) return 0;
        for(j = 1; j <= 21; j++) {
            if(visited[j] == 0 && g[tn][j] && used[j] == 0)
                used[j] = 1, Q[++Qt] = j;
        }
    }
    return 1;
}
void dfs(int nd, int dep) {
    int i;
    if(nd == E) {
        pathcnt++;
        printf("1");
        for(i = 0; i < path.size(); i++)
            printf(" %d", path[i]);
        puts("");
        return;
    }
    for(i = 1; i <= 21; i++) {
        if(g[nd][i] && visited[i] == 0) {
            if(check(i))
                continue;
            visited[i] = 1;
            path.push_back(i);
            dfs(i, dep+1);
            path.pop_back();
            visited[i] = 0;
        }
    }
}
int main() {
    int cases = 0, x, y;
    int i;
    while(scanf("%d", &E) == 1) {
        g.resize(22,vector <int>(22));
        visited.resize(22);
        while(scanf("%d %d", &x, &y) == 2 && x)
            g[x][y] = g[y][x] = 1;
        printf("CASE %d:\n", ++cases);
        pathcnt = 0;
        visited[1] = 1;
        dfs(1, 0);
        printf("There are %d routes from the firestation to streetcorner %d.\n", pathcnt, E);
    }
    return 0;
}
