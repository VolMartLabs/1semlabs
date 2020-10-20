#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
/**
    Contains element class for queues.
    @file queue.h
    @author Volodymyr Martynenko
    @version 1.0
*/

template <typename T>
class Element {
public:
    T value;
    unsigned int priority = 0;
    Element(T val, unsigned int p) {
        value = val;
        priority = p;
    }
};