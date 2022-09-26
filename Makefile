CC_BIN=clang
CC_INCLUDE=""

PATH_INCLUDE=include
PATH_LIB=lib
PATH_OUT=build

APP_NAME=snake-cli

MAIN_FILE=src/main.c
CC_MAIN_FLAGS=\
	-lcurses
CC_TEST_INCLUDE=\
	-I $(PATH_LIB)

TEST_FILE=test/main.test.c
CC_TEST_FLAGS=
CC_TEST_INCLUDE=\
	-I $(PATH_INCLUDE) \
	-I $(PATH_LIB)
CC_TEST_FILES=\
	./include/unity.c \
	test/main.test.c

.DEFAULT_GOAL := usage
.PHONY: build run test

usage:
	@echo "*********"
	@echo "* USAGE *"
	@echo "*********"
	@echo ""

clean:
	@echo "[Clean]"
	@echo "Cleaning '${PATH_OUT}' directory..."
	rm -rf build/
	@echo ""

build:
	@echo "[Build]"
	@echo "Building ${APP_NAME}..."
	if [ ! -d ${PATH_OUT} ]; then mkdir ${PATH_OUT}; fi
	${CC_BIN} ${CC_MAIN_FLAGS} -I ${PATH_INCLUDE} -I ${PATH_LIB} ${MAIN_FILE} -o ${PATH_OUT}/${APP_NAME}
	@echo ""

run:
	@echo "[Run]"
	@echo "Running ${APP_NAME}..."
	${PATH_OUT}/${APP_NAME}
	@echo ""

test:
	$(CC_BIN) ${CC_TEST_FLAGS} ${CC_TEST_INCLUDE} ${CC_TEST_FILES} -o ${PATH_OUT}/test && ${PATH_OUT}/test