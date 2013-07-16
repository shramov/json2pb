CPPFLAGS = -g -fPIC -I.
LDFLAGS = -Wl,-rpath -Wl,.
UNAME := $(shell uname)

ifeq ($(strip $(UNAME)),Darwin)
  SOFLAG := -install_name
  LDFLAGS += -I/usr/local/include -I/usr/local/lib
else
  SOFLAG := -soname
endif

all: libjson2pb.so test_json

clean:
	-rm -f *.o *.so *.a libjson2pb.so.* test test.pb.cc test.pb.h test_json

test_json:  test_json.o test.pb.o libjson2pb.so
	$(CC) $(LDFLAGS) $^ -o $@ -lprotobuf -lstdc++ -ljansson

test_json.o: test.pb.h

json2pb.o: bin2ascii.h

libjson2pb.so: json2pb.o
	$(CC) $(LDFLAGS) -o $@ $^ -Wl,$(SOFLAG)=$@ -shared -L. -lcurl -lprotobuf -lstdc++ -ljansson

test.pb.h test.pb.cc: test.proto
	protoc --cpp_out=$(shell pwd) test.proto
