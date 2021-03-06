#include "series2.h"
#include <iostream>

std::string encodeVigenere(std::string plaintext, std::string secret)
{
	// Uppercase all letters in both words
	for(int i = 0; i < plaintext.length(); i++)
	{
		plaintext[i] = toupper(plaintext[i]);
	}
	for(int i = 0; i < secret.length(); i++)
	{
		secret[i] = toupper(secret[i]);
	}

	std::string encodedString = "";

	// Go through the plaintext and encode letter by letter
	for(int i = 0; i < plaintext.length(); i++)
	{
		// If its a space append a space else encode the letter
		if(plaintext[i] == ' ')
		{
			encodedString += ' ';
		}
		else
		{
			encodedString += ((plaintext[i] + secret[i % secret.length()]) % 26) + 'A';
		}
	}

	return encodedString;
}

int* countLetterFrequency(std::string text, int* letterFrequency)
{
	for(int i = 0; i < 26; ++i)
	{
		letterFrequency[i] = 0;
	}

	for(int i = 0; i < text.length(); ++i)
	{
		if(isalpha(text[i]) == true)
		{
			letterFrequency[toupper(text[i]) - 65]++;
		}
	}

	return letterFrequency;
}

void outputLetterFrequencies(int* letterFrequency, bool onlyOutputPresentOnes)
{
	for(int i = 0; i < 26; ++i)
	{
		if(onlyOutputPresentOnes)
		{
			if(letterFrequency[i] > 0)
			{
				std::cout << char('A' + i) << ": " << letterFrequency[i] << std::endl;
			}
		}
		else
		{
			std::cout << char('A' + i) << ": " << letterFrequency[i] << std::endl;
		}

	}
}

int main()
{
	std::cout << "--- Series 2 ---" << std::endl;

	std::string plaintext = "ANGEWANDTEINFORMATIK";
	std::cout << "Klartext: " << plaintext << std::endl;
	std::string key = "KEY";
	std::cout << "Schluessel: " << key << std::endl;

	std::string encodedText = encodeVigenere(plaintext, key);
	std::cout << "Geheimtext: " << encodedText << std::endl;

	std::cout << "Frequency Check:" << std::endl;

	int* frequencyArray = new int[26];
	frequencyArray = countLetterFrequency("JA MOIN WAS GEHT", frequencyArray);
	outputLetterFrequencies(frequencyArray, true);

	std::cout << "--- Series 2 END ---" << std::endl;

	return 0;
}