CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

Target = driver_program

SRCS = main.cpp \
       Address.cpp \
       Date.cpp \
       Driver.cpp \
       Database.cpp \
       LinkedList.cpp \
       Queue.cpp \
       Stack.cpp \
       HashTable.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(Target)

$(Target): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(Target) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(Target)