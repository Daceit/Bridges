#ifndef IMAGE_H 

#define IMAGE_H 1

#include <iostream>
#include <string>
#include <fstream>

#include "Bridges.h"
#include "ColorGrid.h"

using namespace bridges;
using namespace std;

class Image {
	private:
        // image dimensions
		int width, height, maxVal;

        // pointer to the dynamically allocated image array
		int *image_array;

		// you will need an array to hold the processed results
		int *processed_array;

	public:
		// constructor - creates an empty image object,
		Image(int nW, int nH,int nV, int *nIa,int *nPa) : width(nW), height(nH),maxVal(nV), image_array(nIa),processed_array(nPa)  {
		}
        // creates an image object by reading the input image
		Image(string input_file){
		};
        //creates an image object using the given dimensions
		Image(int width, int height) {
		}

		// destructor
		~Image() { 
		}
        // TO DO: you might need setters/getters for accessing data items,
		// image pixel, etc

		// reads an image from  the given input image file
		void read(string file_name) {
		}

		// writes image to the Bridges colorgrid for visualization
		void setColorGrid (ColorGrid& cg) {
		}

		// convert to grayscale
		void toGrayscale () {
		}
		// flip image horizontally
		void flipHorizontal() {
		}

		// remove the blue component
		void flattenBlue() {
		}

		// use the complement of red (wraparound)
		void negateRed() {
		}

		// reads a new image and blends with existing image
		void blend (string file_name, float blend_factor) {
		}
};

#endif
