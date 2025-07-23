TARGET=build/main

all: build run
setup:
	@mkdir -p include
build:
	@mkdir -p build
	@cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make -j
run: $(TARGET)
	@./$(TARGET)
clean:
	rm -rf build
rebuild: clean all