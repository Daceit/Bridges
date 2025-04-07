#include "Image.h"

using namespace bridges;

int main() {

	Bridges bridges(1,"Madzilla23", "16463411788"3);

	bridges.setTitle("Image Processing");
	bridges.setDescription("Students are provided with sample images in a simple text format that they read and display using the ColorGrid datatype.");
	//TODO: the main program where you call various image processing
	// operations.
	Image img(IMG_8464.ppm);

	img.toGrayscale();

	img.negateRed();

	img.flipHorizontal();

	return 0;
}

