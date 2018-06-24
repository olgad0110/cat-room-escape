# Cat room escape

Cat room is a mini game that allows you to program a cat that is inside a room.

## Tech demo

Demo for compiling and loading dynamic libraries (shared libraries on unix) during run time.

Current versions:
* [console with recompiling](https://github.com/ardhena/cat-room-escape/tree/console)
* [2d map with allegro, without recompiling](https://github.com/ardhena/cat-room-escape/tree/master)
* [isometric map with allegro, without recompiling, not finished](https://github.com/ardhena/cat-room-escape/tree/isometric-map)

For proper tech demo use [console](https://github.com/ardhena/cat-room-escape/tree/console) branch.

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
