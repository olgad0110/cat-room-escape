# Cat room escape

Cat room is a mini game that allows you to program a cat that is inside a room. The goal is to leave the room.

## Tech demo

Demo for compiling and loading dynamic libraries (shared libraries on unix) during run time.

## Running

```bash
$ bin/main
```

Note: You need to have `g++` command available and working to run the demo.

## Development

```bash
$ make
```
Note: You need to have `g++` command available and working to compile the demo.

## To do

* ~~Compile and load dynamic library during run time~~
* Game loop
* Easy output and input (probably console)
* Easy option to reload dynamic library with ability to specify file name
* Extend cat class
* Room objects that cat can interact with
* Map containing room objects
* Access (restricted) to room objects and map from dynamic library
* Overwrite function (e.g. better path finding for cat) from main app inside dynamic library
