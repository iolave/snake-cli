APP_NAME=snake-cli
PATH_OUT=build

CC=clang
CFLAGS=-Wall
LDFLAGS=-lcurses
CH_INC=-I src/lib/
CSRC=src/lib/*.c src/main.c


CH_INC_TEST=-I test/include -I src/lib/
CSRC_TEST=\
	src/lib/*.c \
	test/include/unity.c \
	test/main.test.c
CSRC_TEST=test/include/*.c src/lib/*.c test/main.test.c


.DEFAULT_GOAL := usage
.PHONY: build run test

usage:
	@echo "*********"
	@echo "* USAGE *"
	@echo "*********"
	@echo ""

clean:
	@echo "[CLEAN]"
	@echo "Cleaning '${PATH_OUT}' directory..."
	rm -rf build/
	@echo ""

build:
	@echo "[BUILD]"
	@echo "Building ${APP_NAME}..."
	if [ ! -d ${PATH_OUT} ]; then mkdir ${PATH_OUT}; fi
	$(CC) $(CFLAGS) $(CH_INC) $(CSRC) -o $(PATH_OUT)/$(APP_NAME)
	@echo ""

run:
	@echo "[RUN]"
	@echo "Running ${APP_NAME}..."
	${PATH_OUT}/${APP_NAME}
	@echo ""

test:
	@echo "[TEST]"
	$(CC) ${CFLAGS} $(CH_INC_TEST) $(CSRC_TEST) -o ${PATH_OUT}/test && ${PATH_OUT}/test
	@echo ""
