#include <stdio.h>
#include <stdlib.h>
#include "Sulfuras.h"


Sulfuras *newSulfuras(int sellIn, int quality) {
    Sulfuras *pSulfuras = (Sulfuras *) malloc(sizeof(Sulfuras));
    if (pSulfuras == NULL) {
        return NULL;
    }

    Item *pItem = newItem("Sulfuras, Hand of Ragnaros", sellIn, quality);
    pSulfuras->base = *pItem;

    pSulfuras->base.updateQuality = sulfuras_updateQuality;

    return pSulfuras;
}

void sulfuras_updateQuality(Item *item) {
    increaseQuality(item);
}
