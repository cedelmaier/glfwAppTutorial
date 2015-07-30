CXX = g++
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -I/usr/local/include
GLFW3LIBS = `pkg-config --static --libs glfw3` 
THREADS = -std=c++11

release: CXXFLAGS += -O3
release: example example_cursoranim

debug: CXXFLAGS += -O0
debug: example_cursoranim

example: example.o triangle.o square.o ball.o glfwApp.o
	$(CXX) example.o ball.o glfwApp.o -o example $(THREADS) $(GLFW3LIBS)

example_cursoranim: example_cursoranim.o  cursoranim.o glfwApp.o
	$(CXX) example_cursoranim.o cursoranim.o glfwApp.o -o cursoranim $(THREADS) $(GLFW3LIBS)

example.o: square.hpp glfwApp.hpp
	$(CXX) $(CXXFLAGS) -c example.cpp $(THREADS)

example_cursoranim.o: example_cursoranim.cpp
	$(CXX) $(CXXFLAGS) -c example_cursoranim.cpp $(THREADS)

glfwApp.o: glfwApp.hpp glfwApp.cpp
	$(CXX) $(CXXFLAGS) -c glfwApp.cpp $(THREADS)

triangle.o: triangle.hpp triangle.cpp glfwApp.hpp
	$(CXX) $(CXXFLAGS) -c triangle.cpp $(THREADS)

square.o: square.hpp square.cpp glfwApp.hpp
	    $(CXX) $(CXXFLAGS) -c square.cpp $(THREADS)

ball.o: ball.hpp ball.cpp glfwApp.hpp
	    $(CXX) $(CXXFLAGS) -c ball.cpp $(THREADS)

cursoranim.o: cursoranim.hpp cursoranim.cpp glfwApp.hpp
	$(CXX) $(CXXFLAGS) -c cursoranim.cpp $(THREADS)

clean:
	rm -f *.o example cursoranim

