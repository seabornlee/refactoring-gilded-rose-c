#ifndef REFACTOR_GILDED_ROSE_C_ITEM_H
#define REFACTOR_GILDED_ROSE_C_ITEM_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _item Item;

struct _item {
    char *name;
    int sellIn;
    int quality;

    void (* updateQuality)(Item *item);
};


extern Item *init_item(Item *item, const char *name, int sellIn, int quality);
Item *newItem(const char *name, int sellIn, int quality);
void decreaseQuality(Item *item);

void increaseQuality(Item *item);

void updateSellIn(Item *item);

void item_updateQuality(Item *item);

void updateQualityAfterExpired(Item *item);

#ifdef __cplusplus
}

Item *newItem(const char *name, int sellIn, int quality) {
    Item *pItem = (Item *) malloc(sizeof(Item));
    if (pItem == NULL) {
        return NULL;
    }

    pItem->name = strdup(name);
    pItem->sellIn = sellIn;
    pItem->quality = quality;

    pItem->updateQuality= item_updateQuality;

    return pItem;
}

#endif
#endif //REFACTOR_GILDED_ROSE_C_ITEM_H
