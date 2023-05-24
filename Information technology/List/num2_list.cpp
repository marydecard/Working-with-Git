// №2. Создать двусвязный список, содержащий целые числа. Перенести в начало списка четные числа.

// 9  1 2 3 4 5 6 7 8 9

#include <iostream>
#include <cmath>
using namespace std;

// структура двусвязного списка
struct list{    
    int inf;
    list *next;
    list *prev;
};

// функция вставки элемента в конец списка
void push(list *&h, list *&t, int x){                       
    list *r = new list;                 // создаём новый элемент
    r->inf = x;
    r->next = NULL;                // всегда последний
    if (!h && !t){                 // если список пустой
        r->prev = NULL;            // первый элемент
        h = r;                     // голова
    }
    else{                       // если же список не пуст
        t->next = r;            // r - следующий для хвоста
        r->prev = t;            // хвост - предыдущий для r
    }
    t = r;                      // r теперь хвост
}

// функция печати элементов списка
void print(list *h, list *t){                
    list *p = h;                    // указатель на голову
    while (p){                      // пока не дошли до конца списка
        cout << p->inf << " ";
        p = p->next;                // переход к следующему элементу
    }
}

// функция поиска элемента в списке
list *find ( list *h, list *t, int x){
    list *p = h;                        // указатель на голову
    while (p){                          // пока не дошли до конца списка
        if (p->inf == x) break;          // если нашли элемент, прекращаем цикл
        p = p->next;                    //переход к следующему элементу
    }
    return p;                           //возвращаем указатель
}

// функция вставки элемента перед определенным элементом
void insert_before(list *&h, list *&t, list *r, int y){                     
    list *p = new list;           
    p->inf = y;
    if (r == h){                  
        p->prev = NULL;           
        p->next = r;              
        r->prev = p;
        h = p;                    
    }
    else{                     
        r->prev->next = p; 
        p->prev = r->prev; 
        p->next = r;       
        r->prev = p;
    }
}

// функция удаления элемента из списка
void del_node(list *&h, list *&t, list *r){          // удаляем после r
    if (r == h && r == t)        // единственный элемент списка
        h = t = NULL;
    else if (r == h){            // удаляем голову списка
        h = h->next;             // сдвигаем голову
        h->prev = NULL;
    }
    else if (r == t){            // удаляем хвост списка
        t = t->prev;             // сдвигаем хвост
        t->next = NULL;
    }
    else{                           // удаляем из середины списка
        r->next->prev = r->prev;    // для следующего от r предыдущим становится r->prev
        r->prev->next = r->next;    // для предыдущего от r следующим становится r->next
    }
    delete r;       // удаляем r
}


// функция, ищущая результат
void result(list *&h, list *&t, int n){
    list *p = t;            // указатель на хвост
    int count = 0;      
    while (count < n){          // пока счетчик < размерности списка
        list *k = p->prev;                     // указатель на предыдущий для p элемент
        if (!(p->inf % 2)){                    // если элемент четный
            insert_before(h, t, h, p->inf);    // вставляем его значение перед головой
            del_node(h, t, p);                 // удаляем из изначального места
        }
        count++;            
        p = k;                  // сдвигаем указатель на предыдущий элемент
    }
}

int main(){
    int n, x; cout << "n = "; cin >> n;          // количество элементов
    list *head = NULL, *tail = NULL;             // создание указателей на голову и на хвост

    for (int i = 0; i < n; i++){        // заполнение списка
        cin >> x;
        push(head, tail, x); 
    }
    result(head, tail, n); 
    print(head, tail);                  // печать результата
    return 0;
}