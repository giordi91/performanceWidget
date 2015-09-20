performanceWidget
=================
WARNING: THis is an old and most likely crappy project, brace yourself you brave coder that dares to enter

This is a small library I wrote in order to create some "performance" widgets.
What I mean by that is a series of widgets that can show computer performance, like ram usage , CPU usage etc.
I tried to build the library in a way which is a bit flexible and modular and adapt to different type of data.
Beware though this is not a library for data plotting, there are a lot of professional libraries out there to do that.

This library doesn't have any external dependency (Other than Qt itself) and is self contained.
At this point it only work on Linux since it relies on a /proc/stat file  and other Linux specific query.
There will be need to modify the classes to work differently on a OSX or Windows environment.

If you want to read the documentation you can do it here :
http://giordi91.github.io/index.html


Feel free to contact me for any advice or error report etc.( I am sure there are massive amount of typos and English errors).
marco(dot)giordano(dot)work(at)gmail(dot)com

##### IMAGES ######

Cpu-ram

![Alt cpu-ram](/doc/images/demoWidget.png)

Bar-painter

![Alt bar-painter](/doc/images/performanceSingleBar.png)

Graph-painter 

![Alt graph-painter](/doc/images/performanceSingleGraph.png)

Graph-painter2 

![Alt graph-painter2](/doc/images/performanceMultiColorGraph.png)
