#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

std::string read_shader_source(const std::string &file_path) {
  std::ifstream shader_file(file_path);
  if(!shader_file.is_open()) {
    throw std::runtime_error("Could not open shader file: " + file_path);
  }
  std::stringstream shader_stream;
  shader_stream << shader_file.rdbuf();
  return shader_stream.str();
}

GLuint compile_shader(GLenum type, std::string source) {
  GLuint shader = glCreateShader(type);
  const char* source_cstr = source.c_str();
  glShaderSource(shader, 1, &source_cstr, nullptr);
  glCompileShader(shader);

  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if(!success) {
    char log[512];
    glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
    std::runtime_error("Shader compilation error: " + std::string(log));
    exit(-1);
  }
  return shader;
}

GLuint create_shader_program(std::string vertex_shader_path, std::string fragment_shader_path) {
  std::string vertex_shader_source = read_shader_source(vertex_shader_path);
  std::string fragment_shader_source = read_shader_source(fragment_shader_path);

  GLuint vertex_shader = compile_shader(GL_VERTEX_SHADER, vertex_shader_source);
  GLuint fragment_shader = compile_shader(GL_FRAGMENT_SHADER, fragment_shader_source);

  GLuint shader_program = glCreateProgram();
  glAttachShader(shader_program, vertex_shader);
  glAttachShader(shader_program, fragment_shader);
  glLinkProgram(shader_program);

  GLint success;
  glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
  if(!success) {
    char log[512];
    glGetProgramInfoLog(shader_program, sizeof(log), nullptr, log);
    std::cerr << "Shader program linking error: " << log << std::endl;
    throw std::runtime_error("Shader program linking error");
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  return shader_program;
}

#endif