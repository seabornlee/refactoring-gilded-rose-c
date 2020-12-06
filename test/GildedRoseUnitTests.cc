#include <gtest/gtest.h>
#include <ApprovalTests.hpp>


using namespace ApprovalTests;

extern "C" {
#include "GildedRose.h"
}

TEST(TestGildedRoseGroup, FirstTest)
{
    Item items[2];
    init_item(items, "Foo", 0, 0);
    update_quality(items, 1);
    ASSERT_STREQ("fixme", items[0].name);
}

void example()
{
    Item items[6];
    int last = 0;

    init_item(items + last++, "+5 Dexterity Vest", 10, 20);
    init_item(items + last++, "Aged Brie", 2, 0);
    init_item(items + last++, "Elixir of the Mongoose", 5, 7);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", 0, 80);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    init_item(items + last++, "Conjured Mana Cake", 3, 6);
    update_quality(items, last);
}
