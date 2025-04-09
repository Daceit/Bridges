#include "Image.h"

using namespace bridges;
int main() {

	Bridges bridges(1, "Madzilla23", "604801690376" );
	bridges.setTitle("Image Processing");
	bridges.setDescription("Students are provided with sample images in a simple text format that they read and display using the ColorGrid datatype.");
	ColorGrid *cg = new ColorGrid();


	
		//TODO: the main program where you call various image processing
	// operations.
	Image img("IMG_8464.ppm");

	img.toGrayscale();
	img.negateRed();
	img.flipHorizontal();
	img.setColorGrid(*cg);
	bridges.setDataStructure(*cg);
	bridges.visualize();
	return 0;
}

