#ifndef REFACTORING_GILDED_ROSE_C_GILDEDROSE_H
#define REFACTORING_GILDED_ROSE_C_GILDEDROSE_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char *name;
    int sellIn;
    int quality;
} Item;

extern Item *init_item(Item *item, const char *name, int sellIn, int quality);

extern void update_quality(Item items[], int size);

#ifdef __cplusplus
}
#endif
#endif //REFACTORING_GILDED_ROSE_C_GILDEDROSE_H
