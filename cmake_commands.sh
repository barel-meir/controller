/home/barel/.local/bin/cmake /home/barel/repos/controller_ws/src/controller -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja -DCMAKE_INSTALL_PREFIX=/home/barel/repos/controller_ws/install/controller
/home/barel/.local/bin/cmake --build /home/barel/repos/controller_ws/build/controller -- -j8 -l8
/home/barel/.local/bin/cmake --install /home/barel/repos/controller_ws/build/controller
