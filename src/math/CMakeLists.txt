target_sources(quadsim PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CrossProdMatrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/QuaternionToDcm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/QuaternionToRotMat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WrapPiDiv2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WrapTwoPi.cpp
)
