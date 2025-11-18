//
// Created by sacha on 17/11/2025.
//

#ifndef TD2_IVUE_H
#define TD2_IVUE_H

#include "../Model/Direction.h"

class IVue {
public:
    virtual ~IVue() = default;

private:
    virtual void move(Direction direction);
    virtual void Display();
};


#endif //TD2_IVUE_H