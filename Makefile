TARGET=build/main
all: build run
build:
	mkdir -p build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make -j$(shell nproc)
run: $(TARGET)
	@./$(TARGET)
clean:
	rm -rf build
rebuild: clean all