#pragma once

#include "GlobalDefine.h"
#include <map>

template <typename _Ty>
class MyDeque {
private:
	static constexpr int Block_Size = 8;

public:
	explicit MyDeque() {}
	~MyDeque() {}

private:
	map<int, _Ty*> Map_;
	
};