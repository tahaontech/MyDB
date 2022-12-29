#include <catch2/catch.hpp>
#include "groundupdb.h"

#include <string>

TEST_CASE("Store and retrive a value", "[setKeyValue,getKeyValue]")
{

    SECTION("Basic set and get")
    {
        std::string dbname("myemptydb");
        Database db(GroundUpDB::createEmptyDB(dbname));

        std::string key("simplestring");
        std::string value("Some Highly valuable value");
        db.setKeyValue(key, value);
        REQUIRE(value == db.getKeyValue(key));

        db.destroy();
    }
}