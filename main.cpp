#include <iostream>

#include<icpasz/p2picp/vanillaricp.h>

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    
#ifdef FUNC_USE_SAVE_MAP
    std::cout<<"use map"<<std::endl;
#endif
    return 0;
}
