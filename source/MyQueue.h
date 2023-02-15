#pragma once

#include "GlobalDefine.h"
#include "MyLinkedList.h"

template <typename _Ty>
class MyQueue {
public:
	explicit MyQueue() : lst_() {}
	//explicit MyQueue(const int& _maxSize, const _Ty& _ty = _Ty()) : vec_(_maxSize, _ty) {}

	~MyQueue() {}

public:
	inline void push(const _Ty& _val)
	{
		lst_.push_back(_val);
	}

	inline void push(_Ty&& _val)
	{
		lst_.push_back(std::move(_val));
	}

	inline void pop()
	{
		lst_.pop_front();
	}

	inline _Ty& front()
	{
		return lst_.front();
	}

	inline bool empty() const { return size() == 0; }

	inline const int& size() const { return lst_.size(); }

private:
	MyLinkedList<_Ty> lst_;
};