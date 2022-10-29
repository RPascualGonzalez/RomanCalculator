#pragma once
#include <string>

namespace NSP_Conversor {
	class Conversor
	{
		public:
			Conversor();

			std::string hexadecimalValues[16];
			std::string romanNumbersFactor1[7];
			std::string romanNumbersFactor5[6];
			std::string romanNumberToAdd;
			
			int romanEquivalentNumberToAdd;
			int romanNumbersEquivalenceFactor1[7];
			int romanNumbersEquivalenceFactor5[6];

			std::string DecimalToHexadecimalConversion(int decimalNumber);
			std::string DecimalToRomanConversion(int decimalNumber);
			std::string DecimalToBinaryConversion(int decimalNumber);

			void ReverseStr(std::string& str);
			void RomanConversionValueDigitLower4(int actualDigit);
			void RomanConversionValueDigitEqual4(int actualDigit);
			void RomanConversionValueDigitGreater4Lower9(int actualDigit);
			void RomanConversionValueDigitEqual9(int actualDigit);

	};
}

