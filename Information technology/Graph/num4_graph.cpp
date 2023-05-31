// №4. Дан ориентированный граф. Вывести все вершины, недостижимые из данной.

#include <iostream> 
#include <algorithm> 
#include <vector> 
 
using namespace std; 
 
int n, m;                   // количество вершин и ребер в графе 
vector<vector<int>> Gr;     // список смежности графа 
vector<int> path, used;
bool flag;

void graph(){ 
    cout << "n = "; cin >> n; cout << "m = "; cin >> m; 
    Gr.resize(n);                   // выделение памяти в векторе под n строк
    int x, y; 
    for (int i = 0; i < m; i++) {   // добавление ребер в список смежности 
        cin >> x >> y; 
        x--; y--; 
        Gr[x].push_back(y);         // поскольку граф ориентированный
    } 
    for (int i = 0; i < n; i++) { 
        sort(Gr[i].begin(), Gr[i].end());                           // сортируем списки смежных вершин для каждой вершины 
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());   // удаляем дубликаты 
    } 
} 


void dfs(vector<vector<int>> Gr, int current, vector<int>& used){
    used[current] = 1;
    path.push_back(current);

    for (int i = 0; i < Gr[current].size(); i++)
        if (used[Gr[current][i]] == 0)
            dfs(Gr, Gr[current][i], used);
}

int main(){
    graph();
    vector<int> used, path;
    int vertex; cout << "required vertex: "; cin >> vertex;
    vertex--;

    for (int i = 0; i < n; i++)
        used.push_back(0);

    dfs(Gr, vertex, used);

    for (int i = 0; i < used.size(); i++)
        if (used[i] == 0)
            cout << i + 1 << " ";
}