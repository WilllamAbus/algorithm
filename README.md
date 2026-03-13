Algorithm Practice – C++ + WSL

Repository này dùng để luyện thuật toán từ các bài trên LeetCode bằng C++ trong môi trường WSL + VS Code.

Mục tiêu:

Compile và run nhanh

Cấu trúc code rõ ràng theo tuần / topic

Có thể debug bằng gdb

1. Môi trường sử dụng

Editor:

Visual Studio Code

Runtime:

WSL (Ubuntu)

Compiler:

g++

Debugger:

gdb

2. Cấu trúc project
algorithm
│
├── .vscode
│   ├── launch.json
│   ├── tasks.json
│
├── build
│
├── Week1
│   ├── merge_array.cpp
│   ├── two_sum.cpp
│
├── Week2
│   ├── sliding_window.cpp
│
└── template.cpp

Giải thích:

.vscode/
cấu hình build và debug cho VS Code

build/
chứa executable sau khi compile

WeekX/
chứa các bài thuật toán theo tuần hoặc topic

3. Cách chạy một bài toán
Bước 1 – mở file

Ví dụ:

Week1/merge_array.cpp
Bước 2 – bấm F5

VS Code sẽ chạy pipeline:

g++ source.cpp
↓
build/executable
↓
run program

Ví dụ:

g++ Week1/merge_array.cpp -o build/merge_array
./build/merge_array
4. Compile bằng terminal (nếu không dùng VS Code)

Trong WSL:

g++ -std=c++17 -O2 Week1/merge_array.cpp -o build/merge_array
./build/merge_array