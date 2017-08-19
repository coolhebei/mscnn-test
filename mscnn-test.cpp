/*
 * mscnn-test.cpp
 *
 *  Created on: 19 de ago de 2017
 *      Author: luan
 */

#include "Mscnn.hpp"

#include <stdio.h>


int main(int argc, char **argv)
{
	std::string model_file = "mscnn_deploy.prototxt";
	std::string trained_file = "mscnn_kitti_trainval_2nd_iter_35000.caffemodel";

	if (argc < 2)
	{
		printf("Usage %s <image filename>\n", argv[0]);
		return -1;
	}
	std::string file = argv[1];
	int gpu = 1;
	int device_id = 0;

	// loads the detect net
	Mscnn mscnn(model_file, trained_file, gpu, device_id);

	cv::Mat img = cv::imread(file, -1);

	// forward the image through the network
	std::vector<float> result = mscnn.Predict(img);

	for (unsigned int i = 0; i < result.size(); i++)
	{
		printf("%f\n", result[i]);
	}

	// fix the scale of image
	float correction_x = img.cols / 1250.0;
	float correction_y = img.rows / 380.0;

//	char output_file_name[25];
//	sprintf(output_file_name, "%s.txt", argv[1]);

//	FILE *output_file = fopen(output_file_name, "w");

//	for (int i = 0; i < 10; i++)
//	{
//		// top left
//		float xt = result[5*i] * correction_x;
//		float yt = result[5*i + 1] * correction_y;
//
//		// botton right
//		float xb = result[5*i + 2] * correction_x;
//		float yb = result[5*i + 3] * correction_y;
//
//		float confidence = result[5*i + 4];
//		if (confidence > 0.0)
//		{
//			fprintf(output_file, "Car 0.00 0 0.00 %.2f %.2f %.2f %.2f 0.00 0.00 0.00 0.00 0.00 0.00 0 %.2f\n", xt, yt, xb, yb, confidence);
//			//cv::rectangle(img, cv::Point(xt,yt), cv::Point(xb,yb), cv::Scalar(0,255,0), 2);
//		}
//	}

	/*
	if (img.empty())
	{
		printf("image empty\n");
	}
	else
	{
		cv::imshow("Image", img);
		cv::waitKey(0);
	}
	*/
	return 0;
}


