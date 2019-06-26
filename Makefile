init: init-vendor clone-cmake update-cmake build-cmake clone-glfw update-glfw build-glfw clone-glew update-glew build-glew clone-soil update-soil build-soil

init-vendor:
	rm -rf vendor/; mkdir vendor

clone-cmake:
	git clone https://gitlab.kitware.com/cmake/cmake.git vendor/cmake/
update-cmake:
	cd vendor/cmake/; git pull; cd ../../
build-cmake:
	cd vendor/cmake/; ./bootstrap && make && sudo make install; cd ../../

clone-glfw:
	git clone https://github.com/glfw/glfw.git vendor/glfw/
update-glfw:
	cd vendor/glfw/; git pull; cd ../../
build-glfw:
	cd vendor/glfw/; \
	./../cmake/bin/cmake -DBUILD_SHARED_LIBS=ON .; \
	make && sudo make install; \
	cd ../../

clone-glew:
	git clone https://github.com/nigels-com/glew.git vendor/glew
update-glew:
	cd vendor/glew/; git pull; cd ../../
build-glew:
	cd vendor/glew/auto; make && sudo make install; cd ../; make && sudo make install; cd ../../

clone-soil:
	git clone https://github.com/kbranigan/Simple-OpenGL-Image-Library.git vendor/soil
update-soil:
	cd vendor/soil/; git pull; cd ../../
build-soil:
	cd vendor/soil/; make && sudo make install; cd ../../

clone-glm:
	git clone https://github.com/g-truc/glm.git vendor/glm
update-glm:
	cd vendor/glm/; git pull; cd ../../
build-glm:
	cd vendor/glm/; cmake .; make && sudo make install; cd ../../

build-app:
	rm -rf build; mkdir build; g++ -lglfw -lGLEW -lGL -lSOIL -lX11 app/main.cpp -o build/razor-phantom
