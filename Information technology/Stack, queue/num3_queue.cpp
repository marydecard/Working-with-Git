// №3. Создать очередь, содержащую целые числа. Удалить первый и последний четный элемент. 

// 12 8 2 1 6 8 8 1 2 2 8 2 1
// 15 1 8 8 2 3 9 0 1 4 5 0 2 0 5 3
#include<iostream>
#include <cmath>
using namespace std;


// описание структуры очереди
struct queue{
    int inf;
    queue *next;
};

// функция добавления элемента в очередь
void push(queue *&h, queue *&t, int x){
    queue *r = new queue;
    r->inf = x;
    r->next = NULL;         // всегда последний
    if (!h && !t){          // если очередь пуста, то это и голова, и хвост
        h = t = r;
    }
    else{                   // если очередь не пуста, то 
        t->next = r;        // r - следующий для хвоста
        t = r;              // теперь r - хвост
    }
}

// функция удаления элемента (и возвращения его значения)
int pop(queue*& h, queue *&t){ 
    queue *r = h;                   // создаем указатель на голову
    int i = h->inf;                 // сохраняем значение головы
    h = h->next;                    // сдвигаем указатель на следующий элемент
    if (!h)                    // если удаляем последний элемент из очереди
        t = NULL;
    delete r;                  // удаляем первый элемент
    return i;
}

// функция, возвращающая результат
void result(queue*&h, queue *&t){
    queue *h_res = NULL, *t_res = NULL;     // результирующая очередь
    queue *head1 = NULL, *tail1 = NULL;       // вспомогательная очередь
    int x, count = 0;
    
    while (h && t){
        x = pop(h, t);
        if (!(x % 2)) count++;         // если элемент четный, добавляем к счетчику +1
        push(head1, tail1, x);
    }
    h = head1, t = tail1;                // переобозначаем указатели


    bool flag = true;
    int count_new = 0;
    
    while (h && t){
        x = pop(h, t);
        if (!(x % 2)){                  // если встретили четный элемент, добавляем к новому счетчику +1
            count_new++;
            if (!(flag) && count_new != count){     // если встреченный четный элемент - не первый и не последний, то 
                                                    // добавляем его в результирующую очередь
                push(h_res, t_res, x);
            }
            flag = false;
        }
        else                            // если встретили нечетный элемент, сразу его добавляем
            push(h_res, t_res, x);
    }
    h = h_res, t = t_res;               // переобозначаем указатели
}

int main(){
    int n; cout << "n = "; cin >> n;            // размерность очереди
    queue* head = NULL, *tail = NULL;           // инициализация очереди
    int x;
    for (int i = 0; i < n; i++) {               // заполнение очереди 
        cin >> x;
        push(head, tail, x);
    }

    result(head, tail); 

    while (head && tail)                        // пока очередь не пуста      
        cout << pop(head, tail) << " ";         // вывод результатов на экран
    cout << endl;
}