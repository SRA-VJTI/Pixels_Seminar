# Makefile for installation of opencv and other dependencies

#check if OpenCV is installed(check for not found error) print true if not found, false if found
OPENCV_INSTALLED := $(shell pkg-config --exists opencv4 sdl2 && echo true || echo false | awk '{print $1}')

# Install OpenCV libraries if needed, Debian, Mac, and Arch Linux
# if pkg-config returns an error, then OpenCV is not installed
install:
	@echo "Checking if OpenCV is installed..."
ifeq ($(OPENCV_INSTALLED), true)
	@echo "OpenCV is installed"
else
	@echo "OpenCV is not installed"
	@echo "Installing OpenCV..."
ifeq ($(shell cat /etc/os-release | awk '{if (match ($$0, /debian/)) {print "true"; exit;}}'),true)
	@echo "Debian"
	@sudo apt-get update -y
	@sudo apt-get install libopencv-dev libsdl2-2.0-0 libsdl2-image-dev libsdl2-dev -y
else ifeq ($(shell uname -a | awk '{if (match ($$0, /Darwin/)) print "true"}'),true)
	@echo "Mac"
	@brew install opencv sdl2
else ifeq ($(shell cat /etc/os-release | awk '{if (match ($$0, /arch/)) {print "true"; exit;}}'),true)
	@echo "Arch Linux"
	@sudo pacman -Sy opencv hdf5 glew vtk fmt sdl2
else
	@echo "Unknown OS"
endif
endif
