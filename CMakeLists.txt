cmake_minimum_required(VERSION 3.0.0)
project(ChargedUpCv VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set( Boost_INCLUDE_DIR /usr/local/boost_1_82_0)
find_package( Boost REQUIRED )

set( Eigen3_DIR /usr/local/eigen-3.4.0/build_dir)
find_package( Eigen3 REQUIRED )

set ( libInterpolate_DIR /home/sasanka/ChargedUpCv/libInterpolate/build )
find_package( libInterpolate REQUIRED )

add_executable(ChargedUpCv main.cpp Utils/Utils.cpp )

target_link_libraries( ChargedUpCv ${OpenCV_LIBS} )
target_link_libraries( ChargedUpCv ${Boost_LIBRARIES} )
target_link_libraries( ChargedUpCv libInterpolate::Interpolate )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
