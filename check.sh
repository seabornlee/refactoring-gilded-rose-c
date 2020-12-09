#!/bin/sh

cd cmake-build-debug && cmake .. && make && ./test/refactor-gilded-rose-c_test && cd ..
