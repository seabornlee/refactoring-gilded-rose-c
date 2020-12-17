#ifndef REFACTOR_GILDED_ROSE_C_SULFURAS_H
#define REFACTOR_GILDED_ROSE_C_SULFURAS_H

#include "Item.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _sulfuras {
    Item base;
} Sulfuras;
Sulfuras *newSulfuras(int sellIn, int quality);

static void sulfuras_updateQuality(Item *item);
#ifdef __cplusplus
}
#endif
#endif //REFACTOR_GILDED_ROSE_C_SULFURAS_H
