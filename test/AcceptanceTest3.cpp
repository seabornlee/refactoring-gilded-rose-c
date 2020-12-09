#include <gtest/gtest.h>
#include <ApprovalTests.hpp>
#include "../src/GildedRose.h"


using namespace ApprovalTests;

TEST(AcceptanceTest3, itsLockedDown) {
    testing::internal::CaptureStdout();

    // add your test code here

    const std::string &out = testing::internal::GetCapturedStdout();
    ApprovalTests::Approvals::verify(out);
}