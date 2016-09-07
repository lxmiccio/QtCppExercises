#include <iostream>

#include "counter.h"

void counter::setValue(int value) {
    this->value = value;
    emit(valueChanged(value));
}

void counter::valueChanged(int value) {
    std::cout << value;
}
