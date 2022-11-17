# lab2B-part04
## TODO:

Update your sequencer to be able to slow down and speed up recordings/replay. On the input side, the goal is ultimately to be able to handle the full 4 Gbps "firehose" from the PIO logic analyzer example in the SDK manual, which would fill up 256Kb of RAM in only 31 µs at a system clock speed of 125000 MHz if captured 'raw'! On the output side, the goal is to be able to output precisely timed sequences from the PIO at system clock resolution based on a handful of control points.

update your sequencer to be able to record just the timestamped transitions between input values, and to be able to play data in this format
give your sequencer the ability to select a range of output rates for both live and recorded input

## In order to reach these functions, we have these codes:
1. the [bootpress.c](https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/code/bootpress.c) for 3 functions: record, replay and loopplay
2. the [data_transfer.c](https://github.com/xcyxcyxcyxcy/lab2B-part04/blob/main/code/data_transfer.c) for encoding and decoding
3. the [neopixel.c](https://github.com/xcyxcyxcyxcy/lab2B-part04/blob/main/code/neopixel.c)
4. the [speed.c](https://github.com/xcyxcyxcyxcy/lab2B-part04/blob/main/code/speed.c) for realizing the whole functions which are requested.

## Results:
#### Record speed=1:

<div align=center><img width="500" height="700" src="https://github.com/xcyxcyxcyxcy/lab2B-part04/blob/main/speed%3D1%20record.gif"/></div>

#### Replay:
a. speed=1:<div align=center><img width="500" height="700" src="https://github.com/xcyxcyxcyxcy/lab2B-part04/blob/main/speed%3D1%20replay.gif"/></div>

b. speed=1/4:<div align=center><img width="500" height="700" src="https://github.com/xcyxcyxcyxcy/lab2B-part04/blob/main/speed%3D1%3A4%20replay.gif"/></div>

c. speed=4:<div align=center><img width="500" height="700" src="https://github.com/xcyxcyxcyxcy/lab2B-part04/blob/main/speed%3D4.gif"/></div>

We have done tests for all speeds which are included in our code and also have done some tests for loop playing, it works well!

