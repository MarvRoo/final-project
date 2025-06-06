#include "interview.h"
#include "gtest/gtest.h"

TEST(Interview, testGardenerInterview) {
    vector<string> gardenerClues = {
        "Gardener",
        "Gardener arrives during the interviews in a different truck.",
        "Called Angie from the Mechanic shop.",
        "Alibi is his nephew"
    };
    Interview gardener(gardenerClues, 3302);
    EXPECT_EQ(gardener.getName(), "Gardener's Interview");
    EXPECT_NO_THROW(Gardener.print());
}

TEST(Interview, poolBoyInterview) {
    vector<string> poolBoyClues = {
        "Pool boy left before 11 am on a lunch break."
        "Angie was supposed to call us about the gardener"
        "Alibi is Angie"
    };
    Interview poolBoy(poolBoyClues, 3301);
    EXPECT_EQ(poolBoy.getName(), "Pool Boy's Interview");
    EXPECT_NO_THROW(poolBoy.print());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


