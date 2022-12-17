cmake_minimum_required(VERSION 3.14)

project (PyTorch-openCV-Cpp)

find_package (Torch REQUIRED)

add_executable(PyTorch-openCV-Cpp main.cpp )

target_link_libraries(PyTorch-openCV-Cpp "${TORCH_LIBRARIES}")

if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET PyTorch-openCV-Cpp
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:PyTorch-openCV-Cpp>)
endif (MSVC)

