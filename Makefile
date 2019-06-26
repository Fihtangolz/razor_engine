init: init-third-aprty clone-cmake update-cmake build-cmake clone-glfw update-glfw build-glfw clone-glew update-glew build-glew clone-soil update-soil build-soil

init-third-aprty:
	rm -rf third_aprty/; mkdir third_aprty

clone-cmake:
	git clone https://gitlab.kitware.com/cmake/cmake.git third_aprty/cmake
update-cmake:
	cd third_aprty/cmake/; git pull; cd ../../
build-cmake:
	cd third_aprty/cmake/; ./bootstrap && make && sudo make install; cd ../../

clone-glfw:
	git clone https://github.com/glfw/glfw.git third_aprty/glfw/
update-glfw:
	cd third_aprty/glfw/; git pull; cd ../../
build-glfw:
	cd third_aprty/glfw/; \
	cmake -DBUILD_SHARED_LIBS=ON .; \
	make && sudo make install; \
	cd ../../

clone-glew:
	git clone https://github.com/nigels-com/glew.git third_aprty/glew
update-glew:
	cd third_aprty/glew/; git pull; cd ../../
build-glew:
	cd third_aprty/glew/auto; make && sudo make install; cd ../; make && sudo make install; cd ../../

clone-soil:
	git clone https://github.com/kbranigan/Simple-OpenGL-Image-Library.git third_aprty/soil
update-soil:
	cd third_aprty/soil/; git pull; cd ../../
build-soil:
	cd third_aprty/soil/; make && sudo make install; cd ../../

clone-glm:
	git clone https://github.com/g-truc/glm.git third_aprty/glm
update-glm:
	cd third_aprty/glm/; git pull; cd ../../
build-glm:
	cd third_aprty/glm/; cmake .; make && sudo make install; cd ../../

build-app:
	rm -rf build; mkdir build; g++ -Wall -lglfw -lGLEW -lGL -lSOIL -lX11 src/main.cpp -o build/razor-phantom
