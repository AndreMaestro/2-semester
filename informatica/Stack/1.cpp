/*Создать стек, содержащий слова. В новый стек записать все слова, оканчивающиеся на заданную букву. Порядок следования чисел в новом стеке должен совпадать с первоначальным. Например, было aaa, fdds, sss, asd, qwe, rty, fes   и заданная буква s.  Cтало  fdds, sss, fes. 
*/

#include <iostream>
#include <string>
using namespace std;

struct stack{
    int inf;
    stack *next;
};

void push (stack *&h, int x){
    stack *r = new stack;
    r ->inf = x;
    r ->next = h;
    h =r;
}
