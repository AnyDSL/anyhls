anydsl_runtime_wrap(TEST_HOST2HOST CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES test_host2host.impala)
add_executable(test_host2host ${TEST_HOST2HOST})
target_link_libraries(test_host2host ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_IMG_MEM1D CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES test_img_mem1d.impala)
add_executable(test_img_mem1d ${TEST_IMG_MEM1D})
target_link_libraries(test_img_mem1d ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_POINT CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} test_point.impala)
add_executable(test_point ${TEST_POINT})
target_link_libraries(test_point ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_LBUF CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} test_lbuf.impala)
add_executable(test_lbuf ${TEST_LBUF})
target_link_libraries(test_lbuf ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_SWIN CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} test_swin.impala)
add_executable(test_swin ${TEST_SWIN})
target_link_libraries(test_swin ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_LOCAL CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} test_local.impala)
add_executable(test_local ${TEST_LOCAL})
target_link_libraries(test_local ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_LOCAL_BH CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} test_local_bh.impala)
add_executable(test_local_bh ${TEST_LOCAL_BH})
target_link_libraries(test_local_bh ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_LOCAL_FSM CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${IMGLIB_ANY_FILES} test_local_fsm.impala)
add_executable(test_local_fsm ${TEST_LOCAL_FSM})
target_link_libraries(test_local_fsm ${ANYDSL_RUNTIME_LIBRARIES})

add_test(NAME host2host COMMAND test_host2host)
add_test(NAME img_mem1d COMMAND test_img_mem1d)
add_test(NAME point     COMMAND test_point)
add_test(NAME lbuf      COMMAND test_lbuf)
add_test(NAME swin      COMMAND test_swin)
add_test(NAME local     COMMAND test_local)
add_test(NAME local_fsm COMMAND test_local_fsm)
