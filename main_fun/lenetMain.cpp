#include "common.hpp"
#include "convolution.hpp"
#include "io.hpp"
#include "pooling.hpp"

void LenetArch(string image, string ker_l1, string ker_l2, string ker_l3, string ker_l4);

int main(int argc, char **argv){
    string ch1 = argv[1];
    string out_folder = "weights/";
    string ch2 = out_folder + "conv1.txt";
    string ch3 = out_folder + "conv2.txt";
    string ch4 = out_folder + "fc1.txt";
    string ch5 = out_folder + "fc2.txt";
    LenetArch(ch1, ch2, ch3, ch4, ch5);

    return 0;
}