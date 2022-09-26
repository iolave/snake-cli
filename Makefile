CC=clang

APP_NAME=snake-cli
APP_MAIN=src/main.c
PATH_INCLUDE=include/
PATH_LIB=lib/
PATH_OUT=build/

.DEFAULT_GOAL := usage
.PHONY: build run

usage:
	@echo "*********"
	@echo "* USAGE *"
	@echo "*********"
	@echo ""

clean:
	@echo "[Cleaning process]"
	@echo "Cleaning '${PATH_OUT}' directory..."
	rm -rf build/
	@echo ""

build:
	@echo "[Building process]"
	@echo "Building ${APP_NAME}..."

	if [ ! -d ${PATH_OUT} ]; then mkdir ${PATH_OUT}; fi

	${CC} -I ${PATH_INCLUDE} -I ${PATH_LIB} ${APP_MAIN} -o ${PATH_OUT}/${APP_NAME}
run:
	${PATH_OUT}/${APP_NAME}