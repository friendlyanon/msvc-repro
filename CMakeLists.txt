cmake_minimum_required(VERSION 3.8)

project(msvc-repro CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

foreach(name IN ITEMS fold member_ptr)
  set(tgt "${name}_repro")
  add_executable("${tgt}" "${name}.cpp")
  target_compile_options("${tgt}" PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/permissive->")
  add_test("${name}" "${tgt}")
endforeach()
