cbits
=====

A C++ helper class to check/set on a defined DWORD struct in which images on an image sequence a (ground) point exists.<br>

## Description

A ground point (or an object point) may be captured or presented in multiple images if those images are highly overlapped. The figure below illustrates a ground point exists on multiple images. 

![Ground object on multiple image](https://github.com/stanathong/cbits/blob/master/Image%201%20-%20Ground%20object%20on%20multiple%20images.jpg)

For some situations, we need to know in which images a ground point exists. Bundle adjustment algorithm, for example, involves a large number of image matches, object points, and camera parameters of all images in the dataset. Below is a picture of a file containing a list of image matches - saying on which image ID, an object point (mentioned by ID) shows up and at which (x,y) coordinate. The file contains the whole image points in the sequence. The structure of each point composes of ‘Image ID’, ‘Object ID’, ‘Image point (x,y)’. The ‘Object ID’ of one image is usually duplicated along the adjacent images as its corresponding image point shares the same object point. 

![Image ID](https://github.com/stanathong/cbits/blob/master/Image%202%20-%20Image%20ID.jpg)

To record that which object ID is in which image ID, we can simply use a vector of std::set.

```
Object ID: 1 --> Image ID: {1, 2, 3, 4}
Object ID: 2 --> Image ID: {1, 2, 3, 4, 5}
Object ID: 3 --> Image ID: {2, 3, 4, 5}
```

But, that consumes a huge memory as long as the sets and the number of object ID go bigger. In my work (particularly, image matching), I have created CBits class that uses each bit in DWORD to represent each image ID. Thus, instead of having a vector of std::set, we use a vector of CBits to store the relationship between Object ID and a list of image ID. This is presented as the image below: 

![Relationship between Object and Image Points](https://github.com/stanathong/cbits/blob/master/Image%203%20-%20Relationship%20between%20Object%20ID%20and%20Image%20ID.jpg)

If the object point exists in an image, the bit value of that image index is marked as 1. Otherwise, it is marked as 0. The structure of DWORD_BITS is simply 4 DWORDs, in which each DWORD defines different range of bits. 

![DWORD_BITS structure](https://github.com/stanathong/cbits/blob/master/Image%204%20-%20Structure%20of%20DWORD_BITS.jpg)
