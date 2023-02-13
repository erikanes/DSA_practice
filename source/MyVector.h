#pragma once

#include "GlobalDefine.h"

/*
수정 예정사항
- 이동 생성자 및 연산자 구현
*/

template<typename _Ty>
class MyVector {
public:
	MyVector() :
		currentSize_(0),
		maxCapacity_(0),
		data_(nullptr)
	{}

	explicit MyVector(const int& _maxCapacity, const _Ty& _ty = _Ty()) :
		currentSize_(0),
		maxCapacity_(_maxCapacity),
		data_(nullptr)
	{
		data_ = new _Ty[_maxCapacity];

		for (int i = 0; i < _maxCapacity; ++i)
			push_back(_ty);
	}

	explicit MyVector(const MyVector& _vec) :
		currentSize_(0),
		maxCapacity_(_vec.maxCapacity_),
		data_(nullptr)
	{
		this->operator=(_vec);
	}

	//explicit MyVector(MyVector&& _vec) noexcept :
	//	currentSize_(_vec.currentSize_),
	//	maxCapacity_(_vec.maxCapacity_),
	//	data_(_vec.data_)
	//{
	//	this->operator=(std::forward<_Ty>(_vec));
	//}

	~MyVector()
	{
		if (nullptr != data_) {
			delete[] data_;
			data_ = nullptr;
		}
	}

public:
	MyVector& operator=(const MyVector& _vec)
	{
		maxCapacity_ = _vec.maxCapacity_;
		data_ = new _Ty[_vec.maxCapacity_];

		for (int i = 0; i < _vec.maxCapacity_; ++i)
			push_back(_vec[i]);
	}

	//MyVector& operator=(MyVector&& _vec) noexcept
	//{
	//	/* 수정해야됨. 주소만 들고오는게 아니라 전체 요소를 move? */
	//	currentSize_ = _vec.currentSize_;
	//	maxCapacity_ = _vec.maxCapacity_;
	//	data_ = _vec.data_;

	//	_vec.currentSize_ = 0;
	//	_vec.maxCapacity_ = 0;
	//	_vec.data_ = nullptr;
	//}

	_Ty& operator[](const int& _idx) const
	{
		return this->at(_idx);
	}

public:
	void push_back(const _Ty& _data)
	{
		if (currentSize_ >= maxCapacity_) {
			if (maxCapacity_ < 2)
				++maxCapacity_;
			else
				maxCapacity_ += maxCapacity_ / 2;

			_Ty* newData = new _Ty[maxCapacity_];
			for (int i = 0; i < currentSize_; ++i) {
				newData[i] = data_[i];
			}
			if (data_)
				delete[] data_;

			data_ = newData;
		}
		data_[currentSize_] = _data;
		++currentSize_;
	}

	void emplace_back(const _Ty& _data)
	{
		push_back(_data);
	}

	void emplace_back(_Ty&& _data) noexcept
	{
		if (currentSize_ < maxCapacity_) {
			data_[currentSize_] = std::move(_data);
			++currentSize_;
		}
		else
			push_back(_data);
	}

	void pop_back()
	{
		if (!empty()) --currentSize_;
	}

	_Ty& front() const
	{
		if (currentSize_ <= 0) abort();
		return at(0);
	}

	_Ty& back() const
	{
		if (currentSize_ <= 0) abort();
		return at(currentSize_ - 1);
	}

	_Ty& at(const int& _index) const
	{
		if (_index > currentSize_) abort();
		return *(data_ + _index);
	}

	bool empty() const
	{
		return currentSize_ <= 0;
	}

	int size() const
	{
		return currentSize_;
	}

	int capacity() const
	{
		return maxCapacity_;
	}

private:
	_Ty* data_;

	int currentSize_;
	int maxCapacity_;
};