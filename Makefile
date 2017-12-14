all: lottery edf

lottery: lottery.c
	cc -o lottery lottery.c
edf: edf.c
	cc -o edf edf.c
clean:
	rm lottery edf
