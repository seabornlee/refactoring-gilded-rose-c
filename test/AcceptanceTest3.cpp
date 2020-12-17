#include <gtest/gtest.h>
#include <ApprovalTests.hpp>
#include <AgedBrie.h>
#include "../src/GildedRose.h"
#include "Item.h"
#include "BackstagePass.h"
#include "Sulfuras.h"


using namespace ApprovalTests;
int
print_item(Item *item) {
    return printf("%s, %d, %d\n", item->name, item->sellIn, item->quality);
}

TEST(AcceptanceTest3, itsLockedDown) {
    testing::internal::CaptureStdout();

    Item *items[9];
    int last = 0;
    int day;
    int index;

    items[last++] = newItem("+5 Dexterity Vest", 10, 20);
//    items[last++] = newItem("Aged Brie", 2, 0);
    items[last++] = (Item *) newAgedBrie(2, 0);
    items[last++] = newItem("Elixir of the Mongoose", 5, 7);
    items[last++] = (Item *) newSulfuras(0, 80);
    items[last++] = (Item *) newSulfuras(-1, 80);
    items[last++] = (Item *) newBackstagePass(15, 20);
    items[last++] = (Item *) newBackstagePass(10, 49);
    items[last++] = (Item *) newBackstagePass(5, 49);

    // this Conjured item doesn't yet work properly
    items[last++] = newItem("Conjured Mana Cake", 3, 6);
//    init_item(items + last++, "Conjured Mana Cake", 3, 6);

    puts("OMGHAI!");

    for (day = 0; day <= 30; day++) {
        printf("-------- day %d --------\n", day);
        printf("name, sellIn, quality\n");
        for (index = 0; index < last; index++) {
            print_item(items[index]);
        }

        printf("\n");

        update_quality(items, last);
    }

    const std::string &out = testing::internal::GetCapturedStdout();
    ApprovalTests::Approvals::verify(out);
}