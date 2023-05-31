// №1. Дано дерево. Определить количество узлов, имеющих только правого потомка.

#include <iostream>
using namespace std;


// структура дерева
struct tree{ 
    int inf;
    tree *left;
    tree *right;
    tree *parent;
};

// создание нового узла
tree *node(int x){ 
    tree *n = new tree;
    n->inf = x;
    n->parent = NULL;
    n->right = NULL;
    n->left = NULL;
    return n;
}

// симметричный обход (Л-К-П)
void inorder(tree *tr){ 
    if (tr){
        inorder(tr->left);         // левое
        cout << tr->inf << " ";    // корень
        inorder(tr->right);        // правое
    }
}

// вставка элемента
void insert(tree *&tr, int x){ 
    tree *n = node(x);
    if (!tr)
        tr = n;         // если дерево пустое - значит это корень
    else{
        tree *y = tr;
        while (y){                      // ищем куда вставлять
            if (n->inf > y->inf)        // правая ветка
                if (y->right)
                    y = y->right;
                else{
                    n->parent = y;      // узел становится правым ребенком
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf)   // левая ветка
                if (y->left)
                    y = y->left;
                else{
                    n->parent = y;      // узел становится левым ребенком
                    y->left = n;
                    break;
                }
        }
    }
}

// функция подсчета количества узлов, имеющих только правого потомка
int descendants(tree *&tr){
    int count = 0;
    if (!tr) return 0;                                              // если дерево пустое
    if (!tr->left && tr->right) count = 1;                          // если левого потомка нет, а правый есть
    return count + descendants(tr->right) + descendants(tr->left);  // рекурсивно считаем для каждого поддерева
}


// 12   7 5 3 15 1 9 4 2 11 8 19 20

int main(){
    int n; cout << "n = "; cin >> n;     // количество элементов дерева
    int x;
    tree *tr = NULL;

    for (int i = 0; i < n; i++){  // заполнение дерева
        cout << i << " = ";
        cin >> x;                 // ввод текущего элемента
        insert(tr, x);            // вставка этого элемента на свое место в дереве
    }
    inorder(tr);
    cout << endl;
    cout << descendants(tr);
}