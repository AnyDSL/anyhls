project(AnyHLS)
cmake_minimum_required(VERSION 3.4.3)

find_package(AnyDSL_runtime REQUIRED)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

include_directories(${AnyDSL_runtime_INCLUDE_DIRS})

set(BACKEND fpga)
if(NOT BACKEND)
    set(BACKEND aocl CACHE STRING "select the backend from the following: CPU, AVX, NVVM, CUDA, OPENCL, AMDGPU, fpga" FORCE)
endif()
string(TOLOWER "${BACKEND}" BACKEND)
message(STATUS "Selected backend: ${BACKEND}")

if(BACKEND STREQUAL "fpga")
    set(SYNTHESIS CACHE BOOLEAN "ON: Synthesis and HDL generation, OFF: C simulation")
    if(NOT SYNTHESIS)
        set(SYNTHESIS OFF CACHE BOOLEAN "ON: Synthesis and HDL generation, OFF: C simulation" FORCE)
    endif()
    string(TOLOWER "${SYNTHESIS}" SYNTHESIS)
    message(STATUS "HW Synthesis: ${SYNTHESIS}")

    set(FPGA_PART CACHE STRING "Specify FPGA part")
    if(NOT FPGA_PART)
        set(FPGA_PART xc7z020clg484-1 CACHE STRING "Specify FPGA part" FORCE)
    endif()
    string(TOLOWER "${FPGA_PART}" FPGA_PART)
    message(STATUS "Selected FPGA: ${FPGA_PART}")

    set(SOC CACHE BOOLEAN "ON: SoC integration, OFF: HDL IP generation")
    if(NOT SOC)
        set(SOC OFF CACHE BOOLEAN "ON: SoC integration, OFF: HDL IP generation" FORCE)
    endif()
    string(TOLOWER "${SOC}" SOC)
    message(STATUS "SoC integration: ${SOC}")
else()
    unset(SYNTHESIS CACHE)
    unset(FPGA_PART CACHE)
    unset(SOC CACHE)
endif()

set(ANYDSL_RUNTIME_LIBRARIES ${AnyDSL_runtime_LIBRARIES})
set(HLS_FLAGS ${SOC} ${SYNTHESIS} ${FPGA_PART})

#add_subdirectory(src)
add_subdirectory(test)
