#!/bin/bash
#################################################################
#   Copyright (C) 2024 xboard. All rights reserved.
#														  
#	B> File Name:        < dd_to_SDHC.sh >
#	> Author:           < 口袋物联 >		
#	> Mail:             < gjianw217@163.com >		
#	> Created Time:     < 2024/03/17 >
#	> Last Changed: 
#	> Description:	    ok210裸机.bin文件通过dd命令烧写到SD的BL1区域;
#################################################################



# 1. 指定SDHC在linux下的映射设备; 通过$ lsblk命令查看;

if [[ $EUID -ne 0 ]];then 
	echo you must have superuser permision
fi
if [ $# -ne 2 ];then
	echo usage: sudo $0  led.bin /dev/sdb
	exit -1
fi 

BinFile=$1
SDDevice=$2

# 2 
$(which gcc) -x c addheader -o mkbl1
./mkbl1 ${BinFile} ok210.bin

# 3
dd iflag=dsync oflag=dsync if=ok210.bin of=${SDDevice} seek=1
