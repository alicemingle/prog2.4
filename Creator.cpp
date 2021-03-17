#include "Creator.h"

CComplexVector* CreatorVector0::create(size_t size) {
    return new CComplexVector0(size);
}

CComplexVector* CreatorVector1::create(size_t size) {
    return new CComplexVector1(size);
}
