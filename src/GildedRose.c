// Copyright 2020 Seaborn Lee
#include <string.h>
#include <stdbool.h>
#include "GildedRose.h"
#include "ItemType.h"

void passOneDay(Item *item);

void updateQuality(Item *item);

void updateSellIn(Item *item);

void updateQualityAfterExpired(Item *item);

void increaseQuality(Item *item);

void decreaseQuality(Item *item);

Item *
init_item(Item *item, const char *name, int sellIn, int quality) {
    item->name = strdup(name);

    if (isSulfuras(item)) {
        item->sellIn = 0;
        item->quality = 80;
    } else {
        if (isAgedBrie(item)) {
            item->sellIn = 0;
        } else {
            item->sellIn = sellIn;
        }
        item->quality = quality;
    }

    return item;
}

void update_quality(Item items[], int size) {
    for (int i = 0; i < size; i++) {
        passOneDay(&items[i]);
    }
}

void passOneDay(Item *item) {
    updateQuality(item);
    updateSellIn(item);

    bool isExpired = item->sellIn < 0;
    if (isExpired) {
        updateQualityAfterExpired(item);
    }
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

void increaseQuality(Item *item) {
    if (item->quality < 50) {
        item->quality = item->quality + 1;
    }
}

void updateSellIn(Item *item) {
    if (isSulfuras(item) || isAgedBrie(item)) return;
    item->sellIn = item->sellIn - 1;
}

void updateQuality(Item *item) {
    if (isAgedBrie(item) || isBackstagePass(item) || isSulfuras(item)) {
        increaseQuality(item);

        if (isBackstagePass(item)) {
            if (item->sellIn < 11) {
                increaseQuality(item);
            }

            if (item->sellIn < 6) {
                increaseQuality(item);
            }
        }
        return;
    }

    decreaseQuality(item);

    if (isManaCake(item)) {
        decreaseQuality(item);
    }
}

void decreaseQuality(Item *item) {
    if (item->quality > 0) {
        item->quality = item->quality - 1;
    }
}