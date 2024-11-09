1: clean
	g++ g++ -Wall -std=c++11 main.cpp -o 1_Main
	./1_Main
clean:
	@rm -f 1_Main