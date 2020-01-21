set(CLANG_FLAGS -march=native)
set(IMPALA_FLAGS --log-level info)
set(ANYDSL_RUNTIME_LIBRARIES ${AnyDSL_runtime_LIBRARIES})
set(HLS_FLAGS ${SOC} ${SYNTHESIS} ${FPGA_PART})

set(ANYHLS_CORE_FILES
    ${PROJECT_SOURCE_DIR}/src/core/regs1d.impala
    ${PROJECT_SOURCE_DIR}/src/core/regs2d.impala)

set(ANYHLS_FILES ${ANYHLS_CORE_FILES}
    ${PROJECT_SOURCE_DIR}/src/utils.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/img.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/mem.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/fifo.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/mask.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/loops.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/alg.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/dataflow.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/borderhandling.impala
    ${PROJECT_SOURCE_DIR}/src/imglib/operators.impala)

anydsl_runtime_wrap(GAUSSIAN CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${ANYHLS_FILES} gaussian.impala)
add_executable(gaussian ${GAUSSIAN})
target_link_libraries(gaussian ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME gaussian COMMAND test_gaussian)

anydsl_runtime_wrap(BOX_FILTER CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${ANYHLS_FILES} box_filter.impala)
add_executable(box_filter ${BOX_FILTER})
target_link_libraries(box_filter ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME box_filter COMMAND test_box_filter)

anydsl_runtime_wrap(JACOBI CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${ANYHLS_FILES} jacobi.impala)
add_executable(jacobi ${JACOBI})
target_link_libraries(jacobi ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME jacobi COMMAND test_jacobi)
