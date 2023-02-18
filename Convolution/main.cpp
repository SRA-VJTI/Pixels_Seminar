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
    
    Mat kernel_inv;
    Mat resultant_image{original_image.size(), original_image.type()};


    // Just checking whether these funcitons are continuous or not
    kernel_inv.isContinuous();
    kernel.isContinuous();

    // ################################ Flip Kernel Suboptimally ######################## //

    // Method 2: Simply using in-built functions
    flip(kernel, kernel_inv, -1);

    // #################################################################################### //

    for (int i = 1; i < original_image.rows; i++) 
    {   
        for (int j = 1; j < original_image.cols; j++) 
        {
            double tmp = 0.0;
            for (int k = 0; k < kernel_inv.rows; k++) 
            {
                for (int l = 0; l < kernel_inv.cols; l++) 
                {
                    int x = j - 1 + l;
                    int y = i - 1 + k;

                    if ((x >= 0 && x < original_image.cols) && (y >= 0 && y < original_image.rows)){
                        tmp += (int)original_image.at<u_char>(y, x) * (int)kernel_inv.at<u_char>(k, l);
                    }
                }
            }

            resultant_image.at<u_char>(i, j) = saturate_cast<char>(tmp);
        }
    }
    return resultant_image;
}

int main( int argc, char** argv )
{
    
    Mat image = imread("walle.png",IMREAD_GRAYSCALE);    // Read Image
    Mat img2;
    // Format for last argument in Create, ones and zero
    // CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C[The channel number]

    /*  
        // Try These Lines by uncommenting the code one by one
        // kernel.create(4,4, CV_8UC(2));          // Just to create a matrix
        // kernel = Mat::ones(4,4, CV_64F);        // Just to create matrix with all entries 1
        // kernel = Mat::eye(4,4, CV_32F);         // Just to create matrix with all entries 0
    */
    double sobelx_data[9] = {0.111, 0.111, 0.111, 0.111, 0.111, 0.111, 0.111, 0.111, 0.111};
    Mat sobelx = cv::Mat(3, 3, CV_32F, sobelx_data);
    // cout<<image<<endl<<endl;
    img2 = convolve(sobelx, image);
    cout<<"Original: "<<(int)image.at<u_char>(100,250)<<endl;
    cout<<"img2: "<<(int)img2.at<u_char>(100,250)<<endl;
    // cout<<"OUTPUT = \n"<<img2<<endl<<endl;

    // Functions to show images
    namedWindow("Copy", WINDOW_NORMAL);
    imshow("Copy", img2);
    // Resizing the Window for Better Visualization
    waitKey(0);
    return 0;
}