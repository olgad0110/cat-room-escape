# Cat room escape

Cat room is a mini game that allows you to program a cat that is inside a room. The goal is to leave the room.

## Tech demo

Demo for compiling and loading dynamic libraries (shared libraries on unix) during run time.

## Setup g++ and allegro

### OSX

Install Xcode for g++, install allegro via homebrew.
```bash
$ brew install allegro
```

### Linux (ubuntu/mint/raspbian)

Install required libs:

```bash
$ sudo add-apt-repository ppa:allegro/5.2
$ sudo apt-get update
$ sudo apt-get install g++
$ sudo apt-get install liballegro5-dev liballegro-image5-dev liballegro-dialog5-dev liballegro-audio5-dev liballegro-acodec5-dev
```

## Create and run release version

```bash
$ make BUILD=release RDIR=releases/alpha
$ releases/alpha/main
```

## Development

```bash
$ make
$ make clean
$ make help
```

## To do

* Compile and load dynamic library during run time
* Game loop
* Easy output and input (probably console)
* Easy option to reload dynamic library with ability to specify file name
* Extend cat class
* Room objects that cat can interact with
* Map containing room objects
* Access (restricted) to room objects and map from dynamic library
* Overwrite function (e.g. better path finding for cat) from main app inside dynamic library
