/*Создать стек, содержащий слова. В новый стек записать все слова, оканчивающиеся на заданную букву. Порядок следования чисел в новом стеке должен совпадать с первоначальным. Например, было aaa, fdds, sss, asd, qwe, rty, fes   и заданная буква s.  Cтало  fdds, sss, fes. 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stack{
    string inf;
    stack *next;
};

void push (stack *&h, string X){
    stack *r = new stack;
    r ->inf = X;
    r ->next = h;
    h = r;
}

string pop(stack *& h) {
    string X = h -> inf;
    stack *p = h;
    h = h -> next;
    delete p;
    return X;
}

stack* filterWordsByLastLetter(stack *& h, char letter){
    stack* tmpStack = nullptr;
    stack* resStack = nullptr;

    while(h != nullptr) {
        string w = pop(h);
        push(tmpStack, w);


        if (w.back() == letter) {
            push(resStack, w);
        }
    }

    return resStack;
}

void printStack(stack *& h) {
    stack* tmp = h;
    while(tmp != nullptr){
        cout << tmp -> inf << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

int main() {
    stack* original = nullptr;

    push(original, "aaa");
    push(original, "fdds");
    push(original, "sss");
    push(original, "asd");
    push(original, "qwe");
    push(original, "rty");
    push(original, "fes");

    cout << "Исходный стек: ";
    printStack(original);

    char targetLetter = 's';
    stack* result = filterWordsByLastLetter(original, targetLetter);

    cout << " Слова, оканчивающиеся на '" << targetLetter << "': ";
    printStack(result);

    return 0;
}