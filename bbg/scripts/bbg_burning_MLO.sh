#!/bin/bash

#method1

mkimage -T omapimage -a 0x402F0400 -d led.bin MLO1


# method2
tiimage 0x402F0400    MMCSD   led.bin MLO

