# Time-Lapse-Photo

Takes a time-lapse (any video will work really, but it's made for time-lapses) and turns it into a photo by taking a vertical strip from every few frames and layering them side by side together. It works especially well/looks best with day to night time-lapses. 

It's kinda an abstract concept, so I included an [example](https://github.com/chauandrew/Time-Lapse-Photo/blob/master/Example.gif), which produces this [photo](https://github.com/chauandrew/Time-Lapse-Photo/blob/master/ExamplePhoto.jpg) using this [time-lapse](https://www.videvo.net/video/day-to-night-time-lapse-lake-and-stars/2619/) as input. (I did NOT make this time-lapse)

### Getting Started

Run the .exe in command line. Use the given TimeLapsePhoto.exe file with one argument: the directory of a .mp4 or .mov file, for example:
```
C:\User\Videos TimeLapsePhoto cooltimelapse.mov
```
The photo will be saved as "video directory".jpg

### Building

If you want to build it from the main.cpp file, you'll need [opencv](https://opencv.org/releases.html) for C++. From there, you'll probably have to mess around with the include directory and everything else that accompanies using libraries. I won't get into it here because there's better documentation on the [openCV website](https://docs.opencv.org/master/df/d65/tutorial_table_of_content_introduction.html). 



Let me know if you have trouble with it, and thanks for taking the time to look through everything here!

-Andrew
