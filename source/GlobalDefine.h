#pragma once

#pragma region Header

#include <iostream>

#pragma endregion

/*
---------------------------------------------------------------
*/

#pragma region MACRO

#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if (p) { delete[] p; p = nullptr; }

#pragma endregion