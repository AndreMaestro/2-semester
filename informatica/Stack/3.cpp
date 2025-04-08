/*Создать очередь, содержащую целые числа. После всех чисел, равных максимальному числу, вставить последний нечетный элемент. Например, было  2 8 2 1 6 8 8 1 2 2 8 2 1. Стало  2 8 1 2 1 6 8 1 8 1 1 2 2 8 1 2 1 */

#include <iostream>
using namespace std;

struct queue{
    int inf;
    queue *next;
};

void push(queue *&h, queue *&t, int x){
    queue *r = new queue;
    r ->inf = x;
    r->next = NULL;
    if(!h && !t){
        h = t = r;
    }
    else {
        t ->next = r;
        t = r;
    }
}

int pop (queue *&h, queue *&t) {
    queue *r = h;
    int i = h -> inf;
    h = h -> next;
    if(!h){
        t = NULL;
    }
    delete r;
    return i;
}

void printQueue (queue *h){
    queue *current = h;
    while (current) {
        cout << current->inf << " ";
        current = current -> next;
    }
    cout << endl;
}