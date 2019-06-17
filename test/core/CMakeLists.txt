set(CLANG_FLAGS -march=native)
set(IMPALA_FLAGS --log-level info)

anydsl_runtime_wrap(TEST_MUX CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/mux.impala test_mux.impala)
add_executable(test_mux ${TEST_MUX})
target_link_libraries(test_mux ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_FSM CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/fsm.impala test_fsm.impala)
add_executable(test_fsm ${TEST_FSM})
target_link_libraries(test_fsm ${ANYDSL_RUNTIME_LIBRARIES})

anydsl_runtime_wrap(TEST_RED CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/red.impala test_red.impala)
add_executable(test_red ${TEST_RED})
target_link_libraries(test_red ${ANYDSL_RUNTIME_LIBRARIES})

add_test(NAME mux1 COMMAND test_mux a)
add_test(NAME mux2 COMMAND test_mux a b c d e)
add_test(NAME fsm  COMMAND test_fsm)
add_test(NAME red1 COMMAND test_red)
add_test(NAME red2 COMMAND test_red a)
add_test(NAME red3 COMMAND test_red a b)
