#!/bin/bash

#脚本作用:提交当前目录下,所有可执行的c代码程序,即除了.c文件外的其他文件

for file in `ls ./`
do
	flag=`echo $file | awk 'BEGIN {FS = "."} { if (($2 ~ /[0-9]/) && ($3 != "c")) {print 1} else {print 0} }'`
	if [ $flag -eq 1 ]; then
		git add $file
	fi
done



