#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("CorrectProcessing","[alphanumeric]")
{
	std::vector<std::string> args{"./mpagscipher",
		"-i","TESTINPUTFILE.TXT",
		"-o","TESTOUTPUTFILE.TXT",
		"-k", "1234567890",
		"--encrypt"};
	ProgramSettings settings{false,false,"","","",CipherMode::encrypt};

	REQUIRE( processCommandLine(args, settings)) ;

	args[7] = "--decrypt";

	REQUIRE ( processCommandLine(args, settings) );

	args.push_back("--help");

	REQUIRE( processCommandLine(args, settings) );

	args.push_back("--version");

	REQUIRE( processCommandLine(args, settings) );
}
