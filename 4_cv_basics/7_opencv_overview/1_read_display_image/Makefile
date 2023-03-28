output: read_display_image.cpp
	@echo "Building.." 
	@find $(shell pwd) -name "*.cpp" -type f -exec sed -i 's@PROJECT_SOURCE_DIR@../../..@g' {} \;
	@g++ read_display_image.cpp -o read_display_image `pkg-config opencv4 --cflags --libs` -lsqlite3
	@find $(shell pwd) -name "*.cpp" -type f -exec sed -i 's@../../..@PROJECT_SOURCE_DIR@g' {} \;
	@find $(shell pwd) -name "*.cpp" -type f -exec sed -i 's@../../..@PROJECT_SOURCE_DIR@g' {} \;

clean:
	rm output