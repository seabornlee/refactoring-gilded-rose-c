#include <gtest/gtest.h>
#include <ApprovalTests.hpp>
#include "../src/GildedRose.h"


using namespace ApprovalTests;

int
print_item(Item *item) {
    return printf("%s, %d, %d\n", item->name, item->sellIn, item->quality);
}

TEST(AcceptanceTest3, itsLockedDown) {
    testing::internal::CaptureStdout();

    Item items[9];
    int last = 0;
    int day;
    int index;

    init_item(items + last++, "+5 Dexterity Vest", 3, 20);
    init_item(items + last++, "Aged Brie", 2, 41);
    init_item(items + last++, "Elixir of the Mongoose", 5, 5);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", 0, 80);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", -1, 80);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 10, 49);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 5, 42);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 1, 20);
    init_item(items + last++, "Conjured Mana Cake", 3, 6);

    puts("OMGHAI!");

    for (day = 0; day <= 6; day++) {
        printf("-------- day %d --------\n", day);
        printf("name, sellIn, quality\n");
        for (index = 0; index < last; index++) {
            print_item(items + index);
        }

        printf("\n");

        update_quality(items, last);
    }

    const std::string &out = testing::internal::GetCapturedStdout();
    ApprovalTests::Approvals::verify(out);
}