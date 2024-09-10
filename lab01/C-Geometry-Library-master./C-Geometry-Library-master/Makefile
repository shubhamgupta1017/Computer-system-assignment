CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -fPIC
LDFLAGS = -lm

all: bin/app bin/test bin/test_app

app: bin/app

test:  bin/test

test_app: bin/test_app

lib: lib/libgeo.so

run_app: bin/app
	./bin/app

run_test: bin/test
	./bin/test

run_test_app: bin/test_app
	./bin/test_app


bin/app: app/app.c lib/libgeo.so
	$(CC) $(CFLAGS) -o bin/app app/app.c -Llib -lgeo -Wl,-rpath=lib  $(LDFLAGS)

bin/test: test/test.c lib/libgeo.so
	$(CC) $(CFLAGS) -o bin/test test/test.c -Llib -lgeo -Wl,-rpath=lib $(LDFLAGS)

bin/test_app: test/test_app.c lib/libgeo.so
	$(CC) $(CFLAGS) -o bin/test_app test/test_app.c -Llib -lgeo -Wl,-rpath=lib $(LDFLAGS)

lib/libgeo.so: src/geometry.c
	$(CC) $(CFLAGS) -shared -o lib/libgeo.so src/geometry.c  $(LDFLAGS)


clean:
	rm -f lib/libgeo.so
	rm -f bin/app
	rm -f bin/test
	rm -f bin/test_app


.PHONY: all clean test test_app app run_app run_test run_test_app
