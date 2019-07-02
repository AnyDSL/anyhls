set(CLANG_FLAGS -march=native)
set(IMPALA_FLAGS --log-level info)
set(ANYDSL_RUNTIME_LIBRARIES ${AnyDSL_runtime_LIBRARIES})
set(HLS_FLAGS ${SOC} ${SYNTHESIS} ${FPGA_PART})


anydsl_runtime_wrap(TEST_HOST2HOST CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES test_host2host.impala)
add_executable(test_host2host ${TEST_HOST2HOST})
target_link_libraries(test_host2host ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_MAKE_IMG_MEM1D CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES test_make_img_mem1d.impala)
add_executable(test_make_img_mem1d ${TEST_MAKE_IMG_MEM1D})
target_link_libraries(test_make_img_mem1d ${ANYDSL_RUNTIME_LIBRARIES})

add_test(NAME host2host          COMMAND test_host2host)
add_test(NAME make_img_mem1d     COMMAND test_make_img_mem1d)
