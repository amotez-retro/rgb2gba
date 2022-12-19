# rgb2gba
A program to convert a directory of rgb images to a gba formatted array of frames.
This is mostly to be used in conjunction with the other repo to convert regular bitmaps to 15 bit formatted

To compile, use the `make` command from the rgb2gba directory

To use: `rgb2gba <directory with images to convert to gba color> `

The output will be in frames.h as an array as well as an int for the number of frames
