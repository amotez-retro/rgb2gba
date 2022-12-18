#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include <CImg.h>
using namespace cimg_library;


int rgbToHicolor(int r, int g, int b)
{
   return (((r >> 3) & 31) | (((g >> 3) & 31) << 5) | (((b >> 3) & 31) << 10));
}

int processImage(string dir, string imageName)
{
    CImg<unsigned char> src;
    src.load((dir+"/"+imageName).c_str());
    int width = src.width();
    int height = src.height();

    string arrayStr = "const unsigned bitmap" + imageName + "[19200]={"; 
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width-1; c+=2) {
            unsigned pixel1 = rgbToHicolor( (int)src(c,r,0,0), (int)src(c,r,0,1), (int)src(c,r,0,2) );
            unsigned pixel2 = rgbToHicolor( (int)src(c+1,r,0,0), (int)src(c+1,r,0,1), (int)src(c+1,r,0,2) );
            printf("0x");
            printf("%X%X,",pixel1,pixel2);
	    }
    }
    
    return 0;
}

int main(int argc, char** argv)
{
    vector<string> frameVector;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (argv[1])) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL) {
        //printf ("%s\n", ent->d_name);
        string frame = string(ent->d_name);
        frameVector.emplace_back(frame);
    }
    closedir (dir);
    } else {
    /* could not open directory */
    perror ("");
    return EXIT_FAILURE;
    }
    printf("int numFrames = %d;\n", (frameVector.size()-2));
    printf("const unsigned frames[%d][19200]={\n",(frameVector.size()-2));
    for (int i = 2; i < frameVector.size(); i++)
    {
        processImage(argv[1],frameVector[i]);
        printf("\n");
    }
    printf("};");

    return 0;
}
