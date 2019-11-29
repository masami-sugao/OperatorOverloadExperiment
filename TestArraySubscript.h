#ifndef TEST_ARRAY_SUBSCRIPT_H
#define TEST_ARRAY_SUBSCRIPT_H

#include <iostream>
#include "ArraySubscriptOverloaded.h"

namespace OperatorOverloadExperiment {
class TestArraySubsucript {
public:
	void Execute() {
		std::cout << "[添字演算子 左辺値 const返却 呼び出し]" << std::endl;
		ArraySubscriptOverloaded overloaded1(1);
		overloaded1[0].Print();
		std::cout << std::endl;

		std::cout << "[コピー代入演算子のオーバーロード呼び出し]" << std::endl;
		ArrayItem item1(0);
		// コピー代入
		item1 = overloaded1[1];
		// 同じインスタンスにコピー代入
		item1 = item1;
		std::cout << std::endl;

		std::cout << "[添字演算子 左辺値 参照返却 呼び出し]" << std::endl;
		overloaded1[0].value = 1;
		std::cout << std::endl;

		std::cout << "[添字演算子 右辺値 呼び出し]" << std::endl;
		ArrayItem item = ArraySubscriptOverloaded(2)[0];
		item.Print();
		std::cout << std::endl;

		std::cout << "[TestArraySubscript.Execute() 終了]" << std::endl;
	}

};
}

#endif // TEST_ARRAY_SUBSCRIPT_H
