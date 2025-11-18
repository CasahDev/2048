//
// Created by sacha on 17/11/2025.
//

#ifndef TD2_CASEVM_H
#define TD2_CASEVM_H
#include "../Model/Case.h"


class CaseVM {
    Case c_;

public:
    explicit CaseVM(Case c);
    long get_value() const;
};


#endif //TD2_CASEVM_H