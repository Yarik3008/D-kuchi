#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
template <class Value>
class Dheap
{
protected:
    Value H[50]{0};
	int size = -1;
public:
    Dheap() {}

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return (2 * i) + 1;
    }

    int rightChild(int i)
    {
        return (2 * i) + 2;
    }

    void shiftUp(int i)// ћен€ет местами неправильно закрепленный узел с его родителем в тех порах, 
        //пока это не будет удовлетвор€ть свойству кучи
    {
        while (i > 0 && H[parent(i)] < H[i]) {
            swap(H[parent(i)], H[i]);
            i = parent(i);
        }
    }

    void shiftDown(int i)//мен€ет неправильно закрепленный узел с более крупным дочерним узлом до тех пор, 
        //пока это не будет удовлетвор€ть свойству кучи
    {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l <= size && H[l] > H[maxIndex]) {
            maxIndex = l;
        }

        if (r <= size && H[r] > H[maxIndex]) {
            maxIndex = r;
        }

        if (i != maxIndex) {
            swap(H[i], H[maxIndex]);
            shiftDown(maxIndex);
        }
    }

    void insert(Value p) // ¬ставл€ет новый элемент с приоритетом p
    {
        size++;
        H[size] = p;
        shiftUp(size);
    }

    Value extractMax() // »звлекает элемент с максимальным приоритетом.
    {//Ќо корень дерева напр€мую удалить нельз€.—начала его замен€ют любые листь€, а затем удал€ют
        Value result = H[0];
        H[0] = Value();
        swap(H[0], H[size]);
        size--;
        shiftDown(0);//Ќо это нарушение свойства кучи, поэтому вам придетс€ заменить узел вниз
        return result;
    }

    void changePriority(int i, Value p) // »змен€ет элемент приоритета
    {
        int oldp = H[i];
        H[i] = p;

        if (p > oldp) {
            shiftUp(i);
        }
        else {
            shiftDown(i);
        }
    }

    Value getMax() // ¬озвращает элемент с максимальным приоритетом.
    {
        return H[0];
    }

    void remove(int i) // ”дал€ет элемент, на который указывает номер i.
    {
        i++;
        H[i] = getMax() + 1;//измените его приоритет на значение, превышающее насто€щий максимум
        shiftUp(i); // сдвиньте его вверх
        extractMax(); // извлеките его с помощью
    }

    friend ostream& operator<<(ostream& os, Dheap& heap) {
        for (int j = 0; j <= heap.size; j++) {
            os << heap.H[j] << " ";
        }
        return os << "\n";
    }

    Value& operator[](int index) {
        if (index > size)
            size = index;
        return H[index];
    }
};

