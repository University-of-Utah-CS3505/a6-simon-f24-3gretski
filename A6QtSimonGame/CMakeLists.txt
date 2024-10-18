cmake_minimum_required (VERSION 3.21.1)

project(A6QtSimonGame VERSION 0.0.1 LANGUAGES C CXX ASM)

find_package(Qul)

qul_add_target(A6QtSimonGame QML_PROJECT A6QtSimonGame.qmlproject GENERATE_ENTRYPOINT)
app_target_setup_os(A6QtSimonGame)
