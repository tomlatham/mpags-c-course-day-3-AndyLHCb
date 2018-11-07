#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Addition Works", "[math]") {
	REQUIRE( 1+1 == 2);
}

//Testing a Fail case to see how it looks
/*
TEST_CASE("Addition Breaks", "[math]") {
	REQUIRE( 1+1 == 1);
}
*/
