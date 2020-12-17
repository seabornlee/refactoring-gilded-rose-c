#ifndef REFACTOR_GILDED_ROSE_C_BACKSTAGEPASS_H
#define REFACTOR_GILDED_ROSE_C_BACKSTAGEPASS_H
#include "Item.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _BackstagePass {
    Item base;
} BackstagePass;

BackstagePass *newBackstagePass(int sellIn, int quality);

static void backstagePass_updateQuality(void *pObj);

#ifdef __cplusplus
}
#endif
#endif //REFACTOR_GILDED_ROSE_C_BACKSTAGEPASS_H
