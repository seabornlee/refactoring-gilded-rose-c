#include <stdlib.h>
#include "AgedBrie.h"

AgedBrie *newAgedBrie(int sellIn, int quality) {
    Item *pItem = newItem("Aged Brie", sellIn, quality);

    AgedBrie *pAgedBrie = (AgedBrie *) malloc(sizeof(AgedBrie));
    if (pAgedBrie == NULL) {
        // printf
        // deleteItem(super)
        return NULL;
    }

    pAgedBrie->base = *pItem;
    pAgedBrie->base.updateQuality = agedBrie_updateQuality;

    return pAgedBrie;
}

void agedBrie_updateQuality(void *pObj) {
    increaseQuality(pObj);
}
