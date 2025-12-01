//
// Created by sacha on 01/12/2025.
//

#ifndef TD2_OBSERVABLE_H
#define TD2_OBSERVABLE_H
#include <memory>
#include <vector>

#include "Observer.h"


class Observable {
    std::vector<Observer *> observers_;
public:
    Observable() = default;
    void register_observer(Observer *obs);
    void notify_grid_changed() const;
};


#endif //TD2_OBSERVABLE_H