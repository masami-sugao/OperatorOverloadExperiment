#include <iostream>
#include "TestOperatorOverload.h"
#include "TestGlobalOperatorOverload.h"
#include "TestArraySubscript.h"

int main() {
	std::cout << "Hello, World" << std::endl;

	using namespace OperatorOverloadExperiment;

	std::cout << "*** メンバ関数での算術系演算子オーバーロード ***************************************************************" << std::endl;
	TestOperatorOverload testOperatorOverload;
	testOperatorOverload.Execute();

	std::cout << "*** グローバル関数での算術系演算子オーバーロード ***************************************************************" << std::endl;
	TestGlobalOperatorOverload testGlobalOperatorOverload;
	testGlobalOperatorOverload.Execute();

	std::cout << "*** 添字演算子オーバーロード ***************************************************************" << std::endl;
	TestArraySubsucript testArraySubsucript;
	testArraySubsucript.Execute();

	return 0;
}