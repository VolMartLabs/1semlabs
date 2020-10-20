/**
    Tests to ensure the work of the lab
    @file main.cpp
    @author Volodymyr Martynenko
    @version 1.0
*/

#include "dice.h"
#include "dice_set.h"
#include "queue_heap.h"
#include "queue_list.h"
#include "queue.h"

int main()
{
    DiceSet set1({ {2, {0.3, 0.7}},
                  {4, {0.2, 0.3, 0.3, 0.4}},
                  {2, {0.1, 0.9}} });
    DiceSet set2({ {2, {0.9, 0.1}},
                  {4, {0.9, 0.3, 0.1, 0.1}},
                  {2, {0.9, 0.2}},
                  {4, {0.9, 0.2, 0.5, 0.2}} });
    set1.print_sum_probabilities();
    set2.print_sum_probabilities();
    std::cout << "expected value 1: " << set1.expected_value() << std::endl;
    std::cout << "expected value 2: " << set2.expected_value() << std::endl;
    std::cout << set1 << std::endl << set2;
    std::cout << (set1 < set2);
    return 0;
}