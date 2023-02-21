
using std::cout;
using std::endl;

int main() {
    // Constructing from an Array
    uint8_t greyArr[11][11] = {
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 }
    };

    cv::Mat greyImg = cv::Mat(11, 11, CV_8U, &greyArr);
    std::string greyArrWindow = "Grey Array Image";
    cv::namedWindow(greyArrWindow, cv::WINDOW_AUTOSIZE);
    cv::imshow(greyArrWindow, greyImg);

    // note that the above simply copied the pointer into the Mat
    // object thus, its is only operatoring on the original array
    // data which is very fast but, may not be exactly what you want    
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            greyArr[i][j] = 100;
        }
    }
    std::string monoGreyImgWindow = "Mono Grey Arr Image";
    cv::namedWindow(monoGreyImgWindow);
    cv::imshow(monoGreyImgWindow, greyImg);

    // The Mat class also prints to standard out in a nicely readable format 
    // (a handy debugging feature for smallish Mat objects)
    cout << "greyImg = \n" << greyImg << endl;

    // Now lets say I want to copy the data from my 2D array into a Mat instance so it
    // has it's own copy to use and manage I can do so with memcpy
    cv::Mat greyImgForArrCopy = cv::Mat(11, 11, CV_8U);
    std::memcpy(greyImgForArrCopy.data, greyArr, 11 * 11 * sizeof(uint8_t));

    // update every element of greyArr to be black (ie, 0)
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            greyArr[i][j] = 0;
        }
    }
    std::string copyedArrImg = "Grey Copied Image";
    cv::namedWindow(copyedArrImg);
    cv::imshow(copyedArrImg, greyImgForArrCopy);



    // Construct from vector
    std::vector<uint8_t> vec = {
        0,   0,   0,   0,   0,   0,
        25,  25,  25,  25,  25,  25,
        50,  50,  50,  50,  50,  50,
        75,  75,  75,  75,  75,  75,
        100, 100, 100, 100, 100, 100,
        125, 125, 125, 125, 125, 125,
        150, 150, 150, 150, 150, 150,
        175, 175, 175, 175, 175, 175,
        200, 200, 200, 200, 200, 200,
        225, 225, 225, 225, 225, 225,
        255, 255, 255, 255, 255, 255
    };
    cv::Mat greyImgFromVec(11, 6, CV_8U, vec.data());
    std::string greyImgFromVecWindow = "Grey Image From Vec";
    cv::namedWindow(greyImgFromVecWindow);
    cv::imshow(greyImgFromVecWindow, greyImgFromVec);

    // similar to what was shown in the Array section when a Mat object
    // is constructed in this manner a pointer to the vector data is copied
    // to the data field within the Mat object so, modifying the source vector
    // data will be reflected when displaying the contents of the Mat object.

    // again, the memcpy function can be used to copy a vector's data into
    // a Mat object similar to what was shown with the array example previously.

    cv::Mat greyImgForVecCopy = cv::Mat(cv::Size(6, 11), CV_8U);
    std::memcpy(greyImgForVecCopy.data, vec.data(), vec.size() * sizeof(uint8_t));

    std::fill(std::begin(vec), std::end(vec), 100);

    std::string greyImgFromVecCopyWindow = "Grey Image Vec Copy";
    cv::namedWindow(greyImgFromVecCopyWindow);
    cv::imshow(greyImgFromVecCopyWindow, greyImgForVecCopy);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}