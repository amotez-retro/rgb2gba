# rgb2gba
A program to convert a directory of rgb images to an array of frames which is compatible with gba to be directly loaded in VRAM.
This is mostly to be used in conjunction with the other repo to convert regular bitmaps to 15 bit formatted

To compile, use the `make` command from the rgb2gba directory

To use: `rgb2gba <directory with images to convert to gba color> `

The output will be in frames.h as an array as well as an int for the number of frames
