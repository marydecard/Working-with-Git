// №3. Дан ориентированный граф. Подсчитать полустепень захода каждой вершины.

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
        sort(Gr[i].begin(), Gr[i].end());                           // сортируем списки смежных вершин для каждой вершины 
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());   // удаляем дубликаты 
    } 
} 

// функция печати полустепени захода 
void indegree(vector<vector<int>> Gr){
    int count;
    for (int j = 0; j < Gr.size(); j++){
        count = 0;
        for (int i = 0; i < Gr.size(); i++)
            if (find(Gr[i].begin(), Gr[i].end(), j) != Gr[i].end()) count++;
        cout << "vertex " << j + 1 << " indegree: " << count << endl;
    }
}
 
// функция вывода двумерного массива
void print(vector<vector<int>> Gr){
    for (int i = 0; i < Gr.size(); i++){
        cout << "vertex " << i + 1 << ": ";
        for (auto it = Gr[i].begin(); it != Gr[i].end(); it++)
            cout << *it + 1 << " ";
        cout << endl;
    }
}
 
int main() { 
    graph(); 
    indegree(Gr);
    cout << endl;
    print(Gr);
}