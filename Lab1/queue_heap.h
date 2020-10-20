/**
    Heap realization of priority queue.
    @file queue_heap.h
    @author Volodymyr Martynenko
    @version 1.0
*/
#include "queue.h"
#include <vector>


template <typename T>
class PriorityQueueH {
private:
    vector<Element<T>> data;
public:
    /**
    Looking for element with lower priority and inserting current element before it or pushing it front if current priority is the lowest.
    @return true if priority of element 'a' is bigger than b and vice versa 
    */
    void add(T value, unsigned int priority) {
        Element<T> temp(value, priority);
        data.push_back(temp);
        make_heap(data.begin(), data.end(),
            [](Element<T> a, Element<T> b) {
                return a.priority > b.priority;
            });
    }
    /**
    Takes the first element in the queue.
    @return First element in the queue.
    */
    T peek() {
        T temp = (data[0]).value;
        data.pop_front();
        return temp;
    }
    /**
    Takes second element without deleting it.
    @return second element in the queue
    */
    T next() {
        return data[1].value;
    }
    //prints the queue
    void Print() {
        for (auto c : data)
            cout << c.value << " (" << c.priority << ") ";
        cout << endl;
    }
};