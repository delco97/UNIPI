#!/bin/sh

echo "Runing tests..."
#loo through all in files
for f in *.in ; do
    echo "Processing $f file..";
    calcRes=$(time ../Debug/es3.4 < $f)
    #Check result using the related .out file
    filename=$(basename -- "$f")
    filename="${filename%.*}" #filename without extension
    expectedRes=$(cat ./$filename.out)
    if [ $calcRes!=$expectedRes ] ; then
        echo "OK"
    else
        echo "BAD"
        echo "  calculated result:"
		echo "    $calcRes"
        echo "  expected result:"
		echo "    $expectedRes"
    fi

done
