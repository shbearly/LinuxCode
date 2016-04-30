
date >> ./start_time.log

times=0

while [ 1 ]
do

rm -rf download.php* index.html*

wget -nv -a ./wget_run.log http://dl.client.baidu.com/download.php?source=/ime/BaiduPinyinSetup.exe

if(($?!=0)) 
then
	echo "download return error:$?"
	date >> ./end_time.log
        echo "there already running $times times" >> end_time.log
#	exit
        sleep 600
fi

wget -nv -a ./wget_run.log www.sina.com.cn

if(($?!=0)) 
then
	echo "getweb return error:$?"
	date >> ./end_time.log
        echo "there already running $times times" >> end_time.log
#	exit
        sleep 600
fi
	times=`expr $times + 1`

sleep 30


done
