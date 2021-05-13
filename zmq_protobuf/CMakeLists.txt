cmake_minimum_required(VERSION 3.8.0)

# 设置项目名称 版本
set(PROJECT_NAME zmq_demo1)
project(${PROJECT_NAME} VERSION 1.0.0)

# 获取编译时间
string(TIMESTAMP vDataTime "%Y%m%d")
add_definitions(
    -DDATETIME="${vDataTime}"
    -DAPP_VERSION="zmq_demo_laster_${PROJECT_VERSION}_${vDataTime}"
    -DAPP_NAME="PROJECT_NAME"
)

# 编译protobuf
find_package(Protobuf REQUIRED)

file(GLOB ALL_PROTOS proto/*.proto)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${ALL_PROTOS})

add_compile_options(-std=c++14 -pthread -Wl,
    # -Werror
    -Wswitch
    -Wuninitialized
    -Wno-return-local-addr
    -Wreturn-type
)


###########
## Build ##
###########

# 头文件路径
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    
    /usr/local/include/
)

# 库路径
link_directories(

)

# 编译生成可执行文件
add_executable(psenvpub
    ${CMAKE_CURRENT_SOURCE_DIR}/src/psenvpub.cpp
    ${PROTO_SRCS}
    # /usr/local/include/zmq.hpp
)

# 链接库
target_link_libraries(psenvpub
    uuid
    zmq
    protobuf
)

# 编译生成可执行文件
add_executable(psenvsub
    ${CMAKE_CURRENT_SOURCE_DIR}/src/psenvsub.cpp
    ${PROTO_SRCS}
    # /usr/local/include/zmq.hpp
)

# 链接库
target_link_libraries(psenvsub
    uuid
    zmq
    protobuf
)
