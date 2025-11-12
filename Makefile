CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
PRACTICES = practice1 practice2 practice3 practice4 practice5 practice6 practice7
all: $(PRACTICES)
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
.PHONY: clean
clean:
	rm -f $(PRACTICES)
