CXX=g++
CXXFLAGS=-Wall -Wextra -g -O0 -std=c++11
BOOST_INCLUDE_PATH=/usr/include/boost
BOOST_LIB_PATH=/usr/lib/x86_64-linux-gnu
PTHREAD_LIB_PATH=/lib/x86_64

INCLUDE_PATH=/opt/rpi-micromanager/micro-manager/MMCore
LIB_PATH=/opt/rpi-micromanager/build/lib/micro-manager
LIBMMCORE=MMCore

MKDIR_P=mkdir -p
BIN_PATH=bin
TARGET="$(BIN_PATH)/main"

#---------------------------------------------------------------------
# Rules
#---------------------------------------------------------------------
.PHONY: all bin_path

all: bin_path $(TARGET)

bin_path: $(BIN_PATH)

$(BIN_PATH):
	$(MKDIR_P) $@

$(TARGET): src/main.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_PATH) $^ -L$(LIB_PATH) -l$(LIBMMCORE) -L$(BOOST_LIB_PATH) -lboost_system -lboost_thread -lboost_date_time -L$(PTHREAD_LIB_PATH) -lpthread -ldl -o $@

clean:
	rm -rf $(BIN_PATH)
