set(CLANG_FLAGS -march=native)
set(IMPALA_FLAGS --log-level info)
set(ANYDSL_RUNTIME_LIBRARIES ${AnyDSL_runtime_LIBRARIES})
set(HLS_FLAGS ${SOC} ${SYNTHESIS} ${FPGA_PART})

set(IMGLIB_FILES
    ${PROJECT_SOURCE_DIR}/imglib/src/utils.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/img.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/mem.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/fifo.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/mask.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/loops.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/alg.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/dataflow.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/borderhandling.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/operator_reduce.impala
    ${PROJECT_SOURCE_DIR}/imglib/src/operators.impala)

set(IMGLIB_ANY_FILES ${IMGLIB_FILES} ${ANYHLS_CORE_ANY_FILE})
set(IMGLIB_I32_FILES ${IMGLIB_FILES} ${ANYHLS_CORE_I32_FILE})
set(IMGLIB_F32_FILES ${IMGLIB_FILES} ${ANYHLS_CORE_F32_FILE})
set(IMGLIB_U8_FILES  ${IMGLIB_FILES} ${ANYHLS_CORE_U8_FILE})

add_subdirectory(apps)
add_subdirectory(test)
