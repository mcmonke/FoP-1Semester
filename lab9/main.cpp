#include <iostream>
#include <string.h>
#include "modes.cpp"
using namespace std;

const int max_size = 100;
Dictionary dict[max_size];
int num_w = 0;	

int main(int argc, char *argv[]) {
    bool isInteractive = false;

    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive) {
        return interactive(dict,  num_w);
    } else {
        return demo(dict,  num_w);
    }
}
