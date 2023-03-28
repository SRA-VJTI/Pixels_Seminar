output: masking.cpp
	@echo "Building.." 
	@find $(shell pwd) -name "*.cpp" -type f -exec sed -i 's@PROJECT_SOURCE_DIR@../../..@g' {} \;
	@g++ masking.cpp -o masking `pkg-config opencv4 --cflags --libs` -lsqlite3
	@find $(shell pwd) -name "*.cpp" -type f -exec sed -i 's@../../..@PROJECT_SOURCE_DIR@g' {} \;
clean:
	rm output