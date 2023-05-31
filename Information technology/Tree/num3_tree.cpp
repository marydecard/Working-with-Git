// №3. Дано дерево. Подсчитать сумму листьев.

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

// прямой обход (К-Л-П)
void preorder(tree *tr){ 
   if (tr){
      cout << tr->inf << " "; // корень
      preorder(tr->left);     // левое
      preorder(tr->right);    // правое
   }
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

// функция подсчета суммы листьев
int leaves(tree *tr){ 
    int sum = 0;
    if (!tr) return 0;
    if (!tr->left && !tr->right) sum = tr->inf;         // если нет ни правого, ни левого потомка => значит лист
    return sum + leaves(tr->right) + leaves(tr->left);  // рекурсивно считаем сумму листьев         
}

// 10   4 5 3 7 8 6 9 1 2 0

int main(){
    tree *tr = NULL;
    int n, x; cout << "n = "; cin >> n;      // количество элементов
    create(tr, n);                           // заполнение дерева
    preorder(tr);
    cout << endl;
    cout << leaves(tr);         // вывод суммы листьев
}