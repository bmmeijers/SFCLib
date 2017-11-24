# SFCLib

SFCLib: an efficient and scalable space-filling curve library for nD point cloud management.

- Multi dimensions support (xyt, xyz, xyzt, xyzi, ...) ;
- Multi SFC encoding schema (value, hashstring, ...);
- Multi query support and integration of different databases;
- Scalability for massive point datasets.
- Performance experiments on LiDAR point cloud, GPS trajectory data, ...


# Installation

Build with Visual Studio, CodeBlocks or use CMake.

## Using cmake

Inside the source distribution folder, run in a shell:

    $ rm -rf ./build
    $ mkdir ./build
    $ cd ./build
    $ cmake ..
    $ make -j4 VERBOSE=1

To install the tools system wide:

    $ sudo make install

The 3 command line tools now should be installed to /usr/local/bin/


# Command line tools

## sfcgen

Encode nD points to a SFC key.

### Command line arguments

- **-p** Sequential or parallel mode (i.e., 0: sequential or 1: parallel).
- **-s** SFC type, Morton or Hilbert (i.e., 0: morton or 1: hilbert).
- **-e** Encoding type, Number value, or Base32 string, or Base64 string (i.e., 0: number, 1: base32, 2: base64).
- **-t** Coordinate transform file (one line for translation, one line for scale, comma separated in each dimension), default, if no transform file is given, is 0 for translation and 1 for scaling respectively.
- **-l** The total LOD levels (i.e, 0~ L-1).
- **-i** and **-o** The input file and output file. Note, the SFCGen tool also support command PIPE input and PIPE output if no -i or -o is specified. So it can be integrated with other existing tools, e.g. LASTools or Oracle's SQLLoader by using pipes.
- **-onlysfc** Only output the SFC code, no dimensional coordinates.
- **-n** Number of points in a chunk during parallel SFC generation, the default is 5000.

### Example usage

Only using sfcgen:

    $ sfcgen -p 0 -s 1 -e 2 -t ct.txt -l 10 -i ahn2.txt -o ee.txt -onlysfc -n 5000

Piping output of las2txt as input for sfcgen:

    $ las2txt -i /var/tmp/data/0020/ahn_bench000020.las -stdout -parse xyz -sep comma | sfcgen -p 0 -s 1 -e 0 -t /var/tmp/data/0020/ct.txt -l 10 


## sfcdecode

Decode a SFC key to nD points.


## sfcquery

Produce set of ranges for query geometry (nD box).

### Command line arguments

- **-i** defines the input filter, format: x0/x1/y0/y1/z0/z1/.../...
- **-s**, **-e**, **-t** same as sfcgen's arguments (SFC type, Encoding type, Coordinate transform file)
- **-o** means the output ranges file
- **-n** defines the generated ranges number (exactly around)

### Example usage

Producing some ranges in the qq3.sql output file.

    $ sfcquery -i 85999.0/85999.5/446266/446266.5/-2.0/-1.5/8/9 -s 1 -e 0 -t ct.txt -n 1000 -o qq3.sql


