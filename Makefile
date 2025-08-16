build:
	g++ -Wall -std=c++17 src/*.cpp -I"./libs/" -lSDL2 -llua -o game-engine

	# -Wall for show warning
	# -lSDL2 for linking SDL2
	# -"./libs/" is linking everthing in libs folder

run:
	./game-engine

clean: 
	rm ./game-engine


