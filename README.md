# GLFW Starter

This is a simple GLFW starter project that sets up a window and prepares for rendering with OpenGL.

## Pre-requisites

This project requires the following libraries:

- [GLFW](https://www.glfw.org/)
- [GLAD](https://glad.dav1d.de/)
- [CMake](https://cmake.org/)
- [Make](https://www.gnu.org/software/make/)

## Libraries Installation

To install GLAD, you can use the [link](<[GLAD](https://glad.dav1d.de/#profile=compatibility&language=c&specification=gl&loader=on&api=gl%3D4.6)>) to generate the necessary files. Make sure to place the generated files in the `include/glad` directory.

Installing GLFW can be done through your package manager or by downloading it from the [GLFW website](https://www.glfw.org/download.html).

## Project Structure

```

.
├── CMakeLists.txt
├── Makefile
├── README.md
├── include
│   ├── KHR
│   │   └── khrplatform.h
│   └── glad
│   ├── glad.c
│   └── glad.h
└── src
├── handler
│   ├── initializer.hpp
│   └── shader.hpp
├── main.cpp
└── shader
├── fragment_shader.glsl
└── vertex_shader.glsl
```

## Building and Running the Project

Since we provide a `Makefile`, you can build the project using the following command:

```bash
make build
```

This will create a `build` directory and compile the project. You can then run the executable with:

```bash
make run
```

If you want to clean the build files, you can use:

```bash
make clean
```

If you want to rebuild the project, you can use:

```bash
make rebuild
```
