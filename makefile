cs:
	@echo `pwd`
	@rsync -r -t -u -v --delete \
	--include "makefile"        \
	--include "*.c++"           \
	--include "*.h"             \
	--include "*.html"          \
	--include "*.java"          \
	--include "*.out"           \
	--exclude "*"               \
	. downing@$(CS):cs/projects/graph/

OS       := $(shell uname)
VALGRIND := $(shell which valgrind)

ifeq ($(OS), Darwin)
	BOOST :=
else
	BOOST := -I/public/linux/include/boost-1_38
endif

.PRECIOUS: %.c++.app
.PRECIOUS: %.class

TestGraph.c++.app: TestGraph.c++ Graph.h
	g++ -ansi -pedantic $(BOOST) -lcppunit -ldl -Wall $< -o TestGraph.c++.app

TestGraph.class: TestGraph.java Graph.java
	javac -Xlint TestGraph.java

TestGraph.c++x: TestGraph.c++.app
	$(VALGRIND) TestGraph.c++.app

TestGraph.javax: TestGraph.class
	java -ea TestGraph

TestGraph.pyx:
	TestGraph.py

clean:
	rm -f *.app
	rm -f *.class
	rm -f *.pyc

list:
	ls -al *.app
	ls -al *.class

test:
	make TestGraph.c++x
	make TestGraph.javax
	make TestGraph.pyx
