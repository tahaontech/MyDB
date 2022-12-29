#include "tests.h"

#include <filesystem>
#include <string>

#include "groundupdb.h"

namespace fs = std::filesystem;

TEST_CASE( "Create new Empty database", "[createEmptyDB]" ) {
    
    SECTION("Default settings") {
        std::string dbname("myemptydb");
        Database db(GroundUpDB::createEmptyDB(dbname));

        REQUIRE(fs::is_directory(fs::status(db.getDirectory())));

        const auto& p = fs::directory_iterator(db.getDirectory());
        REQUIRE(p == end(p));

        db.destroy();
        REQUIRE(!fs::exists(fs::status(db.getDirectory())));
    }
}


TEST_CASE("Load existing database","[loadDB]") {

    SECTION("Default settings") {
        std::string dbname("myemptydb");
        Database db(GroundUpDB::createEmptyDB(dbname));

        Database db2(GroundUpDB::loadDB(dbname));

        
        REQUIRE(fs::is_directory(fs::status(db2.getDirectory())));
        
        auto p = fs::directory_iterator(db.getDirectory());
        REQUIRE(p == end(p)); 

        db2.destroy();
        REQUIRE(!fs::exists(fs::status(db2.getDirectory())));
    }
}