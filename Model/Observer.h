//
// Created by sacha on 01/12/2025.
//

#ifndef TD2_OBSERVER_H
#define TD2_OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;

    virtual void grid_changed() = 0;
};

#endif //TD2_OBSERVER_H