#ifndef TEST_GLOBAL_OPERATOR_OVERLOAD_H
#define TEST_GLOBAL_OPERATOR_OVERLOAD_H

#include <iostream>
#include "OperatorOverloadedGlobally.h"

namespace OperatorOverloadExperiment {
class TestGlobalOperatorOverload {
public: 
	void Execute() {
		OperatorOverloadedGlobally overloaded1(1);
		std::cout << "[算術演算子(グローバル関数版)呼び出し]" << std::endl;
		OperatorOverloadedGlobally overloaded2 = overloaded1 + 1;
		std::cout << "overloaded2.number: " << overloaded2.number << std::endl;
		std::cout << std::endl;

		std::cout << "[等価比較演算子(グローバル関数版)呼び出し]" << std::endl;
		bool equalsTo1 = (overloaded1 == 1);
		std::cout << "equalsTo1: " << equalsTo1 << std::endl;
		std::cout << std::endl;

		std::cout << "[不等価比較演算子(グローバル関数版)呼び出し]" << std::endl;
		bool notEqualsTo1 = (overloaded1 != 1);
		std::cout << "notEqualsTo1: " << notEqualsTo1 << std::endl;
		std::cout << std::endl;

		std::cout << "[比較演算子<(グローバル関数版)呼び出し]" << std::endl;
		bool smallerThan1 = (overloaded1 < 1);
		std::cout << "smallerThan1: " << smallerThan1 << std::endl;
		std::cout << std::endl;

		std::cout << "[比較演算子>(グローバル関数版)呼び出し]" << std::endl;
		bool biggerThan1 = (overloaded1 > 1);
		std::cout << "biggerThan1: " << biggerThan1 << std::endl;
		std::cout << std::endl;

		std::cout << "[比較演算子<=(グローバル関数版)呼び出し]" << std::endl;
		bool equalsToOrSmallerThan1 = (overloaded1 <= 1);
		std::cout << "equalsToOrSmallerThan1: " << equalsToOrSmallerThan1 << std::endl;
		std::cout << std::endl;

		std::cout << "[後置インクリメント(グローバル関数版)呼び出し]" << std::endl;
		OperatorOverloadedGlobally overloaded3(3);
		overloaded3.number = 3;
		OperatorOverloadedGlobally overloaded4 = overloaded3++;
		std::cout << "overloaded3++.number: " << overloaded3.number << std::endl;
		std::cout << "overloaded4.number: " << overloaded4.number << std::endl;
		std::cout << std::endl;

		std::cout << "[前置インクリメント(グローバル関数版)呼び出し]" << std::endl;
		OperatorOverloadedGlobally overloaded5(5);
		overloaded5.number = 5;
		OperatorOverloadedGlobally overloaded6 = ++overloaded5;
		std::cout << "overloaded5++.number: " << overloaded5.number << std::endl;
		std::cout << "overloaded6.number: " << overloaded6.number << std::endl;
		std::cout << std::endl;

		std::cout << "[論理否定演算子(グローバル関数版)呼び出し]" << std::endl;
		OperatorOverloadedGlobally overloaded7(7);
		overloaded7.number = -1;
		bool isOverloaded7False = !overloaded7;
		std::cout << "!overloaded7: " << std::boolalpha << isOverloaded7False << std::endl;
		std::cout << std::endl;
	} 

};
}

#endif // TEST_GLOBAL_OPERATOR_OVERLOAD_H
