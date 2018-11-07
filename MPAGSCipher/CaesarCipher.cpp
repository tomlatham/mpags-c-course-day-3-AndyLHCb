#include "CaesarCipher.hpp"

Caesar::Caesar(const size_t& key): key_{key}
{
}

Caesar::Caesar(const std::string& key)
{
    for ( const auto& elem : key ) {
	if ( ! std::isdigit(elem) ) {
	    std::cerr 
		<<"[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
		<< "       the supplied key (" << key << ") could not be successfully converted \n "
		<< "       a default value of 1 was taken." << std::endl;
	    key_ = 1;
	    return;
	}	
    }
    key_ =  key.empty() ? 0 : std::stoul(key);
}

std::string Caesar::applyCipher(  const std::string& inputText, const CipherMode encrypt )
{
  // Create the output string
  std::string outputText {};

  // Make sure that the key is in the range 0 - 25
  const size_t truncatedKey { key_ % alphabetSize_ };

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

	  // For each character in the input text, find the corresponding position in
	  // the alphabet by using an indexed loop over the alphabet container
	  for ( size_t i{0}; i < alphabetSize_; ++i ) {

		  if ( origChar == alphabet_[i] ) {

			  // Apply the appropriate shift (depending on whether we're encrypting
			  // or decrypting) and determine the new character
			  // Can then break out of the loop over the alphabet
			  switch ( encrypt ) {
				  case CipherMode::encrypt:
					  processedChar = alphabet_[ (i + truncatedKey) % alphabetSize_ ];
					  break;
				  case CipherMode::decrypt:
					  processedChar = alphabet_[ (i + alphabetSize_ - truncatedKey) % alphabetSize_ ];
					  break;
			  }

			  // Add the new character to the output text
			  outputText += processedChar;
		  }
	  }
  }

  return outputText;

}

void Caesar::printAlphabet()
{
	for( char i : alphabet_ )
	{
		std::cout << i;
	}
	std::cout << std::endl;
}

