set(CLANG_FLAGS -march=native)
set(IMPALA_FLAGS --log-level info)
set(HLS_FLAGS ${SOC} ${SYNTHESIS} ${FPGA_PART})

anydsl_runtime_wrap(TEST_MUX CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/mux.impala test_mux.impala)
add_executable(test_mux ${TEST_MUX})
target_link_libraries(test_mux ${AnyDSL_runtime_LIBRARIES})

anydsl_runtime_wrap(TEST_FSM CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/fsm.impala test_fsm.impala)
add_executable(test_fsm ${TEST_FSM})
target_link_libraries(test_fsm ${AnyDSL_runtime_LIBRARIES})

anydsl_runtime_wrap(TEST_RED CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/red.impala test_red.impala)
add_executable(test_red ${TEST_RED})
target_link_libraries(test_red ${AnyDSL_runtime_LIBRARIES})

anydsl_runtime_wrap(TEST_REGS1D CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/regs1d.impala test_regs1d.impala)
add_executable(test_regs1d ${TEST_REGS1D})
target_link_libraries(test_regs1d ${AnyDSL_runtime_LIBRARIES})

anydsl_runtime_wrap(TEST_REGS2D CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/regs1d.impala ${PROJECT_SOURCE_DIR}/src/core/regs2d.impala test_regs2d.impala)
add_executable(test_regs2d ${TEST_REGS2D})
target_link_libraries(test_regs2d ${AnyDSL_runtime_LIBRARIES})

anydsl_runtime_wrap(TEST_GENERATE CLANG_FLAGS ${CLANG_FLAGS} IMPALA_FLAGS ${IMPALA_FLAGS} HLS_FLAGS ${HLS_FLAGS} FILES ${PROJECT_SOURCE_DIR}/src/core/backend.impala test_generate.impala)
add_executable(test_generate ${TEST_GENERATE})
target_link_libraries(test_generate ${AnyDSL_runtime_LIBRARIES})

add_test(NAME mux1     COMMAND test_mux a)
add_test(NAME mux2     COMMAND test_mux a b c d e)
add_test(NAME fsm      COMMAND test_fsm)
add_test(NAME red1     COMMAND test_red)
add_test(NAME red2     COMMAND test_red a)
add_test(NAME red3     COMMAND test_red a b)
add_test(NAME regs1d   COMMAND test_regs1d)
add_test(NAME regs2d   COMMAND test_regs2d)
add_test(NAME generate COMMAND test_generate)
