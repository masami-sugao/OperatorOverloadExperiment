
#ifndef OPERATOR_OVERLOADED_GLOBALLY_H
#define OPERATOR_OVERLOADED_GLOBALLY_H

#include <iostream>
#include "OperatorOverloaded.h"

namespace OperatorOverloadExperiment {
class OperatorOverloadedGlobally {
public:
	int id;
	int number = 0;

	explicit OperatorOverloadedGlobally(int id) : id(id) {}

};

/// <summary>
/// 算術演算子のオーバーロード。
/// </summary>
/// <param name="rLhs">被加数</param>
/// <param name="rhs">加数</param>
/// <remarks>グローバル関数版。</remarks>
OperatorOverloadedGlobally operator+(const OperatorOverloadedGlobally& rLhs, int rhs) {
	std::cout << "global operator + called" << std::endl;
	OperatorOverloadedGlobally ret(0);
	ret.number = rLhs.number + rhs;

	return ret;
}

/// <summary>
/// 算術演算子のオーバーロード。
/// </summary>
/// <param name="lhs">被加数</param>
/// <param name="rRhs">加数</param>
/// <remarks>
/// <para>グローバル関数版。</para>
/// <para>右辺と左辺の型が異なる場合は、順番を考慮してそれぞれ実装する必要がある(必要な場合)。</para>
/// </remarks>
OperatorOverloadedGlobally operator+(int lhs, const OperatorOverloadedGlobally& rRhs) {
	std::cout << "global operator +2 called" << std::endl;
	OperatorOverloadedGlobally ret(0);
	return (rRhs + lhs);
}

/// <summary>
/// 等価比較演算子のオーバーロード。
/// </summary>
/// <param name="rLhs">被加数</param>
/// <param name="rhs">加数</param>
/// <remarks>グローバル関数版。</remarks>
bool operator==(const OperatorOverloadedGlobally& rLhs, int rhs) {
	std::cout << "global operator == called" << std::endl;
	return (rLhs.number == rhs);
}

/// <summary>
/// 不等価比較演算子のオーバーロード。
/// </summary>
/// <param name="rLhs">被加数</param>
/// <param name="rhs">加数</param>
/// <remarks>グローバル関数版。</remarks>
bool operator!=(const OperatorOverloadedGlobally& rLhs, int rhs) {
	std::cout << "global operator != called" << std::endl;
	return !(rLhs == rhs);
}

/// <summary>
/// 比較演算子<のオーバーロード。
/// </summary>
/// <param name="rLhs">被加数</param>
/// <param name="rhs">加数</param>
/// <remarks>グローバル関数版。</remarks>
bool operator<(const OperatorOverloadedGlobally& rLhs, int rhs) {
	std::cout << "global operator < called" << std::endl;
	return (rLhs.number < rhs);
}

/// <summary>
/// 比較演算子<のオーバーロード。
/// </summary>
/// <param name="lhs">被加数</param>
/// <param name="rRhs">加数</param>
/// <remarks>グローバル関数版。</remarks>
bool operator<(int lhs, const OperatorOverloadedGlobally& rRhs) {
	std::cout << "global operator <2 called" << std::endl;
	return (lhs < rRhs.number);
}

/// <summary>
/// 比較演算子>のオーバーロード。
/// </summary>
/// <param name="rLhs">被加数</param>
/// <param name="rhs">加数</param>
/// <remarks>グローバル関数版。</remarks>
bool operator>(const OperatorOverloadedGlobally& rLhs, int rhs) {
	std::cout << "global operator > called" << std::endl;
	return (rhs < rLhs);
}

/// <summary>
/// 比較演算子<=のオーバーロード。
/// </summary>
/// <param name="rLhs">被加数</param>
/// <param name="rhs">加数</param>
/// <remarks>グローバル関数版。</remarks>
bool operator<=(const OperatorOverloadedGlobally& rLhs, int rhs) {
	std::cout << "global operator <= called" << std::endl;
	return (rLhs < rhs || rLhs == rhs);
}

/// <summary>
/// 後置インクリメントのオーバーロード。
/// </summary>
/// <param name="rOperand">被加数</param>
/// <param name="_">後置インクリメントとするためのマーク</param>
/// <remarks>グローバル関数版。</remarks>
OperatorOverloadedGlobally operator++(OperatorOverloadedGlobally& rOperand, int _) {
	std::cout << "id: " << rOperand.id << " global operator postfix++ called" << std::endl;
	// 現時点のコピーを作成して退避
	OperatorOverloadedGlobally ret = rOperand;
	// インクリメント
	rOperand.number++;
	// 退避したオブジェクトを返却
	return ret;
}

/// <summary>
/// 前置インクリメントのオーバーロード。
/// </summary>
/// <param name="rOperand">加算対象</param>
/// <remarks>グローバル関数版。</remarks>
OperatorOverloadedGlobally& operator++(OperatorOverloadedGlobally& rOperand) {
	std::cout << "id: " << rOperand.id << " global operator prefix++ called" << std::endl;
	// インクリメント
	rOperand.number++;
	// 引数のオブジェクトを返却
	return rOperand;
}

/// <summary>
/// 論理否定演算子のオーバーロード。
/// </summary>
/// <param name="rOperand">オペランド</param>
/// <remarks>グローバル関数版。</remarks>
bool operator!(const OperatorOverloadedGlobally& rOperand) noexcept {
	std::cout << "id: " << rOperand.id << " global operator ! called" << std::endl;
	return (rOperand.number < 0);
}

}

#endif // OPERATOR_OVERLOADED_GLOBALLY_H
