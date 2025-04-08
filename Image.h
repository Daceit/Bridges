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

		// you will need an arrayaaa to hold the processed results
		int *processed_array;

	public:
		// constructor - creates an empty image object,
		Image(int nW, int nH,int nV, int *nIa,int *nPa) : width(nW), height(nH),maxVal(nV), image_array(nIa),processed_array(nPa)  {
		}
        // creates an image object by reading the input image
		Image(string input_file){

		}
        //creates an image object using the given dimensions
		Image(int width, int height) {
		}

		// destructor
		~Image() { 
		}
        // TO DO: you might need setters/getters for accessing data items,
		// image pixel, etc
		int getWidth() const { return width; }
		int getHeight() const { return height; }

		// reads an image from  the given input image file
		void read(string file_name) {
		ifstream infile(file_name);
		if (!infile){
			cerr << "Error: Cant Read File." << endl;
			return;
		}
		
		infile >> width >> height >> maxVal;
		image_array = new int [width * height * 3];

		for (int i = 0; i < width * height * 3; ++i){
			infile >> image_array[i];	
		}
		}
		// writes image to the Bridges colorgrid for visualization
		void setColorGrid (ColorGrid& cg) {
			for (int row = 0; row < height; ++row){
				for (int col = 0; col < width; ++col){
					int idx =  (row * width + col) * 3;
					int r = image_array[idx];
					int g = image_array[idx + 1];
					int b = image_array[idx + 2];
					cg.set(row, col, Color(r, g, b));
			}
		}
	}

		// convert to grayscale
		void toGrayscale () {
			for (int i = 0; i < width * height; ++i) {
				int idx = i * 3;
				int r = image_array[idx];
				int g = image_array[idx + 1];
				int b = image_array[idx + 2];
				int gray = (r + g + b) / 3;
				image_array[idx] = gray;
				image_array[idx + 1] = gray;
				image_array[idx + 2] = gray;
		}
	}
		// flip image horizontally
		void flipHorizontal() {
			for (int row = 0; row < height; ++row) {
				for (int col = 0; col < width / 2; ++col) {
					int left_idx = (row * width + col) * 3;
					int right_idx = (row * width + (width - 1 - col)) * 3;
					for (int k = 0; k < 3; ++k) {
						swap(image_array[left_idx + k], image_array[right_idx + k]);
					}
			}	
	}
		}
		// remove the blue component
		void flattenBlue() {
			for (int i = 0; i < width * height; ++i) {
				int idx = i * 3;

				image_array[idx + 2] = 0;
		}

		}

		// use the complement of red (wraparound)
		void negateRed() {
			for (int i = 0; i < width * height; ++i) {
			int idx = i * 3;

			 image_array[idx] -= 255;

		     image_array[idx] * -1;

		}
		}
		// reads a new image and blends with existing image
		void blend (string file_name, float blend_factor) {
			read (file_name);

			}
		
};

#endif
