#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;
/*
void detect_eye()
{
	CascadeClassifier face_classifier("haarcascade_frontalface_default.xml");
	CascadeClassifier eye_classifier("haarcascade_eye.xml");

	if (face_classifier.empty() || eye_classifier.empty()) {
		cerr << "XML load failed!" << endl;
	}

	vector<Rect> faces;
	face_classifier.detectMultiScale(src, faces);

	for (Rect face : faces) {
		rectangle(src, face, Scalar(255, 0, 255), 2);

		Mat faceROI = src(face);
		vector<Rect> eyes;
		eye_classifier.detectMultiScale(faceROI, eyes);

		for (Rect eye : eyes) {
			Point center(eye.x + eye.width / 2, eye.y + eye.height / 2);
			circle(faceROI, center, eye.width / 2, Scalar(255, 0, 0), 2, LINE_AA);
		}
	}

	imshow("src", src);
}*/


int main()
{
	// std::cout << CV_VERSION << std::endl; 버전 확인

	VideoCapture video; // videocapture 객체 생성 및 호출
	video.open("eye2.mp4");
	CascadeClassifier face_classifier("haarcascade_frontalface_default.xml");
	CascadeClassifier eye_classifier("haarcascade_eye.xml");

	if (!video.isOpened()) {
		cerr << "Video open failed!" << endl;
	}

	if (face_classifier.empty() || eye_classifier.empty()) {
		cerr << "XML load failed!" << endl;
	}
	/*
	double fps = video.get(CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;
	int delay = cvRound(1000 / fps);
	*/
	
	Mat frame;
	while (true) {
		video >> frame;
		if (frame.empty())
			break;

		//imshow("frame", frame);
		vector<Rect> faces;
		face_classifier.detectMultiScale(frame, faces);

		for (Rect face : faces) {
			rectangle(frame, face, Scalar(255, 0, 255), 2);
			
			Mat faceROI = frame(face);
			vector<Rect> eyes;
			eye_classifier.detectMultiScale(faceROI, eyes);

			for (Rect eye : eyes) {
				Point center(eye.x + eye.width / 2, eye.y + eye.height / 2);
				circle(faceROI, center, eye.width / 2, Scalar(255, 0, 0), 2, LINE_AA);
			}
		}
		Mat dst;
		resize(frame, dst, Size(), 0.5, 0.5);
		imshow("src", dst);
		if (waitKey(1) != -1)
			break;
	}
	destroyAllWindows();
	//return 0;
}
// Mat video;      //이미지 처리를 위한 MAT 객체 생성
	/*video=imread("eye1.mp4");
	imshow("eye", video);
	img = imread("");
	if (video.empty()) {
	cerr << "Video load failed!" << endl;
	return -1;

	// 카메라 열때 사용
	//bool imwrite(const String & filename, InputArray img, const std::vector<int> & params = std::vector<int>());
	// bool VideoCapture::open(const String & filename, int apiPreference = CAP_ANY);
	// bool VideoCapture::isOpened()const;

	}*/
