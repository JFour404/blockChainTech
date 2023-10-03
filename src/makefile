OPTIMIZATION_LEVELS := O3 O2 O1
DEFAULT_OPTIMIZATION_LEVEL := O3

$(info Prieinami optimizacijos lygiai: $(OPTIMIZATION_LEVELS))

ifdef OPT
ifeq ($(filter $(OPT),$(OPTIMIZATION_LEVELS)),)
$(error Neinkamas optimizacijos lygis: $(OPT))
endif
OPTIMIZATION_LEVEL := $(OPT)
else
OPTIMIZATION_LEVEL := $(DEFAULT_OPTIMIZATION_LEVEL)
endif

CXXFLAGS := -$(OPTIMIZATION_LEVEL)

main: funkcijos.o hashF.o test.o sha256.o
	g++ $(CXXFLAGS) -o program main.cpp funkcijos.o hashF.o test.o sha256.o -lcrypto


funkcijos.o: funkcijos.cpp
	g++ $(CXXFLAGS) -c funkcijos.cpp

hashF.o: hashF.cpp
	g++ $(CXXFLAGS) -c hashF.cpp

test.o: test.cpp
	g++ $(CXXFLAGS) -c test.cpp

sha256.o: sha256.cpp
	g++ $(CXXFLAGS) -c sha256.cpp

clean:
	del -f *.o *.exe