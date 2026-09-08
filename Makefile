CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g
DEPFLAGS := -MMD -MP

OBJECTS := Competition.o Game.o GameScore.o Match.o MatchScore.o Player.o \
           PointScore.o Score.o Set.o SetScore.o TieBreaker.o \
           TieBreakerScore.o main.o
DEPENDENCIES := $(OBJECTS:.o=.d)

tennis.x: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPENDENCIES)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(DEPENDENCIES) tennis.x
