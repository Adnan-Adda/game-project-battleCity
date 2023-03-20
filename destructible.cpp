#include <algorithm>
#include "destructible.h"

Destructible::Destructible(int strength) :strength_(strength) {
}

int Destructible::getStrength() const {
    return std::max(strength_, 0);
}

bool Destructible::isDead() const {
    return strength_ <= 0;
}

void Destructible::decreaseStrength(int damageSize) {
    strength_ -= damageSize;
}
