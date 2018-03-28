#include <string>
#include <opencv2/opencv.hpp>

unsigned int countFrames(const std::string& sourcefilename, int& nRows, int& nCols);
cv::Mat getImage(const std::string& sourcefilename);

int main(int argc, char** argv)
{
	// check to make sure that we're given proper input
	if (argc != 2) return -1;
	char* filename = argv[1];
	cv::Mat image;
	cv::VideoCapture temp(filename);
	temp.read(image);	
	if (image.empty()){
		printf("Could not find the video at the specified address \n ");
		return -1;
	}

	// get the image, write it to disc, and keep the window open for a little bit
	std::string outputName = argv[1];
	outputName += ".jpg";
	image = getImage(filename);
	imwrite(outputName, image);
	cv::waitKey(1000);
	return 0;
}

// takes a video file as input and returns a Mat file that takes a few pixels from
// each frame of the video
cv::Mat getImage(const std::string& sourcefilename)
{
	int nFrames, height, width, stripWidth, nFramesToSkip(1), extraPixels, extraPixelFreq;
	cv::Mat currFrame;
	nFrames = countFrames(sourcefilename, height, width);
	if (nFrames == -1) return currFrame;	// if we didn't find the video, return empty Mat

	// First, make sure we don't have more frames than our desired resolution, width must be greater than nframes
	// Then, we have to figure out the width of each strip - difficult because we can't split pixels in pieces
	// On the (very) rare chance that it fits perfectly, stripWidth = width / nFrames.
	// Regardless of how we split up leftover pixels, we will have nFrames number of different strips
	// We split leftover pixels evenly across strips by making certain strips 1 pizel larger
	if (nFrames > width){
		nFramesToSkip = nFrames / width;
		nFrames %= width;
	}
	stripWidth = width / nFrames;
	extraPixels = width % nFrames;
	extraPixelFreq = nFrames / extraPixels;

	// Now, we actually go through the video and create the new Mat object from it
	// We loop through the frames in the video and also our mat object, adding to it from left to right
	// For each frame processed, we first move to the proper frame of the video
	// Then, we copy a certain amount of pixels from the video to the Mat object.
	// Also, just for visual effect, we show the video/photo windows as the photo is being made 
	cv::namedWindow("timelapsephoto", cv::WINDOW_NORMAL);
	cv::namedWindow("video", cv::WINDOW_NORMAL);
	cv::Mat finalImage(height, width, CV_8UC(3));
	cv::VideoCapture video(sourcefilename);		// don't have to check if its a valid file b/c we wouldn't make it here unless it's valid
	int currX = 0;
	for (int i = 0; i < nFrames; ++i){
		// move to the frame of the video we want to process, if we get to the end of the video, return what we have so far
		for (int j = 0; j < nFramesToSkip; ++j)
			if (!video.read(currFrame)) return finalImage;
		// every few strips, we add one extra pixel by making the count start at -1 instead of 0. 
		int pixelCount = 0;
		if (i % extraPixelFreq == 0)  pixelCount--;

		// add a strip of pixels from the current frame to the final image
		for (; pixelCount < stripWidth; ++pixelCount){
			if (currX == width) return finalImage;	// if we hit the end of our image, return it
			// go through the entire height of the frame, copying over a line one pixel wide 
			for (int k = 0; k < height; ++k){
				cv::Vec3b currPixel = currFrame.at<cv::Vec3b>(k, currX);
				finalImage.at<cv::Vec3b>(k, currX) = currPixel;
			}
			currX++;
		}
		cv::imshow("video", currFrame);
		cv::imshow("timelapsephoto", finalImage);
		cv::waitKey(1);
	}
	return finalImage;	// once we finish, return the final image
}

// return the number of frames a video file has and updates nRows and nCols to the 
// number of rows/cols that a frame of the video has. Returns -1 for invalid sourcefile
unsigned int countFrames(const std::string& sourcefilename, int& nRows, int& nCols)
{
	int nFrames(1);		// nFrames starts at 1 because we process first frame of video before starting the counter
	cv::Mat currFrame;
	cv::VideoCapture tempCounter(sourcefilename);
	tempCounter.read(currFrame);	// process first frame of video, holding onto its image resolution and number of frames
	if (currFrame.empty()) return -1;	// if cannot find video, return -1
	nRows = currFrame.rows;						// otherwise, keep track of the pixel size of the video
	nCols = currFrame.cols;
	while (tempCounter.read(currFrame))	// keep track of each frame of the video
		++nFrames;
	return nFrames;
}