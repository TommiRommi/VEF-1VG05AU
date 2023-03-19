PROC_NAME 	:= site_open
C_SOURCE	:= site_open.c

ifeq ($(shell uname),)
	PROC := ..\$(PROC_NAME).exe
else
	PROC := ../$(PROC_NAME)
endif

VERBOSE ?= 0
ifeq ($(VERBOSE),0)
	V := @
endif

FLAGS := -O2 -Wall -Wextra -flto -ffunction-sections -fdata-sections
CC	:= gcc


all: $(PROC)

$(PROC): $(C_SOURCE)
	$(CC) $(FLAGS) $< -o $@

clean:
	$(V)$(RM) $(PROC)
