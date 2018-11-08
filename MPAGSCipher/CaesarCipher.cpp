#include "CaesarCipher.hpp"

Caesar::Caesar(const size_t& key): key_{key % alphabetSize_}
{
}

Caesar::Caesar(const std::string& key) : key_{0}
{
    if ( key.empty() ) {
	return;
    }

    for ( const auto& elem : key ) {
	if ( ! std::isdigit(elem) ) {
	    std::cerr 
		<<"[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
		<< "       the supplied key (" << key << ") could not be successfully converted \n "
		<< "       a default value of 0 was taken." << std::endl;
	    return;
	}	
    }
    key_ =  std::stoul(key) % alphabetSize_;
}

std::string Caesar::applyCipher(  const std::string& inputText, const CipherMode encrypt ) const
{
  // Create the output string
  std::string outputText {};

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
				  case CipherMode::Encrypt:
					  processedChar = alphabet_[ (i + key_) % alphabetSize_ ];
					  break;
				  case CipherMode::Decrypt:
					  processedChar = alphabet_[ (i + alphabetSize_ - key_) % alphabetSize_ ];
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

