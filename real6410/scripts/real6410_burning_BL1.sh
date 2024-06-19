#!/bin/bash
#################################################################
#   Copyright (C) 2024 xboard. All rights reserved.
#														  
#	B> File Name:        < dd_to_SDHC.sh >
#	> Author:           < 口袋物联 >		
#	> Mail:             < gjianw217@163.com >		
#	> Created Time:     < 2024/03/17 >
#	> Last Changed: 
#	> Description:	    real6410l裸机.bin文件通过dd命令烧写到SDHC的BL1区域;
#################################################################



# 1. 指定SDHC在linux下的映射设备; 通过$ lsblk命令查看;

if [[ $EUID -ne 0 ]];then 
	echo you must have superuser permision
fi
if [ $# -ne 2 ];then
	echo usage: sudo $0 /dev/sdb led.bin
	exit -1
fi 


dev_SDHC=$1
bin_file=$2

echo 'SDHC ->' $dev_SDHC
echo "-------------- lsblk $dev_SDHC--------------"
lsblk | grep `basename $dev_SDHC`
echo '-------------------------------------------'

# 2. 通过fdisk查看SDHC的大小;
echo '[WARNING] fdisk, need sudoer authority'
echo "-------------- fdisk $dev_SDHC--------------"
#sudo fdisk -l | grep "Disk $dev_SDHC"
fdisk_string=`sudo fdisk -l | grep "Disk $dev_SDHC"` 
echo $fdisk_string
if [ -z "$fdisk_string" ]; then
	echo "Error! Can't find Device $dev_SDHC" 
	exit
fi

# eg. 
#Disk /dev/sdb: 7.3 GiB, 7822376960 bytes, 15278080 sectors

echo '-------------------------------------------'

# 3. 计算SDHC的BL的起始位置 = 总字节数 - ($Reserved_Bytes + 1 + 16)*512;
TwoG_Bytes=2147483648 #2*1024*1024*1024
ALL_Bytes=`echo $fdisk_string | cut -d ' ' -f 5`
echo "All_Bytes:$ALL_Bytes"

if [ $ALL_Bytes -gt $TwoG_Bytes ];then
Reserved_Bytes=1025
else
Reserved_Bytes=1
fi
echo "SDHC BL1 = (All_Bytes - ($Reserved_Bytes + 1 + 16)*512)"

BL1_Start_Byte=`echo "($ALL_Bytes-($Reserved_Bytes + 1 + 16)*512)" | bc`
echo "BL1 Start Bytes:$BL1_Start_Byte"
echo '-------------------------------------------'

#4. 通过dd将$bin_file烧写到$dev_SDHC中
echo "-------------- dd $dev_SDHC--------------"
echo "dd $bin_file to SDHC($dev_SDHC)"
echo "sudo dd if=$bin_file of=$dev_SDHC seek=$BL1_Start_Byte bs=1"
sudo dd if=$bin_file of=$dev_SDHC seek=$BL1_Start_Byte bs=1
