#include "BackstagePass.h"
#include <stdio.h>
#include <stdlib.h>


BackstagePass *newBackstagePass(int sellIn, int quality) {
    BackstagePass *pBackstagePass = (BackstagePass *) malloc(sizeof(BackstagePass));
    if (pBackstagePass == NULL) {
        return NULL;
    }

    Item *pItem = newItem("Backstage passes to a TAFKAL80ETC concert", sellIn, quality);
    pBackstagePass->base = *pItem;

    pBackstagePass->base.updateQuality = backstagePass_updateQuality;
    return pBackstagePass;
}

void backstagePass_updateQuality(void *pObj) {
    Item *item = (Item *) pObj;

    increaseQuality(item);

    if (item->sellIn <= 10) {
        increaseQuality(item);
    }

    if (item->sellIn <= 5) {
        increaseQuality(item);
    }
}
