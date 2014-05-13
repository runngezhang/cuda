#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.cpp>
#include <opencv2/opencv.hpp>
#include "utils.h"
#include <cuda.h>
#include <cuda_runtime.h>
#include <string>

cv::Mat imageRGBA;
cv::Mat imageGrey;

uchar4 *d_rgbaImage__;
unsigned char *d_greyImage__;

size_t numRows() { return imageRGBA.rows;}
size_t numCols() { return imageRGBA.cols;}

void preProcess(uchar4 **inputImage, unsigned char **greyImage, 
		uchar4 **d_rgbaImage, unsigned char **d_greyImage,
		const std::string &filename)
{
	checkCudaErrors(cudaFree(0));	
	cv::Mat image;
	
