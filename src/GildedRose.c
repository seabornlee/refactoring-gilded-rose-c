// Copyright 2020 Seaborn Lee
#include <stdbool.h>
#include "GildedRose.h"

void updateOneItem(Item *item);

void update_quality(Item **items, int size) {
    for (int i = 0; i < size; i++) {
        updateOneItem(items[i]);
    }
}

void updateOneItem(Item *item) {
    item->updateQuality(item);
    updateSellIn(item);

    bool isExpired = item->sellIn < 0;
    if (isExpired) {
        updateQualityAfterExpired(item);
    }
}
