#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "timer.h"
#include <iostream>
using namespace std;
using namespace cv;
void rgbaToGrayScale(cont uchar4 * const h_rgbaImage,
			uchar4 * const d_rgbaImage,
			unsigned char* const d_greyImage,
			size_t numRows, size_t numCols);
/*TODO
Implement TIMER.h
Implement Preprocess
Implement rgb_to_grey
*/


int main(int argc, char **argv)
{
	//uchar4 is defined in vector_types.h in the SDK
	//uchar4 { unsigned char x,y,z,w; {
	uchar4 *h_rgbaImage, *d_rgbaImage;
	unsigned char *h_greyImage, *d_greyImage;

	string input_file;
	string output_file;

	input_file = "cinque_terre_small.jpg";
	output_file = "output_terre_small.jpg";	

	/*Load image and give input and output pointers*/
	preProcess(&h_rgbaImage,&h_greyImage,&d_rgbaImage,&d_greyImage, input_file);

	/*Start Timer*/
	GpuTimer timer;
	timer.Start();

	/*Execute Function*/
	rgb_to_grey(h_rgbaImage,d_rgbaImage,d_greyImage,numRows(),numCols());

	/*Stop Timer*/
	timer.Stop();	
	//cudaDeviceSynchronize() forces the program to wait for all previously issued commands in all streams on the device to finish before continuing
	cudaDeviceSynchronize();
	checkCudaErrors(cudaGetLastError());
	cout<<"Code ran in: "<<timer.Elapsed())<<" seconds"<<endl;

	//Copy the image from the device back to the host
	size_t numPixels = numRows() * numCols();
	checkCudaErrors(cudaMemCpy(h_greyImage,d_greyImage,sizeof(unsigned char) * numPixels, cudaMemcpyDeviceToHost));
	
	//check results and output the grey image	
	
	
	
	

	

	
	
	
	
	

}//end of main

