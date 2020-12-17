#include <stdbool.h>
#include <string.h>
#include "GildedRose.h"

bool isAgedBrie(const Item *item) { return (strcmp(item->name, "Aged Brie") == 0); }

bool isSulfuras(const Item *item) { return strcmp(item->name, "Sulfuras, Hand of Ragnaros") == 0; }

bool isBackstagePass(const Item *item) {
    return (strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert") == 0);
}