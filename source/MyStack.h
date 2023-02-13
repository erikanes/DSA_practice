#pragma once

#include "GlobalDefine.h"
#include "MyLinkedList.h"
#include "MyVector.h"

/*
수정 예정사항
- 이동 생성자 및 연산자 구현
*/

#pragma region ver. List

//template <typename _Ty>
//class MyStack {
//public:
//	explicit MyStack() : list_() {}
//
//	~MyStack() {}
//
//public:
//	inline void push(const _Ty& _val)
//	{
//		list_.push_back(_val);
//	}
//
//	inline void push(_Ty&& _val)
//	{
//		list_.push_back(std::move(_val));
//	}
//
//	inline void pop()
//	{
//		list_.pop_back();
//	}
//
//	inline _Ty& top()
//	{
//		return list_.back();
//	}
//
//	inline bool empty() const { return size() == 0; }
//
//	inline const int& size() const { return list_.size(); }
//
//private:
//	MyLinkedList<_Ty> list_;
//};

#pragma endregion

#pragma region ver. Vector

template <typename _Ty>
class MyStack {
public:
	explicit MyStack() : vec_() {}

	~MyStack() {}

public:
	inline void push(const _Ty& _val)
	{
		vec_.push_back(_val);
	}

	inline void push(_Ty&& _val)
	{
		vec_.push_back(std::move(_val));
	}

	inline void pop()
	{
		vec_.pop_back();
	}

	inline _Ty& top()
	{
		return vec_.back();
	}

	inline bool empty() const { return size() == 0; }

	inline const int& size() const { return vec_.size(); }

private:
	MyVector<_Ty> vec_;
};

#pragma endregion