#include "ItemType.h"
#include <string.h>
bool isSulfuras(Item *item) { return strcmp(item->name, "Sulfuras, Hand of Ragnaros") == 0; }

bool isBackstagePass(Item *item) { return strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert") == 0; }

bool isAgedBrie(Item *item) { return strcmp(item->name, "Aged Brie") == 0; }

bool isManaCake(Item *item) {
    return strcmp(item->name, "Conjured Mana Cake") == 0;
}

