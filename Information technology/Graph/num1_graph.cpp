// №1. Дан ориентированный граф. Вывести количество вершин, смежных с данной.

#include <iostream> 
#include <algorithm> 
#include <vector> 
 
using namespace std; 
 
int n, m;                   // количество вершин и ребер в графе 
vector<vector<int>> Gr;     // список смежности графа 

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
        sort(Gr[i].begin(), Gr[i].end());                               // сортируем списки смежных вершин для каждой вершины 
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());   // удаляем дубликаты 
    } 
} 
 
 
int main() { 
    graph(); 
    int x; cout << "Required vertex: "; cin >> x;               // заданная вершина
    x--; 
    cout << "Number of adjacent vertices: " << Gr[x].size();    // количество вершин, смежных с заданной
}