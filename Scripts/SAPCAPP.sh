#/bin/bash -e

max=1
counter=5o

while [ $counter -gt $max ]
do
  echo "Hello dear friend I gonna sleep a feel seconds"
  sleep 1
  counter=$(($counter-1))
done

echo Finish program with count equal to $counter
echo The baseName is:$(`basename{}`)
#while [ $i -lt 4 ]
#do
#xterm &
#i=$[$i+1]
#done
