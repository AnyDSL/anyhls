#include <iostream>
#include <anydsl_runtime.hpp>

template<typename T>
void print_pixel(T pix) { std::cout<< int(pix); }

template<>
void print_pixel<float>(float pix) { printf("%15.2f", pix); }

template<typename T>
void displayFrame(T* frame, int stride, const int width, const int height,
                  const int offset_x=0, const int offset_y=0){
    for (int y=0; y<height; ++y) {
        for (int x=0; x<width; ++x) {
            print_pixel(frame[(y+offset_y)*stride + offset_x + x]);
            std::cout << " \t ";
        }
        std::cout<<std::endl;
    }
}

//typedef ANYHLS_DATA_TYPE pixel_t;
typedef int pixel_t;
extern "C" void harris_corner(pixel_t*, pixel_t*);

/*************************************************************************
 * Main function                                                         *
 *************************************************************************/
int main(int argc, const char **argv) {
    size_t width  = 1024;
    size_t stride = 1024;
    size_t height = 1024;

    // host memory for image of width x height pixels
    // use anydsl::Array from AnyDSL runtime for memory allocation
    anydsl::Array<pixel_t>  input(width * height);
    anydsl::Array<pixel_t> output(width * height);

    // initialize data
    for (size_t j = 0; j < height; ++j) {
        for (size_t i = 0; i < width; ++i) {
            input[j * stride + i] = static_cast <uint8_t> ( ((((i%16)>=8) & ((j%16)<8)) | (((i%16)<8) & ((j%16)>=8))) ==0 ? 255 : 0);
        }
    }

    harris_corner(input.data(), output.data());

    // Print Output
    int pOfX= 0; //width-20;
    int pOfY= 0; //height-10;
    printf("Input \n"); displayFrame(input.data(),  stride, 16, 16, pOfX, pOfY);
    printf("Output\n"); displayFrame(output.data(), stride, 16, 16, pOfX, pOfY);

    return EXIT_SUCCESS;
}
