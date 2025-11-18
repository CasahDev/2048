//
// Created by sacha on 17/11/2025.
//

#include "CaseVM.h"

CaseVM::CaseVM(const Case c) : c_(c) {
}

long CaseVM::get_value() const {
    return c_.get_value();
}
