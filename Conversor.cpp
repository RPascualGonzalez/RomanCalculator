#include "Conversor.h"
#include <string>

using namespace std;

namespace NSP_Conversor {
	Conversor::Conversor()
	{
		hexadecimalValues[0] = '0';
		hexadecimalValues[1] = '1';
		hexadecimalValues[2] = '2';
		hexadecimalValues[3] = '3';
		hexadecimalValues[4] = '4';
		hexadecimalValues[5] = '5';
		hexadecimalValues[6] = '6';
		hexadecimalValues[7] = '7';
		hexadecimalValues[8] = '8';
		hexadecimalValues[9] = '9';
		hexadecimalValues[10] = 'A';
		hexadecimalValues[11] = 'B';
		hexadecimalValues[12] = 'C';
		hexadecimalValues[13] = 'D';
		hexadecimalValues[14] = 'E';
		hexadecimalValues[15] = 'F';

		romanNumbersFactor1[0] = 'I';	// 1
		romanNumbersFactor1[1] = 'X';	// 10
		romanNumbersFactor1[2] = 'C';	// 100
		romanNumbersFactor1[3] = 'M';	// 1K
		romanNumbersFactor1[4] = 'x';	// 10K
		romanNumbersFactor1[5] = 'c';	// 100K
		romanNumbersFactor1[6] = 'm';	// 1M

		romanNumbersFactor5[0] = 'V';	// 5
		romanNumbersFactor5[1] = 'L';	// 50
		romanNumbersFactor5[2] = 'D';	// 500
		romanNumbersFactor5[3] = 'v';	// 5K
		romanNumbersFactor5[4] = 'l';	// 50K
		romanNumbersFactor5[5] = 'd';	// 500K

		romanNumbersEquivalenceFactor1[0] =  1;	
		romanNumbersEquivalenceFactor1[1] =  10;	
		romanNumbersEquivalenceFactor1[2] =  100;	
		romanNumbersEquivalenceFactor1[3] =  1000;	
		romanNumbersEquivalenceFactor1[4] =  10000;	
		romanNumbersEquivalenceFactor1[5] =  100000;	
		romanNumbersEquivalenceFactor1[6] =  1000000;

		romanNumbersEquivalenceFactor5[0] = 5;
		romanNumbersEquivalenceFactor5[1] = 50;
		romanNumbersEquivalenceFactor5[2] = 500;
		romanNumbersEquivalenceFactor5[3] = 5000;
		romanNumbersEquivalenceFactor5[4] = 50000;
		romanNumbersEquivalenceFactor5[5] = 500000;
	}

	//----------------------------------------
	string Conversor::DecimalToHexadecimalConversion(int decimalNumber)
	//----------------------------------------
	{
		string hexaNumber = "";
		
		while (decimalNumber > 15)
		{
			int resto = decimalNumber % 16;
			decimalNumber = decimalNumber / 16;
			hexaNumber = hexaNumber + hexadecimalValues[resto];
		}

		hexaNumber = hexaNumber + hexadecimalValues[decimalNumber];
		ReverseStr(hexaNumber);
		return hexaNumber;

	}

	//----------------------------------------
	string Conversor::DecimalToRomanConversion(int decimalNumber)
	//----------------------------------------
	{
		string result;
		string decimalNumberString = to_string(decimalNumber);
		int totalNumberDigits = decimalNumberString.size();

		for (int actualDigit = 0; actualDigit < totalNumberDigits; actualDigit++)
		{
			char valueActualDigit = decimalNumberString[totalNumberDigits - 1 - actualDigit];
			romanNumberToAdd = "";
			while (valueActualDigit != '0') {

				switch (valueActualDigit) 
				{
					case '1': 
					case '2': 
					case '3': RomanConversionValueDigitLower4(actualDigit);	break;
					case '4': RomanConversionValueDigitEqual4(actualDigit);	break;
					case '5': 
					case '6': 
					case '7': 
					case '8': RomanConversionValueDigitGreater4Lower9(actualDigit);	break;
					case '9': RomanConversionValueDigitEqual9(actualDigit);	break;
				}

				
				decimalNumber = decimalNumber - romanEquivalentNumberToAdd;
				decimalNumberString = to_string(decimalNumber);
				valueActualDigit = decimalNumberString[totalNumberDigits - 1 - actualDigit];
			}
			result = romanNumberToAdd + result;
		}
		return result;
	}

	
	//----------------------------------------
	void Conversor::RomanConversionValueDigitLower4(int actualDigit)
	//----------------------------------------
	{
		romanEquivalentNumberToAdd = romanNumbersEquivalenceFactor1[actualDigit];
		romanNumberToAdd = romanNumberToAdd + romanNumbersFactor1[actualDigit];
	}

	//----------------------------------------
	void Conversor::RomanConversionValueDigitEqual4(int actualDigit)
	//----------------------------------------
	{
		romanEquivalentNumberToAdd = romanNumbersEquivalenceFactor5[actualDigit] - romanNumbersEquivalenceFactor1[actualDigit];
		romanNumberToAdd = romanNumbersFactor1[actualDigit] + romanNumbersFactor5[actualDigit];
	}

	//----------------------------------------
	void Conversor::RomanConversionValueDigitGreater4Lower9(int actualDigit)
	//----------------------------------------
	{
		romanEquivalentNumberToAdd = romanNumbersEquivalenceFactor5[actualDigit];
		romanNumberToAdd = romanNumberToAdd + romanNumbersFactor5[actualDigit];
	}

	//----------------------------------------
	void Conversor::RomanConversionValueDigitEqual9(int actualDigit)
	//----------------------------------------
	{
		romanEquivalentNumberToAdd = romanNumbersEquivalenceFactor1[actualDigit + 1] - romanNumbersEquivalenceFactor1[actualDigit];
		romanNumberToAdd = romanNumbersFactor1[actualDigit] + romanNumbersFactor1[actualDigit + 1];
	}

	//----------------------------------------
	string Conversor::DecimalToBinaryConversion(int decimalNumber)
	//----------------------------------------
	{
		string binaryNumber = "";

		while (decimalNumber > 1)
		{
			int resto = decimalNumber % 2;
			decimalNumber = decimalNumber / 2;
			binaryNumber = binaryNumber + to_string(resto);
		}

		binaryNumber = binaryNumber + hexadecimalValues[decimalNumber];
		ReverseStr(binaryNumber);
		return binaryNumber;
	}

	//----------------------------------------
	void Conversor::ReverseStr(string& stringToConvert)
	//----------------------------------------
	{
		size_t stringLong = stringToConvert.length();

		for (int posChar = 0; posChar < stringLong / 2; posChar++)
		{
			swap(stringToConvert[posChar], stringToConvert[stringLong - posChar - 1]);
		}
			
	}
}
