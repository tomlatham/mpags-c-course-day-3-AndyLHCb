#ifndef CAESAR_CLASS
#define CAESAR_CLASS

#include <vector>
#include <string>
#include <iostream>
#include "CipherMode.hpp"

/**
 * A class to impliment a caesar cypher to a string given a key
 * Both encryption and decryption may be done
 */
class Caesar{
	private:
		///alphabet to be used (by default the one used in english and currently unchangable)
		const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		///alphabet size for use in some of the maths implimentation
		const size_t alphabetSize_ = alphabet_.size();
		///Key to be used
		size_t key_{0};


	public:
		///constructors
		explicit Caesar(const size_t& key);
		explicit Caesar(const std::string& key);

		///setters & getters

		void printAlphabet();

		//Overload == operator
		inline bool operator==(const Caesar& rhs )
		{
			bool keyEquiv{ this->key_ == rhs.key_ };
			bool alphEquiv{ this->alphabet_ == rhs.alphabet_  };
			return keyEquiv and alphEquiv;
		}

		///Member functions

		///Applys the cipher to a string given a direction to encrypt/decrypt
		std::string applyCipher( const std::string& inputText, const CipherMode encrypt ) const;
};


#endif
