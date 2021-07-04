#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	std::cout << CV_VERSION << std::endl;

	Mat img;
	// Mat imread (const String& filename, int flags=IMREAD_COLOR);
	//bool imwrite(const String& filename, InputArray img, const std::vector<int>& params=std::vector<int>());
	img=imread("")


	return 0;
}
