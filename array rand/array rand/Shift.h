#pragma once
#include"constants.h"
#include"stdafx.h"
template<typename T>void Shift(T arr[], int n);
template<typename T>T ShiftLeft(T arr[], const int n);
template<typename T>T ShiftRight(T arr[], const int n);

template<typename T>void Shift(T arr[ROWS][COLS], const int ROWS, const int COLS);
template<typename T>T ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS);
template<typename T>T ShiftRight(T arr[ROWS][COLS], const int ROWS, const int COLS);