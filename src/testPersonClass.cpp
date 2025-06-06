#include "person.h"
#include "gtest/gtest.h"
using namespace std;

TEST(PersonTest, AngieDetails){
    string name = "Angie";
    string bloodType = "A-";
    string personalItem = "Hairbrush";
    bool isDead = true;
    bool hasAutopsy = true;
    string description = "The house sitter for the Lou family while they vacationed in Barbados. A close friend of Ally.";

    Person angie(name, bloodType, personalItem, isDead, hasAutopsy, description);

    EXPECT_EQ(name, angie.getPersonName());
    EXPECT_EQ(description, angie.grabDescription());
}

TEST(PersonTest, JacobDetails){
    string name = "Jacob";
    string bloodType = "B+";
    string personalItem = "Gun";
    bool isDead = false;
    bool hasAutopsy = false;
    string description = "The only boy in the Lou family and just returned from Barbados. He is 6'2 and always looks nervous.";

    Person jacob(name, bloodType, personalItem, isDead, hasAutopsy, description);

    EXPECT_EQ(name, jacob.getPersonName());
    EXPECT_EQ(description, jacob.grabDescription());
}

TEST(PersonTest, AllyDetails){
    string name = "Ally";
    string bloodType = "A+";
    string personalItem = "Phone";
    bool isDead = false;
    bool hasAutopsy = false;
    string description = "Just returned from Barbados. She has long brown hair and is 5'3. She is a smart, independent person.";

    Person ally(name, bloodType, personalItem, isDead, hasAutopsy, description);

    EXPECT_EQ(name, ally.getPersonName());
    EXPECT_EQ(description, ally.grabDescription());
}