#include<iostream>
#include<cuda.h>
using namespace std;

__global__ void cube(float *d_out, float* d_in)
{
	int idx = threadIdx.x;
	float f = d_in[idx] ;
	//The d_ implies that the array sits on the device
	d_out[idx] = f*f*f;
}//end of kernel 'cube'

int main(int argc, char** argv)
{
	const int ARRAY_SIZE = 96;
	const int ARRAY_BYTES = ARRAY_SIZE * sizeof(float);
	//generate input array on the host
	float h_in[ARRAY_SIZE];
	//the h_ implies that the array sits on the host
	//Build the test array - the elements of which are going to be cubed
	for(int i=0; i< ARRAY_SIZE; i++)
	{
		h_in[i] = float(i);
	}//end of for
	float h_out[ARRAY_SIZE];
	
	//declare GPU memory pointers
	float *d_in;
	float *d_out;

	//allocate memory for the two arrays on the device
	cudaMalloc((void**)&d_in,ARRAY_BYTES);
	cudaMalloc((void**)&d_out,ARRAY_BYTES);
	
	//transfer the array to the GPU
	// destination,source,size,method
	cudaMemcpy(d_in,h_in,ARRAY_BYTES,cudaMemcpyHostToDevice);

	//launch the kernel	
	cube<<<1,ARRAY_SIZE>>>(d_out,d_in);
	//Kernelname<<<number_of_blocks,number_of_threads_per_block>>(parameters to kernel);

	//copy the results back onto the device
	cudaMemcpy(h_out,d_out,ARRAY_BYTES,cudaMemcpyDeviceToHost);
	
	//print out the results
	for(int i=0;i < ARRAY_SIZE; i++)
	{
		cout<<i<<":"<<h_out[i]<<endl;
	}//end of for
	
	cudaFree(d_in);
	cudaFree(d_out);

}//end of main
