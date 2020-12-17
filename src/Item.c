#include <string.h>
#include "Item.h"
#include "ItemType.h"

Item *
init_item(Item *item, const char *name, int sellIn, int quality) {
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);

    item->updateQuality = item_updateQuality;

    return item;
}

void updateQualityAfterExpired(Item *item) {
    if (isAgedBrie(item)) {
        increaseQuality(item);
        return;
    }

    if (isBackstagePass(item)) {
        item->quality = 0;
        return;
    }
    if (!isSulfuras(item)) {
        decreaseQuality(item);
    }
}

void item_updateQuality(Item *item) {
    if (!isAgedBrie(item) && !isBackstagePass(item) && !isSulfuras(item)) {
        decreaseQuality(item);
        return;
    }

    increaseQuality(item);
}

void updateSellIn(Item *item) {
    if (isSulfuras(item)) return;
    item->sellIn = item->sellIn - 1;
}

void increaseQuality(Item *item) {
    if (item->quality < 50) {
        item->quality = item->quality + 1;
    }
}

void decreaseQuality(Item *item) {
    if (item->quality > 0) {
        item->quality = item->quality - 1;
    }
}