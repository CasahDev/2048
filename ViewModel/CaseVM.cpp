//
// Created by sacha on 17/11/2025.
//

#include "CaseVM.h"

CaseVM::CaseVM(Case c) : c_(c) {
}

long CaseVM::get_value() {
    return c_.get_value();
}
