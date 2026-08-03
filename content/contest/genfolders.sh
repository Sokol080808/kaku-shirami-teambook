chmod +x bld*
for f in {A..Z}
do
    mkdir $f
    cp main.cpp bld* $f
done
