// №4. Дано дерево. Вывести узлы k-ого уровня.

#include <iostream>
using namespace std;

// структура дерева
struct tree{ 
    int inf;
    tree *right;
    tree *left;
};

// создание узла
tree *node(int x){ 
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    return n;
} 

// создание и заполнение исходного дерева
void create(tree *&tr, int n){
    int x;
    if (n > 0){                  // если количество элементов не 0
        cin >> x;
        tr = node(x);
        int l = n / 2;
        int r = n - l - 1;
        create(tr->left, l);      // заполнение левой ветки
        create(tr->right, r);     // заполнение правой ветки
    }
}

// вывод узлов заданного уровня
void levels(tree *tr, int required, int current){ 
    if (tr){
        if (required == current)                        // если находимся на нужном уровне, выводим значения
            cout << tr->inf << " ";                                      
        else if (required > current){                   // если находимся ниже нужного                             
            levels(tr->left, required, current + 1);    // смотрим левую ветку
            levels(tr->right, required, current + 1);   // смотрим правую ветку
        }
    }
}

// 10   4 5 3 7 8 6 9 1 2 0

int main(){
    tree *tr = NULL;
    int n; cout << "n = "; cin >> n;                        // количество элементов
    int level; cout << "required level: "; cin >> level;    // требуемый уровень
    create(tr, n);                                          // заполнение дерева
    cout << endl;
    levels(tr, level, 0);                                   // вывод узлов заданного уровня
}