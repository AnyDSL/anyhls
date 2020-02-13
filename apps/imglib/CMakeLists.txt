set(CLANG_FLAGS -march=native)
set(IMPALA_FLAGS --log-level info)
set(ANYDSL_RUNTIME_LIBRARIES ${AnyDSL_runtime_LIBRARIES})
set(HLS_FLAGS ${SOC} ${SYNTHESIS} ${FPGA_PART})

set(IMGLIB ${ANYHLS_CORE_FILES}
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

set(IMGLIB_ANY ${IMGLIB} ${DATA_TYPE_ANY_FILE})
set(IMGLIB_I32 ${IMGLIB} ${DATA_TYPE_I32_FILE})
set(IMGLIB_F32 ${IMGLIB} ${DATA_TYPE_F32_FILE})
set(IMGLIB_U8  ${IMGLIB} ${DATA_TYPE_U8_FILE})

anydsl_runtime_wrap(SQUARE CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY} square.impala)
add_executable(square ${SQUARE})
target_link_libraries(square ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME square COMMAND test_square)

anydsl_runtime_wrap(GAUSSIAN CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY} gaussian.impala)
add_executable(gaussian ${GAUSSIAN})
target_link_libraries(gaussian ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME gaussian COMMAND test_gaussian)

anydsl_runtime_wrap(BOX_FILTER CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY} box_filter.impala)
add_executable(box_filter ${BOX_FILTER})
target_link_libraries(box_filter ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME box_filter COMMAND test_box_filter)

anydsl_runtime_wrap(JACOBI CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY} jacobi.impala)
add_executable(jacobi ${JACOBI})
target_link_libraries(jacobi ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME jacobi COMMAND test_jacobi)

anydsl_runtime_wrap(BILATERAL CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY} bilateral.impala)
add_executable(bilateral ${BILATERAL})
target_link_libraries(bilateral ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME bilateral COMMAND test_bilateral)

anydsl_runtime_wrap(SOBEL_LUMA CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_I32} sobel_luma.impala)
add_executable(sobel_luma ${SOBEL_LUMA})
target_link_libraries(sobel_luma ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME sobel_luma COMMAND test_sobel_luma)
