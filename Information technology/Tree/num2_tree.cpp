// №2. Дано дерево. Определить степень узла Х.

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

// функция поиска элемента
tree *find(tree *tr, int x){   
    if (!tr || x == tr->inf)           // нашли или дошли до конца ветки
        return tr;
    if (x < tr->inf)
        return find(tr->left, x);      // ищем по левой ветке
    else
        return find(tr->right, x);     // ищем по правой ветке
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

// функция подсчета степени узла
int descendants(tree *&tr){
    if (tr->left == NULL && tr->right != NULL || tr->left != NULL && tr->right == NULL)  // из узла выходит одна дуга
        return 1;
    if (tr->left != NULL && tr->right != NULL)      // из узла выходит две дуги
        return 2;
    return 0;                                       // из узла не выходит дуг
}

// 11   7 5 3 15 1 9 4 2 11 8 19

int main(){
    int n; cout << "n = "; cin >> n;     // количество элементов дерева
    int x, value;
    bool flag = false;
    cout << "node value: "; cin >> value;
    tree *tr = NULL;

    for (int i = 0; i < n; i++){  // заполнение дерева
        cout << i << " = ";
        cin >> x;                 // ввод текущего элемента
        insert(tr, x);            // вставка этого элемента на свое место в дереве
    }
    
    cout << endl;
    tree *tr2 = find(tr, value);
    cout << descendants(tr2);
}