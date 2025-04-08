/*Создать стек, содержащий слова. В новый стек записать все слова, оканчивающиеся на заданную букву. Порядок следования чисел в новом стеке должен совпадать с первоначальным. Например, было aaa, fdds, sss, asd, qwe, rty, fes   и заданная буква s.  Cтало  fdds, sss, fes. 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stack{
    char inf;
    stack *next;
};

void push (stack *&h, char X){
    stack *r = new stack;
    r ->inf = X;
    r ->next = h;
    h = r;
}

char pop(stack *& h) {
    char X = h -> inf;
    stack *p = h;
    h = h -> next;
    delete p;
    return X;
}

void reverse (stack *& h) {
    stack *head1 = NULL;
    while(h){
        push(head1, pop(h));
    }
    h = head1;
}