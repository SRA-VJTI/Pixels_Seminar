#include <opencv2/opencv.hpp>
#include <iostream>

/*
    Specifying Namespaces
    Namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it. 
*/
using namespace std;
using namespace cv;

/// @brief : Convolution will help apply different kernels to your images yielding different results
/// @param   Original_image
/// @param   kernel
/// @return : An Output Image with the kernel applied
Mat convolve(Mat kernel, Mat original_image){
    
    Mat kernel_inv{kernel.size(), kernel.type()}, temp_kernel{kernel.size(), kernel.type()};
    Mat resultant_image{original_image.size(), original_image.type()};

    // Just checking whether these funcitons are continuous or not
    kernel_inv.isContinuous();
    kernel.isContinuous();

    // ################################ Flip Kernel Suboptimally ######################## //

    /* 
        ################################### Using For Loops ###############################
    for(int i = 0 ; i < kernel.rows ; i++ ){
        cout<<"k"<<endl;
        kernel_inv.row(i) = kernel.row(kernel.rows - i - 1).clone(); 
    }

    temp_kernel = kernel_inv.clone();

    for(int i = 0 ; i < kernel.cols ; i++ ){
        kernel_inv.col(i) = temp_kernel.col(kernel.cols - i - 1).clone();
    }
    */


    // Method 2: Simply using in-built functions
    flip(kernel, kernel_inv, -1);  

    // Viewing channels for each image
    // cout<<original_image.channels()<<endl;

    // #################################################################################### //

    for (int i = 1; i < original_image.rows - 1; i++) 
    {   
        for (int j = 1; j < original_image.cols - 1 ; j++) 
        {
            for(int ch = 0 ; ch < original_image.channels() ; ch++){

                double tmp = 0.0;
                for (int k = 0; k < kernel_inv.rows; k++) 
                {
                    for (int l = 0; l < kernel_inv.cols; l++) 
                    {
                        int x = j - 1 + l;
                        int y = i - 1 + k; 

                        if ((x >= 0 && x < original_image.cols) && (y >= 0 && y < original_image.rows)){
                            tmp += (double)original_image.at<Vec3b>(y, x).val[ch] * (double)kernel_inv.at<double>(k, l);
                        }
                    }
                }

                resultant_image.at<Vec3b>(i, j).val[ch] = saturate_cast<uchar>(tmp);        // Why Unsigned? 
            }
        }
    }
    return resultant_image;
}