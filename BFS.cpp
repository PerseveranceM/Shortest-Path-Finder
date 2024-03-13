#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
 

struct Node
{
    int x, y, dist;
};

struct Cord{
    int x;
    int y;
};
 
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };
 

bool isValid(vector<vector<char>> const &mat, vector<vector<bool>> &visited,
        int row, int col) {
    return (row >= 0 && row < mat.size()) && (col >= 0 && col < mat[0].size())
        && mat[row][col] != 'x' && !visited[row][col];
}
 

int findShortestPathLength(vector<vector<char>> const &mat, pair<int, int> &src,
                    pair<int, int> &dest, vector<vector<Cord>> &v)
{
    if (mat.size() == 0 || mat[src.first][src.second] == 'x' ||
            mat[dest.first][dest.second] == 'x') {
        return -1;
    }
 
    int M = mat.size();
    int N = mat[0].size();
 
    vector<vector<bool>> visited;
    visited.resize(M, vector<bool>(N));
 
    queue<Node> q;
    
    int i = src.first;
    int j = src.second;
 
    visited[i][j] = true;
    q.push({i, j, 0});

    int min_dist = INT_MAX;
 
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
 
        
        int i = node.x, j = node.y, dist = node.dist;
 
        if (i == dest.first && j == dest.second)
        {
            min_dist = dist;
            break;
        }
 
        
        for (int k = 0; k < 4; k++)
        {
            
            if (isValid(mat, visited, i + row[k], j + col[k]))
            {
                visited[i + row[k]][j + col[k]] = true;
                q.push({ i + row[k], j + col[k], dist + 1 });
                v[i + row[k]][j + col[k]] = {i, j};
            }
        }
    }
 
    if (min_dist != INT_MAX) {
        return min_dist;
    }
 
    return -1;
}
void Copy(Cord start, Cord goal, vector<vector<char>> &board, vector<vector<Cord>> v){
    int x = goal.x;
    int y = goal.y;
    int a,b;

while (true)
{
    a = (v[x][y]).x;
    b = (v[x][y]).y;
    if (a == start.x and b == start.y){break;}
    else{
    board[a][b] = '*';
    x = a;
    y = b;}
}
}
 void print(vector<vector<char>> board,int m,int n){
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        cout << board[i][j];
      }
      cout << endl;
    }
}

int main(){

    int m,n;
    cin >> m >> n;
    cin.ignore();
    string x;

    vector<vector<char>> board(m, vector<char>(n, '0'));
    vector<vector<Cord>> v(m, vector<Cord>(n, {0, 0}));

    for (int row = 0; row < m; row++){
        getline(cin, x);
    for (int col = 0; col < n; col++){
      board[row][col] = x[col];
    }
}

Cord start;
Cord goal;
for (int row = 0; row < m; row++){
    for (int col = 0; col < n; col++){
      if(board[row][col] == 'S'){start = {row, col};}
      if(board[row][col] == 'G'){goal = {row, col};}  
    }
}
    pair<int, int> src = make_pair(start.x, start.y);
    pair<int, int> dest = make_pair(goal.x, goal.y);
int min_dist = findShortestPathLength(board, src, dest, v);

if (min_dist != -1)
{                                                                                                                                                                                                          
Copy(start, goal, board, v);
print(board, m, n);
}
else{cout << "No Path" << endl;}

return 0;
}