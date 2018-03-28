# Time-Lapse-Photo

Takes a time lapse (any video will work really, but it's made for time lapses) and turns it into a photo by taking a vertical strip from every few frames and layering them side by side together. It works especially well/looks best with day to night time lapses. 

It's kinda an abstract concept, so I included an [ExamplePhoto](https://github.com/chauandrew/Time-Lapse-Photo/blob/master/ExamplePhoto.jpg), which was made from this [time lapse](https://www.videvo.net/video/day-to-night-time-lapse-lake-and-stars/2619/). (I did NOT make this timelapse)

### Getting Started

Run this in command line. Use the given TimeLapsePhoto.exe file with one argument: the directory of a .mp4 or .mov file, for example:
```
C:\Your\Directory\Here TimeLapsePhoto ..\..\..\Videos\cooltimelapse.mov
```
The photo will be saved as "video directory".jpg

### Building

If you want to build it from the main.cpp file, you'll need [opencv](https://opencv.org/releases.html) for C++. From there, you'll probably have to mess around with the include directory and everything else that accompanies using libraries. I won't get into it here. 



Hopefully it's all pretty straightforward! Let me know if you have trouble with it, and thanks for taking the time to look through everything here!

-Andrew
