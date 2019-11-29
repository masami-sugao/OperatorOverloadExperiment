#ifndef ARRAY_SUBSCRIPT_OVERLOADED_H
#define ARRAY_SUBSCRIPT_OVERLOADED_H

#include <iostream>
#include "ArrayItem.h"

namespace OperatorOverloadExperiment {
class ArraySubscriptOverloaded {
public:
	ArraySubscriptOverloaded(int id) : id(id) {
		for (int i = 0; i < sizeof(this->array) / sizeof(this->array[0]); ++i) {
			this->array[i] = new ArrayItem(i + 1);
		}
	}

	~ArraySubscriptOverloaded() {
		std::cout << "ArraySubscriptOverloaded " << this->id << " destructor called" << std::endl;
		for (int i = 0; i < sizeof(this->array) / sizeof(this->array[0]); ++i) {
			delete this->array[i];
			this->array[i] = nullptr;
		}
	}

	/// <summary>
	/// 添字演算子のオーバーロード。
	/// </summary>
	/// <param name="index">インデックス</param>
	/// <remarks>
	/// <para>メンバ関数としてのみ定義可能。</para>
	/// <para>左辺値にconst参照で受けるパターン用。</para>
	/// </remarks>
	const ArrayItem& operator[](const int index) const& {
		std::cout << "id " << this->id << " operator [] const& called" << std::endl;
		return *(this->array[index]);
	}

	/// <summary>
	/// 添字演算子のオーバーロード。
	/// </summary>
	/// <param name="index">インデックス</param>
	/// <remarks>
	/// <para>メンバ関数としてのみ定義可能。</para>
	/// <para>左辺値に参照で受けるパターン用。</para>
	/// </remarks>
	ArrayItem& operator[](const int index) & {
		std::cout << "id " << this->id << " operator [] & called" << std::endl;
		return *(this->array[index]);
	}

	/// <summary>
	/// 添字演算子のオーバーロード。
	/// </summary>
	/// <param name="index">インデックス</param>
	/// <remarks>
	/// <para>メンバ関数としてのみ定義可能。</para>
	/// <para>右辺値で使用するパターン用。</para>
	/// </remarks>
	ArrayItem operator[](const int index) const&& {
		std::cout << "id " << this->id << " operator [] && called" << std::endl;
		// 右辺値で使用される場合、受け取った変数が当オブジェクトの寿命が尽きた後にアクセスされる可能性があるので
		// ムーブ可能な形で返却する。
		return std::move(*(this->array[index]));
	}

private:
	int id;
	ArrayItem* array[5];

};
}

#endif // ARRAY_SUBSCRIPT_OVERLOADED_H
