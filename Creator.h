#pragma once
#include <memory>
#include "CComplexVector.h"
#include "CComplexVector0.h"
#include "CComplexVector1.h"

class Creator {
public:
    virtual CComplexVector* create(size_t size) = 0;
};

class CreatorVector0 : public Creator {
public:
    CComplexVector* create(size_t size) override;
};

class CreatorVector1 : public Creator {
public:
    CComplexVector* create(size_t size) override;
};