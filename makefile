all:
	g++ driver.cpp Threads.cpp -o player -lpthread
run: all
    ./player
