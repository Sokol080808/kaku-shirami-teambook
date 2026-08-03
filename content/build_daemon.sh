while true  
do  
    cd ..
    git pull
    cd content
    oj-verify run
    ./build.sh
    sleep 60
done

