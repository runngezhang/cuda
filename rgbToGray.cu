#include<iostream>
#include "timer.h"
#include "utils.h"
#include <string>
#include <stdio.h>
#include "reference_calc.h"
#include "compare.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.cpp>
void rgbaToGrayScale(const uchar4 * const h_rgbaImage,
			uchar4 * const d_rgbaImage,
			unsigned char* const d_greyImage,
			size_t numRows, size_t numCols);

#include "HW1.cpp"
