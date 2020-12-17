#ifndef REFACTOR_GILDED_ROSE_C_AGEDBRIE_H
#define REFACTOR_GILDED_ROSE_C_AGEDBRIE_H

#include "Item.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _aged_brie {
    Item base;
} AgedBrie;

AgedBrie *newAgedBrie(int sellIn, int quality);

static void agedBrie_updateQuality(void *pObj);

#ifdef __cplusplus
}
#endif
#endif //REFACTOR_GILDED_ROSE_C_AGEDBRIE_H
