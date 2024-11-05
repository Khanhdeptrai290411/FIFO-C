# Yêu cầu phiên bản CMake tối thiểu
cmake_minimum_required(VERSION 3.10)
project(fifo_project VERSION 1.0)

# Chỉ định tiêu chuẩn C cần sử dụng
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Tạo các tệp thực thi cho từng tiến trình với đường dẫn chính xác đến các tệp nguồn
add_executable(sender src/sender.c)
add_executable(receiver src/receiver.c)

# Tạo tệp FIFO (nếu chưa tồn tại)
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/myfifo
    COMMAND mkfifo ${CMAKE_BINARY_DIR}/myfifo
    COMMENT "Creating FIFO file (myfifo)"
)

# Đảm bảo tệp FIFO được tạo trước khi chạy sender và receiver
add_custom_target(create_fifo ALL DEPENDS ${CMAKE_BINARY_DIR}/myfifo)
add_dependencies(sender create_fifo)
add_dependencies(receiver create_fifo)
