/*
 * Mscnn.hpp
 *
 *  Created on: 19 de ago de 2017
 *      Author: luan
 */

#ifndef MSCNN_HPP_
#define MSCNN_HPP_

#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <string>
#include <vector>
#include <caffe/caffe.hpp>

class Mscnn
{
public:
	Mscnn(const std::string &model_file, const std::string& trained_file, int GPU, int device_id);

	std::vector<float> Predict(const cv::Mat& img);

private:

	void WrapInputLayer(std::vector<cv::Mat>* input_channels);

	void Preprocess(const cv::Mat& img, std::vector<cv::Mat>* input_channels);

	boost::shared_ptr<caffe::Net<float>> net_;
	cv::Size input_geometry_;
	int num_channels_;

};



#endif /* MSCNN_HPP_ */
