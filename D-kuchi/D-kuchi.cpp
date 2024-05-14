#include "D-heap.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Dheap<int> h;
    h.insert(9);
    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    h.insert(3);
    h.insert(2);
    h.insert(1);

    cout << "Очередь с приоритетами: " << h;

    cout << "Узел с максимальным приоритетом: " << h.extractMax() << "\n";

    cout << "Очередь после извлечения максимума: " << h;

    h.changePriority(0, 15);
    cout << "Очередь после изменения приоритета: " << h;

    h.remove(3);
    cout << "Очередь после удаления элемента: " << h;
    return 0;
}