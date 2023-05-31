// №2. Дан ориентированный граф. Вставить в граф ребро, соединяющее вершины A и B.

#include <iostream> 
#include <algorithm> 
#include <vector> 
 
using namespace std; 
 
int n, m;                   // количество вершин и ребер в графе 
vector<vector<int>> Gr;     // список смежности графа 
int add_A, add_B;           // вершины, которые необходимо соединить ребром
 
void graph(){ 
    cout << "n = "; cin >> n; cout << "m = "; cin >> m; 
    Gr.resize(n);                   // выделение памяти в векторе под n строк
    int x, y; 
    for (int i = 0; i < m; ++i) {   // добавление ребер в список смежности 
        cin >> x >> y; 
        x--; y--; 
        Gr[x].push_back(y);         // поскольку граф ориентированный
    } 

    cout << "Connect vertices: "; cin >> add_A >> add_B;        // номера соединяемых вершин
    add_A--; add_B--;
    Gr[add_A].push_back(add_B);                                 // добавление ребра

    for (int i = 0; i < n; ++i) { 
        sort(Gr[i].begin(), Gr[i].end());                               // сортируем списки смежных вершин для каждой вершины 
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());   // удаляем дубликаты 
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
 
 
int main(){ 
    graph(); 
    print(Gr);
}