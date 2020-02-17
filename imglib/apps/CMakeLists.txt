anydsl_runtime_wrap(SQUARE CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} square.impala)
add_executable(square ${SQUARE})
target_link_libraries(square ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME square COMMAND test_square)

anydsl_runtime_wrap(GAUSSIAN CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} gaussian.impala)
add_executable(gaussian ${GAUSSIAN})
target_link_libraries(gaussian ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME gaussian COMMAND test_gaussian)

anydsl_runtime_wrap(BOX_FILTER CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} box_filter.impala)
add_executable(box_filter ${BOX_FILTER})
target_link_libraries(box_filter ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME box_filter COMMAND test_box_filter)

anydsl_runtime_wrap(JACOBI CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} jacobi.impala)
add_executable(jacobi ${JACOBI})
target_link_libraries(jacobi ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME jacobi COMMAND test_jacobi)

anydsl_runtime_wrap(BILATERAL CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} bilateral.impala)
add_executable(bilateral ${BILATERAL})
target_link_libraries(bilateral ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME bilateral COMMAND test_bilateral)

anydsl_runtime_wrap(SOBEL_LUMA CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_I32_FILES} sobel_luma.impala)
add_executable(sobel_luma ${SOBEL_LUMA})
target_link_libraries(sobel_luma ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME sobel_luma COMMAND test_sobel_luma)

anydsl_runtime_wrap(FILTER_CHAIN CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_I32_FILES} filter_chain.impala)
add_executable(filter_chain ${FILTER_CHAIN})
target_link_libraries(filter_chain ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME filter_chain COMMAND test_filter_chain)

anydsl_runtime_wrap(HARRIS_CORNER CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_I32_FILES} harris_corner.impala)
add_executable(harris_corner ${HARRIS_CORNER})
target_link_libraries(harris_corner ${ANYDSL_RUNTIME_LIBRARIES})
add_test(NAME harris_corner COMMAND test_harris_corner)
