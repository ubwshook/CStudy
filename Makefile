all:
	gcc base/base.c base/error.c cmd/cmd.c main.c -o test
clean:
	rm -rf test