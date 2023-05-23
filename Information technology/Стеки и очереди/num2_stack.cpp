// №2. Создать стек, содержащий слова. В новый стек записать все слова, оканчивающиеся на заданную букву. Порядок следования слов в новом стеке должен совпадать с первоначальным.

// aaa fdds sss asd qwe rty fes

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;


// описание структуры стека
struct stack{
    string inf;
    stack *next;
};

// функция добавления элемента в стек
void push(stack *&h, string x){
    stack *r = new stack;           // создание нового элемента
    r->inf = x;                     // поле inf (значение) = х
    r->next = h;                    // следующим элементом является h
    h = r;                          // теперь r является головой
}

// функция удаления элемента (и возвращения его значения)
string pop(stack *&h){
    string i = h->inf;             // значение первого элемента
    stack *r = h;               // указатель на голову стека
    h = h->next;                // переносим указатель на следующий элемент
    delete r;                   // удаляем первый элемент
    return i;                   // возвращаем его значение
}

// функция, переписывающая элементы в новый стек в нужном порядке
void reverse(stack *&h){
    stack *head1 = NULL;            // инициализация буферного стека
    while (h)                       // пока стек не пуст
        push(head1, pop(h));        // переписываем из одного стека в другой
    h = head1;                      // переобозначаем указатели
}

// функция, возвращающая результат
stack *result(stack *&h, char letter){
    stack *res = NULL;          // результирующий стек
    string x;      
    while (h){                  // пока стек не пуст
        x = pop(h);             // удаляем первый элемент из head и записываем значение в x
        if (x[x.length() - 1] == letter) push(res, x);      // если последняя буква = заданной, записываем элемент в результирующий стек
    }

    reverse(res);               // переворачиваем результирующий стек
    return res;
}

int main(){
    stack *head = NULL;                 // инициализация стека
    int n; cout << "n = "; cin >> n;    // размерность стека
    char letter; cout << "letter: "; cin >> letter;

    string word;
    for (int i = 0; i < n; i++){        // заполнение стека
        cin >> word;
        push(head, word);
    }

    reverse(head);                      // переворачиваем стек
    stack *res = result(head, letter);  // конечный результат

    while (res)                         // пока стек непустой
        cout << pop(res) << " ";        // вывод результатов на экран
    cout << endl;
    return 0;
}