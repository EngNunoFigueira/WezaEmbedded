#!/bin/bash

echo 'This a testing example to remember me how use the switch-case in bash'

echo The number o parameters is $#
echo $@ | grep "OnSanityCheck"

if [ $? -eq 0 ]; then
{
   echo "Running in Sanity Check Mode"
}     
else
{
   echo "Running in Normal Mode....."
}  
fi

echo "Testing programming ending..."

