//
// Created by sacha on 01/12/2025.
//

#include "Observable.h"

void Observable::register_observer(Observer *obs) {
    observers_.push_back(obs);
}

void Observable::notify_grid_changed() const {
    for (const auto &obs : observers_) {
        obs->grid_changed();
    }
}
