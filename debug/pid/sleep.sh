CMDLINE=$0
export CMDLINE
export LINENO
get_current_time() {
   CURRENT_TIME=`date '+%m:%d:%y_%H:%M:%S'`
   echo "$CURRENT_TIME"
}
source hahahehe.sh

./a.out
./hahahehe.sh
