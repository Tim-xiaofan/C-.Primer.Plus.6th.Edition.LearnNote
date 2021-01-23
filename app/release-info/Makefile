# SPDX-License-Identifier: BSD-3-Clause
# Copyright(c) 2010-2014 Intel Corporation

# binary name
APP = release_info

# all source are stored in SRCS-y
SRCS-y := release_info.cpp main.cpp

# Add flag 
CPPFLAGS += -g -Wall

$(APP): $(SRCS-y) Makefile 
	$(CXX) $(CPPFLAGS) $(SRCS-y) -o $@ 

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(APP)
