// tests-strings.cpp
#include "catch.hpp"
#include "strings.hpp"

TEST_CASE( "getMidiFromKey", "char key" ) {
    REQUIRE( getMidiFromKey('z') == (60 - 12 * 2 + 4) );
    REQUIRE( getMidiFromKey('a') == (60 - 12 * 2 + 4 + 5) );
    REQUIRE( getMidiFromKey('q') == (60 - 12 * 1 + 2) );
    REQUIRE( getMidiFromKey('1') == (60 - 12 * 1 + 2 + 5) );
}
