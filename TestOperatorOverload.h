#ifndef TEST_OPERATOR_OVERLOAD_H
#define TEST_OPERATOR_OVERLOAD_H

#include <iostream>
#include "OperatorOverloaded.h"

namespace OperatorOverloadExperiment {
class TestOperatorOverload {
public: 
	void Execute() {
		std::cout << "[アロー演算子呼び出し]" << std::endl;
		// アロー演算子のオーバーロードは実体に対するメソッドとなる
		OperatorOverloaded overloaded1(1);
		overloaded1->number = 1;
		std::cout << std::endl;

		OperatorOverloaded overloaded2(2);
		overloaded2.number = 2;
		std::cout << "[複合演算子呼び出し]" << std::endl;
		overloaded1 += overloaded2;
		std::cout << "overloaded1.number: " << overloaded1.number << std::endl;
		std::cout << std::endl;

		overloaded1.number = 1;
		std::cout << "[算術演算子(メンバ関数版)呼び出し]" << std::endl;
		OperatorOverloaded overloaded3 = overloaded1 + overloaded2;
		std::cout << "overloaded3.number: " << overloaded3.number << std::endl;
		std::cout << std::endl;

		std::cout << "[等価比較演算子(メンバ関数版)呼び出し]" << std::endl;
		bool equalsTo2 = (overloaded1 == overloaded2);
		std::cout << "equalsTo2: " << equalsTo2 << std::endl;
		std::cout << std::endl;

		std::cout << "[不等価比較演算子(メンバ関数版)呼び出し]" << std::endl;
		bool notEqualsTo2 = (overloaded1 != overloaded2);
		std::cout << "notEqualsTo2: " << notEqualsTo2 << std::endl;
		std::cout << std::endl;

		std::cout << "[比較演算子<(メンバ関数版)呼び出し]" << std::endl;
		bool smallerThan2 = (overloaded1 < overloaded2);
		std::cout << "smallerThan2: " << smallerThan2 << std::endl;
		std::cout << std::endl;

		std::cout << "[比較演算子>(メンバ関数版)呼び出し]" << std::endl;
		bool biggerThan2 = (overloaded1 > overloaded2);
		std::cout << "biggerThan2: " << biggerThan2 << std::endl;
		std::cout << std::endl;

		std::cout << "[比較演算子<=(メンバ関数版)呼び出し]" << std::endl;
		bool equalsToOrSmallerThan2 = (overloaded1 <= overloaded2);
		std::cout << "equalsToOrSmallerThan2: " << equalsToOrSmallerThan2 << std::endl;
		std::cout << std::endl;

		std::cout << "[後置インクリメント(メンバ関数版)呼び出し]" << std::endl;
		OperatorOverloaded overloaded5(5);
		overloaded5.number = 5;
		OperatorOverloaded overloaded6 = overloaded5++;
		std::cout << "overloaded5++.number: " << overloaded5.number << std::endl;
		std::cout << "overloaded6.number: " << overloaded6.number << std::endl;
		std::cout << std::endl;

		std::cout << "[前置インクリメント(メンバ関数版)呼び出し]" << std::endl;
		OperatorOverloaded overloaded7(7);
		overloaded7.number = 7;
		OperatorOverloaded overloaded8 = ++overloaded7;
		std::cout << "++overloaded7.number: " << overloaded7.number << std::endl;
		std::cout << "overloaded8.number: " << overloaded8.number << std::endl;
		std::cout << std::endl;

		std::cout << "[論理否定演算子(メンバ関数版)呼び出し]" << std::endl;
		OperatorOverloaded overloaded9(9);
		overloaded9.number = -1;
		bool isOverloaded9False = !overloaded9;
		std::cout << "!overloaded9: " << std::boolalpha << isOverloaded9False << std::endl;
		std::cout << std::endl;
	} 

};
}

#endif // TEST_OPERATOR_OVERLOAD_H
