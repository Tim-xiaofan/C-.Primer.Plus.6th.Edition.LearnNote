# SPDX-License-Identifier: BSD-3-Clause
# Copyright(c) 2010-2014 Intel Corporation

# binary name
APP = release_info

# all source are stored in SRCS-y
SRCS-y := release_info.cpp main.cpp

ifeq ($(OS),Windows_NT)
		PLATFORM="Windows"
endif

ifeq ($(shell uname),Darwin)
		PLATFORM="MacOS"
endif
ifeq ($(shell uname),Linux)
		PLATFORM="Unix-Like"
endif

# Add flag 
CPPFLAGS += -g -Wall

$(APP): $(SRCS-y) Makefile 
	$(CXX) $(CPPFLAGS) $(SRCS-y) -o $@


ifeq ($(shell uname),Linux)
.PHONY: clean
clean:
	rm -f *.o
	rm -f *.exe
	rm -f $(APP)
endif

ifeq ($(OS),Windows_NT)
.PHONY: clean
clean:
	rm -Force *.o
	rm -Force *.exe
	rm -Force $(APP)
endif
