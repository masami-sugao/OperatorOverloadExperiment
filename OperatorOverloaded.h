#ifndef OPERATOR_OVERLOADED_H
#define OPERATOR_OVERLOADED_H

#include <iostream>

namespace OperatorOverloadExperiment {
class OperatorOverloaded {
public:
	int number = 0;
	OperatorOverloaded* pInstance = this;

	explicit OperatorOverloaded(int id) : id(id) {}

	/// <summary>
	/// メンバ選択演算子のオーバーロード。
	/// </summary>
	/// <remarks>メンバ関数としてのみ定義可能。</remarks>
	OperatorOverloaded* operator->() const {
		std::cout << "id: " << this->id << " operator -> called" << std::endl;
		return const_cast<OperatorOverloaded*>(pInstance);
	}

	/// <summary>
	/// 複合代入演算子のオ翡加算ロード。
	/// </summary>
	/// <param name="rOperand">加数</param>
	/// <remarks>メンバ関数としてのみ定義可能。</remarks>
	OperatorOverloaded& operator+=(const OperatorOverloaded& rOperand) {
		std::cout << "id: " << this->id << " operator += called" << std::endl;
		this->number += rOperand.number;
		return *this;
	}
	
	/// <summary>
	/// 算術演算子のオーバーロード。
	/// </summary>
	/// <param name="rOperand">加数</param>
	/// <remarks>メンバ関数版。</remarks>
	OperatorOverloaded operator+(const OperatorOverloaded& rOperand) {
		std::cout << "id: " << this->id << " member operator + called" << std::endl;
		OperatorOverloaded ret(0);
		ret.number = this->number + rOperand.number;

		return ret;
	}

	/// <summary>
	/// 等価比較演算子のオーバーロード。
	/// </summary>
	/// <param name="rOperand">加数</param>
	/// <remarks>メンバ関数版。</remarks>
	bool operator==(const OperatorOverloaded& rOperand) {
		std::cout << "id: " << this->id << " member operator == called" << std::endl;
		return (this->number == rOperand.number);
	}

	/// <summary>
	/// 不等価比較演算子のオーバーロード。
	/// </summary>
	/// <param name="rOperand">加数</param>
	/// <remarks>メンバ関数版。</remarks>
	bool operator!=(const OperatorOverloaded& rOperand) {
		std::cout << "id: " << this->id << " member operator != called" << std::endl;
		return !(*this == rOperand);
	}

	/// <summary>
	/// 比較演算子<のオーバーロード。
	/// </summary>
	/// <param name="rOperand">加数</param>
	/// <remarks>メンバ関数版。</remarks>
	bool operator<(const OperatorOverloaded& rOperand) {
		std::cout << "id: " << this->id << " member operator < called" << std::endl;
		return (this->number < rOperand.number);
	}

	/// <summary>
	/// 比較演算子>のオーバーロード。
	/// </summary>
	/// <param name="rOperand">加数</param>
	/// <remarks>メンバ関数版。</remarks>
	bool operator>(const OperatorOverloaded& rOperand) {
		std::cout << "id: " << this->id << " member operator > called" << std::endl;
		return (const_cast<OperatorOverloaded&>(rOperand) < *this);
	}

	/// <summary>
	/// 比較演算子<=のオーバーロード。
	/// </summary>
	/// <param name="rOperand">加数</param>
	/// <remarks>メンバ関数版。</remarks>
	bool operator<=(const OperatorOverloaded& rOperand) {
		std::cout << "id: " << this->id << " member operator <= called" << std::endl;
		return (*this < rOperand || *this == rOperand);
	}

	/// <summary>
	/// 後置インクリメントのオーバーロード。
	/// </summary>
	/// <param name="_">後置インクリメントとするためのマーク</param>
	/// <remarks>メンバ関数版。</remarks>
	OperatorOverloaded operator++(int _) {
		std::cout << "id: " << this->id << " member operator postfix++ called" << std::endl;
		// 現時点のコピーを作成して退避
		OperatorOverloaded ret = *this;
		// インクリメント
		this->number++;
		// 退避したオブジェクトを返却
		return ret;
	}

	/// <summary>
	/// 前置インクリメントのオーバーロード。
	/// </summary>
	/// <remarks>メンバ関数版。</remarks>
	OperatorOverloaded& operator++() {
		std::cout << "id: " << this->id << " member operator prefix++ called" << std::endl;
		// インクリメント
		this->number++;
		// 自身を返却
		return *this;
	}

	/// <summary>
	/// 論理否定演算子のオーバーロード。
	/// </summary>
	/// <remarks>メンバ関数版。</remarks>
	bool operator!() const noexcept {
		std::cout << "id: " << this->id << " member operator ! called" << std::endl;
		return (this->number < 0);
	}

private:
	int id;

};
}
#endif // OPERATOR_OVERLOADED_H
