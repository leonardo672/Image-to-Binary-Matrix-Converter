#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>


cv::Mat imageToBinaryMatrix(const std::string& imagePath, int threshold) {

    cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);


    if (image.empty()) {
        std::cerr << "Error: Unable to load image from " << imagePath << std::endl;
        exit(EXIT_FAILURE);
    }

  
    cv::Mat binaryImage;
    cv::threshold(image, binaryImage, threshold, 1, cv::THRESH_BINARY);

    return binaryImage;
}


void saveBinaryMatrixToFile(const cv::Mat& binaryMatrix, const std::string& filePath) {

    std::ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Failed to open " << filePath << " for writing." << std::endl;
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < binaryMatrix.rows; ++i) {
        for (int j = 0; j < binaryMatrix.cols; ++j) {
            outputFile << static_cast<int>(binaryMatrix.at<uchar>(i, j)) << " ";
        }
        outputFile << "\n";
    }


    outputFile.close();

    std::cout << "Binary matrix saved to " << filePath << std::endl;
}

int main() {

    std::string imagePath = "D:/New Folder/C++/OP_T/ConsoleApplication1/DS.jpg"; 


    int thresholdValue = 128; 


    cv::Mat binaryMatrix = imageToBinaryMatrix(imagePath, thresholdValue);


    std::string outputFilePath = "binary_matrix.txt"; 
    saveBinaryMatrixToFile(binaryMatrix, outputFilePath);

    return 0;
}
