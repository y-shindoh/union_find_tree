# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH / 新堂 安孝

SOURCE	:= $(wildcard *.cpp)
HEADER	:= $(wildcard *.hpp)
EXECUTE	:= sample

CXX		:= clang++
CFLAGS	:= -Wall -D__UNION_FIND_TREE_WITH_SIZE__

check: $(EXECUTE)
	./$(EXECUTE)

$(EXECUTE): $(SOURCE) $(HEADER)
	# create: $@
	$(CXX) $(CFLAGS) $(SOURCE) -o $@

clean:
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check clean
