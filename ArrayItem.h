#ifndef ARRAY_ITEM_H
#define ARRAY_ITEM_H

#include <iostream>

namespace OperatorOverloadExperiment {
class ArrayItem {
public:
	int value;

	ArrayItem(int value): value(value) {
		std::cout << "ArrayItem(" << std::hex << this << ") constructor called" << std::endl;
		this->pNumber = new int(9);
	}

	 /// <summary>
	 //// コピーコンストラクタ
	 /// </summary>
	 /// <param name="rSrc">コピー元</param>
	ArrayItem(const ArrayItem& rSrc) {
		std::cout << "ArrayItem(" << std::hex << this << ") copy constructor value: " << rSrc.value << " called. Src(" << std::hex << &rSrc << ")" << std::endl;
		this->value = rSrc.value;
		// Deep copy にする場合はポインタは新しくメモリを確保して同じ値を設定
		this->pNumber = new int(*(rSrc.pNumber));
	}

	 /// <summary>
	 //// ムーブコンストラクタ
	 /// </summary>
	 /// <param name="rrSrc">コピー元</param>
	 /// <remarks>noexceptを付与しないとコンパイラのバージョンによってはムーブコンストラクタとして呼ばれないことがある</remarks>
	ArrayItem(ArrayItem&& rrSrc) noexcept {
		std::cout << "ArrayItem(" << std::hex << this << ") move constructor value: " << rrSrc.value << " called. Src(" << std::hex << &rrSrc << ")" << std::endl;
		this->value = rrSrc.value;

		// ポインタはコピーせずに付け替え
		this->pNumber = rrSrc.pNumber;
		// rrSrcのデストラクタでpNumberが解放されないようにnull代入
		rrSrc.pNumber = nullptr;

		// この後rrSrcのデストラクタが呼ばれる。
	}
	
	~ArrayItem() {
		std::cout << "ArrayItem(" << std::hex << this << ") value: " << this->value << " destructor called" << std::endl;
		delete this->pNumber;
	}
	
	/// <summary>
	/// コピー代入演算子のオーバーロード。
	/// </summary>
	/// <param name="rSrc">コピー元</param>
	/// <remarks>メンバ関数としてのみ定義可能。</remarks>
	ArrayItem& operator=(const ArrayItem& rSrc) {
		std::cout << "ArrayItem(" << std::hex << this << ") operator copy = called" << std::endl;
		std::cout << "Src(" << std::hex << &rSrc << ")" << std::endl;
		std::cout << "    Src.value: " << rSrc.value << "" << std::endl;
		std::cout << "    Src.pNumber: " << std::hex << rSrc.pNumber << std::endl;
		std::cout << "this(" << std::hex << this << ")-コピー前" << std::endl;
		std::cout << "    this.value: " << this->value << "" << std::endl;
		std::cout << "    this.pNumber: " << std::hex << this->pNumber << std::endl;

		// コピー元とコピー先のアドレスが異なる場合のみコピーを行う
		if (this != &rSrc) {
			this->value = rSrc.value;
			// Deep copy にする場合はポインタは新しくメモリを確保して同じ値を設定
			delete this->pNumber;
			this->pNumber = new int(*(rSrc.pNumber));
		}

		std::cout << "this(" << std::hex << this << ")-コピー後" << std::endl;
		std::cout << "    this.value: " << this->value << "" << std::endl;
		std::cout << "    this.pNumber: " << std::hex << this->pNumber << std::endl;
		return *this;
	}

	void Print() const {
		std::cout << "ArrayItem(" << std::hex << this << ").Print() called value: " << this->value << " pNumber: " << *(this->pNumber) << std::endl;
	}

private: 
	int* pNumber = nullptr;

};
}

#endif // ARRAY_ITEM_H
