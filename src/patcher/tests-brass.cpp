// tests-brass.cpp
#include "catch.hpp"
#include "brass.hpp"

TEST_CASE( "getLipPosition", "" ) {
    resetBrassPositions();
    REQUIRE( getLipPosition() == 0 );
    setLipPosition(7, true);
    REQUIRE( getLipPosition() == 7 );
    setLipPosition(4, true);
    REQUIRE( getLipPosition() == 7 );
    setLipPosition(7, false);
    REQUIRE( getLipPosition() == 4 );
}

TEST_CASE( "getFingerPosition", "" ) {
    resetBrassPositions();
    REQUIRE( getFingerPosition() == 0 );
    setFingerPosition(1, true);
    REQUIRE( getFingerPosition() == 2 );
    setFingerPosition(2, true);
    REQUIRE( getFingerPosition() == 2 + 1 );
    setFingerPosition(3, true);
    REQUIRE( getFingerPosition() == 2 + 1 + 3 );
    setFingerPosition(1, false);
    setFingerPosition(2, false);
    setFingerPosition(3, false);
    setFingerPosition(4, true);
    REQUIRE( getFingerPosition() == 5 );
}

TEST_CASE( "getMidiFromBrass", "" ) {
    resetBrassPositions();
    REQUIRE( getMidiFromBrass() == 0 );
    setLipPosition(1, true);
    REQUIRE( getMidiFromBrass() == 24 );
    setFingerPosition(1, true);
    REQUIRE( getMidiFromBrass() == 24 - 2 );
}
