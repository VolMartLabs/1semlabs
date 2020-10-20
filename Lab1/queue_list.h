/**
    List realization of priority queue.
    @file queue_list.h
    @author Volodymyr Martynenko
    @version 1.0
*/
#include "queue.h"
#include <list>


template <typename T>
class PriorityQueueL {
private:
    list<Element<T>> data;
public:
    /**
    Looking for element with lower priority and inserting current element before it or pushing it front if current priority is the lowest.
    @return true if priority of element 'a' is bigger than b and vice versa
    */
    void add(T value, unsigned int priority) {
        Element<T> temp(value, priority);
        auto it = data.begin();
        while (it != data.end() && (*it).priority <= priority)
            it++;
        if (it != data.begin())
            data.insert(it, temp);
        else
            data.push_front(temp);
    }
    /**
    Takes the first element in the queue.
    @return First element in the queue.
    */
    T peek() {
        T temp = (*data.begin()).value;
        data.pop_front();
        return temp;
    }
    /**
    Takes second element without deleting it.
    @return second element in the queue
    */
    T next() {
        return (*next(data.begin())).value;
    }
    //prints the queue
    void Print() {
        for (auto c : data)
            cout << c.value << " (" << c.priority << ") ";
        cout << endl;
    }
};
