CC = g++

LD = ld

CXXFLAGS = -std=c++11 -DUSE_OPENCV -DNO_NVML

IFLAGS += `pkg-config opencv --cflags`
LFLAGS += `pkg-config opencv --libs`

IFLAGS += -I $(CAFFE_HOME)/include -I $(CAFFE_HOME)/build/src/ -I /usr/local/cuda/include
LFLAGS += -L $(CAFFE_HOME)/build/lib -lcaffe \
		-L /usr/local/cuda/lib64 -lglog -lprotobuf -L/usr/local/lib \
		-lboost_thread-mt -lrt -lboost_signals -lboost_system \
	
all: mscnn-test

mscnn-test: mscnn-test.o Mscnn.o
	$(CC) -o mscnn-test mscnn-test.o Mscnn.o $(LFLAGS)

mscnn-test.o: mscnn-test.cpp
	$(CC) -o mscnn-test.o -c mscnn-test.cpp $(IFLAGS) $(CXXFLAGS)
	
Mscnn.o: Mscnn.cpp
	$(CC) -o Mscnn.o -c Mscnn.cpp $(IFLAGS) $(CXXFLAGS)

clean: 
	rm -f *.o mscnn-test