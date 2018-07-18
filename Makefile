SRC = try_google_test_framework_test.cpp try_google_test_framework_tobetest.cpp
OBJS = try_google_test_framework_test.o  try_google_test_framework_tobetest.o
CFLAGS = -std=c++17
LIBS = -pthread  ~/workspace/cpp/libgtest.a
INC = -isystem /usr/local/include/gtest/

all: $(OBJS)
        g++ $(CFLAGS) $(INC) $(LIBS) $(SRC) -o $(OBJS)


try_google_test_framework_tobetest.o: try_google_test_framework_tobetest.cpp
        g++ -c try_google_test_framework_tobetest.cpp -o try_google_test_framework_tobetest.o

try_google_test_framework_test.o: try_google_test_framework_test.cpp
        g++ -c try_google_test_framework_test.cpp -o try_google_test_framework_test.o $(INC)

.PHONY: clean

clean:
        rm -f *.o *.exe
