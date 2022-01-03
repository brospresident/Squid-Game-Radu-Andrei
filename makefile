build: main.cpp
	g++ -o User.o -c ./User/User.cpp
	g++ -o Supervisor.o -c ./User/Supervisor.cpp
	g++ -o Competitor.o -c ./User/Competitor.cpp
	g++ -o Generator.o -c ./Generator/Generator.cpp
	g++ -o FileReader.o -c ./FileReader/FileReader.cpp
	g++ -o NamesReader.o -c ./FileReader/NamesReader.cpp
	g++ -o CityReader.o -c ./FileReader/CityReader.cpp
	g++ -o UserManager.o -c ./UserManager/UserManager.cpp
	g++ -o Team.o -c ./Teams/Team.cpp
	g++ -o Circle.o -c ./Teams/Circle.cpp
	g++ -o Rectangle.o -c ./Teams/Rectangle.cpp
	g++ -o Triangle.o -c ./Teams/Triangle.cpp
	g++ -o Game.o -c ./Games/Game.cpp
	g++ -o RLGL.o -c ./Games/RLGL.cpp
	g++ -o TugOfWar.o -c ./Games/TugOfWar.cpp
	g++ -o Marbles.o -c ./Games/Marbles.cpp
	g++ -o Genken.o -c ./Games/Genken.cpp
	g++ -o main.o -c main.cpp
	g++ -o mainApp main.o User.o Supervisor.o Competitor.o Generator.o FileReader.o NamesReader.o CityReader.o UserManager.o Team.o Circle.o Rectangle.o Triangle.o Game.o RLGL.o TugOfWar.o Marbles.o Genken.o
	rm -rf main.o Generator.o User.o Supervisor.o Competitor.o FileReader.o NamesReader.o CityReader.o UserManager.o Team.o Circle.o Rectangle.o Triangle.o RLGL.o Game.o TugOfWar.o Marbles.o Genken.o

run:
	./mainApp

clear:
	rm -f main