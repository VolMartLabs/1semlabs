/**
    Calculates sum probabilities and expected value of DiceSet.
    @file dice_set.cpp
    @author Volodymyr Martynenko
    @version 1.0
*/

#include "dice_set.h"



//Gets the elements of DiceSet
DiceSet::DiceSet(std::vector<Dice> vec) {
    elements = vec;
}

/**
    Calculates minimal sum dice set.
    @return minimal sum dice set.
*/
int DiceSet::min_sum() {
    return elements.size();
}

/**
    Calculates max sum dice set.
    @return max sum dice set.
*/
int DiceSet::max_sum() {
    int res = 0;
    for (auto& e : elements)
        res += e.face_number;
    return res;
}

/**
    Calculates sum probabilities of two dice sets.
    @return Sum probabilities of two dice sets.
*/
std::vector<double> DiceSet::sum_probabilities() { //result[i] is a probability for value (min_sum() + i);
    if (elements.empty()) return {};
    int min = min_sum();
    int max = max_sum();
    int curr_size = 0;

    std::vector<double> sub_res, tmp, res;
    for (int i = 0; i < max; i++) {
        res.emplace_back(0);
    }
    tmp = sub_res = res;

    curr_size = elements[0].face_number;
    for (int i = 0; i < elements[0].face_number; i++)
        tmp[i] = elements[0].probability[i];

    for (unsigned int i = 1; i < elements.size(); i++) {
        sub_res = res;
        for (int j = 0; j < elements[i].face_number; j++) {
            for (int k = 0; k < curr_size; k++) {
                sub_res[j + k + 1] += elements[i].probability[j] * tmp[k];
            }
        }
        curr_size += elements[i].face_number;
        tmp = sub_res;
    }

    res.clear();
    for (int i = min - 1; i < max; i++) {
        res.emplace_back(sub_res[i]);
    }

    return res;
}

//Prints the sum probabilities of two dice sets.
void DiceSet::print_sum_probabilities() {
    std::vector<double> tmp = sum_probabilities();
    for (int i = 0; i <= max_sum() - min_sum(); i++) {
        std::cout << i + min_sum() << ":  " << tmp[i] << std::endl;
    }
};

/**
    Calculates expected value of dice set.
    @return expected value of dice set
*/
double DiceSet::expected_value() {
    double res = 0;
    std::vector<double> tmp = sum_probabilities();
    int i = min_sum();
    for (auto& e : tmp) {
        res += e * (i++);
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, DiceSet& obj) {
    for (auto& e : obj.elements) os << e << std::endl;
    return os;
}

bool operator<(DiceSet& obj_l, DiceSet& obj_r) {
    return obj_l.expected_value() < obj_r.expected_value();
}

bool operator>(DiceSet& obj_l, DiceSet& obj_r) {
    return obj_r < obj_l;
}

bool operator<=(DiceSet& obj_l, DiceSet& obj_r) {
    return !(obj_l > obj_r);
}

bool operator>=(DiceSet& obj_l, DiceSet& obj_r) {
    return !(obj_l < obj_r);
}

bool operator==(DiceSet& obj_l, DiceSet& obj_r) {
    return !(obj_l < obj_r) && !(obj_l > obj_r);
}

bool operator!=(DiceSet& obj_l, DiceSet& obj_r) {
    return !(obj_l == obj_r);
}