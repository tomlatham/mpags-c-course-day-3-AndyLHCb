#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Correct Cipher Function","[cipher]")
{
	Caesar testcipher{1};
	const std::string alphabet[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};


	for(int i{0}; i<26; ++i)
	{
		REQUIRE( testcipher.applyCipher(alphabet[i],CipherMode::Encrypt) == alphabet[(i+1)%26] );

		REQUIRE( testcipher.applyCipher(alphabet[i],CipherMode::Decrypt) == alphabet[(i+25)%26] );
	}
}

TEST_CASE("String initialisers allowed","[cipher]"){
	Caesar numeric{0};
	Caesar string{"0"};

	REQUIRE( string == numeric );
}
