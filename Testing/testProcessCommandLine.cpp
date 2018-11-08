#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("CorrectProcessing","[commandline]")
{
	std::vector<std::string> args{"./mpagscipher",
		"-i","TESTINPUTFILE.TXT",
		"-o","TESTOUTPUTFILE.TXT",
		"-k", "1234567890",
		"--encrypt"};
	ProgramSettings settings{false,false,"","","",CipherMode::Encrypt};

	REQUIRE( processCommandLine(args, settings)) ;
	REQUIRE( settings.helpRequested == false );
	REQUIRE( settings.versionRequested == false );
	REQUIRE( settings.inputFile == "TESTINPUTFILE.TXT" );
	REQUIRE( settings.outputFile == "TESTOUTPUTFILE.TXT" );
	REQUIRE( settings.cipher_key == "1234567890" );
	REQUIRE( settings.encrypt == CipherMode::Encrypt );

	args[7] = "--decrypt";

	REQUIRE ( processCommandLine(args, settings) );
	REQUIRE( settings.helpRequested == false );
	REQUIRE( settings.versionRequested == false );
	REQUIRE( settings.inputFile == "TESTINPUTFILE.TXT" );
	REQUIRE( settings.outputFile == "TESTOUTPUTFILE.TXT" );
	REQUIRE( settings.cipher_key == "1234567890" );
	REQUIRE( settings.encrypt == CipherMode::Decrypt );

	args.push_back("--help");

	REQUIRE( processCommandLine(args, settings) );
	REQUIRE( settings.helpRequested == true );

	args.back() = "--version";

	REQUIRE( processCommandLine(args, settings) );
	REQUIRE( settings.versionRequested == true );
}
